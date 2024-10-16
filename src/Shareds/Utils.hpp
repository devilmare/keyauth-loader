#include <include.hpp>

void printMessage(const std::string& type, const std::string& message)
{
    const int COLOR_DEFAULT = 7;  // White
    const int COLOR_SUCCESS = 10; // Green
    const int COLOR_ERROR = 12;   // Red
    const int COLOR_INFO = 11;    // Cyan
    const int COLOR_RED = 13;    // Cyan

    int colorCode = COLOR_DEFAULT;
    if (type == xorstr_("Success"))
    {
        colorCode = COLOR_SUCCESS;
    }
    else if (type == xorstr_("Error"))
    {
        colorCode = COLOR_ERROR;
    }
    else if (type == xorstr_("Info"))
    {
        colorCode = COLOR_INFO;
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, COLOR_RED);

    std::cout << xorstr_("[*] ");

    SetConsoleTextAttribute(hConsole, colorCode);

    std::cout << message;

    SetConsoleTextAttribute(hConsole, COLOR_DEFAULT);
}

void __stdcall LogInFile(const std::string& log_name, const char* log, ...)
{
    char current_dir[600];
    memset(current_dir, 0, sizeof(current_dir));
    _getcwd(current_dir, sizeof(current_dir));

    char brutalize_dir[600];
    memset(brutalize_dir, 0, sizeof(brutalize_dir));
    sprintf(brutalize_dir, xorstr_("%s"), current_dir);

    _mkdir(brutalize_dir);

    char log_file_path[600];
    memset(log_file_path, 0, sizeof(log_file_path));
    sprintf(log_file_path, xorstr_("%s\\%s"), brutalize_dir, log_name.c_str());

    static bool once = false;
    if (!once)
    {
        FILE* hFile = fopen(log_file_path, xorstr_("rb"));
        if (hFile) {
            fclose(hFile);
            DeleteFileA(log_file_path);
        }
        once = true;
    }

    FILE* hFile = fopen(log_file_path, xorstr_("a+"));
    if (hFile)
    {
        time_t t = std::time(0);
        tm* now = std::localtime(&t);
        char timestamp[600];
        memset(timestamp, 0, sizeof(timestamp));
        sprintf(timestamp, xorstr_("[%d:%d:%d]"), now->tm_hour, now->tm_min, now->tm_sec);
        strcat(timestamp, " ");
        strcat(timestamp, log);

        va_list arglist;
        va_start(arglist, log);
        vfprintf(hFile, timestamp, arglist);
        va_end(arglist);

        fclose(hFile);
    }
}

std::string tm_to_readable_time(tm ctx)
{
    char buffer[80];

    strftime(buffer, sizeof(buffer), xorstr_("%d/%m/%y %H:%M:%S"), &ctx);

    return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp)
{
    auto cv = strtol(timestamp.c_str(), NULL, 10);

    return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp)
{
    std::tm context;

    localtime_s(&context, &timestamp);

    return context;
}