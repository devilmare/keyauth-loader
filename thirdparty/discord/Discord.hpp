#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <curl.h>
#include <sstream>
#include <vector>
#include <utility>

class Discord
{
public:
    Discord(const std::string& webhookUrl);
    ~Discord();
    bool SendDiscord(const std::string& title, const std::string& description, const std::string& color, const std::vector<std::pair<std::string, std::string>>& fields);

private:
    std::string webhookUrl;
};
