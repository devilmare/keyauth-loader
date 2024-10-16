#pragma once
#include <include.hpp>

class Shared
{
public:
	static std::string GetUserInformation();
	static DWORD GetProcessIdFromName(LPCTSTR szProcessName);
	static BOOL IsElevated();
};
