#include "FindWindow.hpp"

bool Window::CheckWindow()
{
    const char* windowNames[] = {
        xorstr_("Olly Debugger"), xorstr_("OllyDbg"), xorstr_("HxD"), xorstr_("x64dbg"), xorstr_("x32dbg"), xorstr_("IDA Pro"),
        xorstr_("Immunity Debugger"),  xorstr_("WinDbg"),  xorstr_("Ghidra")
    };

    bool foundWindow = false;
    std::string window;

    for (const char* name : windowNames)
    {
        HWND hwnd = FindWindow(NULL, name);
        if (hwnd != NULL)
        {
            foundWindow = true;
            window += name;
            window += "\n";
        }
    }

    if (foundWindow)
    {
        Discord discord(Config::webhook_url);

        std::string title = xorstr_("Debugger Detection");
        std::string description = ("An analysis tool window has been detected open on the user's device");
        std::string color = xorstr_("16711680");

        std::vector<std::pair<std::string, std::string>> fields;
        std::istringstream iss(window);
        std::string line;

        while (std::getline(iss, line))
        {
            fields.push_back({ xorstr_("Tools:"), line });
        }

        fields.push_back({ xorstr_("User Information:"), Shared::GetUserInformation() });

        discord.SendDiscord(title, description, color, fields);

        ExitProcess(0);
    }

    return foundWindow;
}
