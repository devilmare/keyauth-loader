/* ==================================================== */
/*   THIS IS SOURCE CODE IS FREE, CREATED BY BRUTALIZE  */
/*   This code is for learning only. It contains some   */
		  /* useful things that you can use */
			       /* HAVE FUN <3 */
/* ==================================================== */

#include <include.hpp>

#include <auth.hpp>
#include <Config.hpp>

#include <Shareds/Utils.hpp>
#include <Shareds/Console.hpp>
#include <Dump/EntrySizeOfImage.hpp>

using namespace KeyAuth;
using namespace Config;

DWORD tAntiAnalysis = NULL;

api KeyAuthApp(name, ownerid, secretkey, version, url);

VOID AntiAnalysisThread()
{
    while (true)
    {
        Process::CheckProcess();
        Window::CheckWindow();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(int argc, char* argv[])
{
    name.clear(); ownerid.clear(); secretkey.clear(); version.clear(); url.clear();

    if (Shared::IsElevated())
    {
        HANDLE hAntiAnalysis = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)AntiAnalysisThread, NULL, 0, &tAntiAnalysis);

        SetupConsole();

        printMessage(xorstr_("Info"), xorstr_("Starting...\n"));

        KeyAuthApp.init();

        if (!KeyAuthApp.response.success)
        {
            printMessage(xorstr_("Error"), xorstr_("ERROR: ") + KeyAuthApp.response.message + xorstr_("\n"));
            Sleep(3000);
            return 1;
        }

        std::string license;

        printMessage(xorstr_("Info"), xorstr_("License Key: "));
        std::cin >> license;

        KeyAuthApp.license(license);

        if (!KeyAuthApp.response.success)
        {
            printMessage(xorstr_("Error"), xorstr_("ERROR: ") + KeyAuthApp.response.message + xorstr_("\n"));
            Sleep(3000);
            return 1;
        }

        printMessage(xorstr_("Success"), xorstr_("You have logged in successfully\n"));

        Sleep(1000);
        system("cls");
        Sleep(500);

        printMessage(xorstr_("Info"), xorstr_("Welcome, To Brutalize Cheats\n"));
        printMessage(xorstr_("Info"), xorstr_("Your Key ") + KeyAuthApp.user_data.username + xorstr_("\n"));

        auto subs = KeyAuthApp.user_data.subscriptions.front();
        const char* szExpiry = tm_to_readable_time(timet_to_tm(string_to_timet(subs.expiry))).c_str();
        printMessage(xorstr_("Info"), xorstr_("Expiry Date: ") + std::string(szExpiry) + xorstr_("\n"));

        Sleep(1000);

        printMessage(xorstr_("Info"), xorstr_("Loading Requirements...\n"));

        std::vector<std::uint8_t> dllFile = KeyAuthApp.download(xorstr_("719853"));
        if (!KeyAuthApp.response.success)
        {
            printMessage(xorstr_("Error"), xorstr_("ERROR: ") + KeyAuthApp.response.message + xorstr_("\n"));
            Sleep(3000);
            return 1;
        }

        printMessage(xorstr_("Info"), xorstr_("Done...\n"));
    }
    else
    {
        MessageBoxA(0, xorstr_("The Application must be run as administrator"), NULL, MB_ICONERROR);
        return 1;
    }

    getchar();
    return 0;
}