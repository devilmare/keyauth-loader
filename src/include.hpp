#pragma once

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <atlsecurity.h>
#include <TlHelp32.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <IPTypes.h>
#include <Iphlpapi.h>
#include <icmpapi.h>
#include <Psapi.h>
#include <Shlwapi.h>
#include <ShlObj.h>
#include <stdarg.h>
#include <strsafe.h>
#include <time.h>
#include <TlHelp32.h>
#include <Wbemidl.h>
#include <devguid.h>
#include <winioctl.h>
#include <intrin.h>	
#include <locale.h>
#include <powrprof.h>
#include <SetupAPI.h>
#include <algorithm>
#include <cctype>
#include <slpublic.h> 
#include <cassert> 
#include <VersionHelpers.h>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <direct.h>
#include <tchar.h>
#include <winternl.h>

#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "Shlwapi.lib")
#pragma comment(lib, "Mpr.lib")
#pragma comment(lib, "Iphlpapi.lib")
#pragma comment(lib, "Shlwapi.lib")
#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "setupapi.lib")
#pragma comment(lib, "powrprof.lib")
#pragma comment(lib, "Slwga.lib")

#include <Discord.hpp>

// Shareds files
#include "Shareds/XorStr.hpp"
#include <Shared/Shared.hpp>

// Security - Anti Analysis
#include <Analysis/FindProcess.hpp>
#include <Analysis/FindWindow.hpp>