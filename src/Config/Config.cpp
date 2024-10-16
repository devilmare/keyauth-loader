#include "Config.hpp"

namespace Config {
    // loader
    std::string app_name = xorstr_("ADD_YOUR_LOADER_NAME");
    std::string discord_link = xorstr_("ADD_YOUR_DISCOR_LINK");
    std::string dll_path = xorstr_("ADD_YOUR_DLL_PATH");
    std::string webhook_url = xorstr_("ADD_YOUR_WEBHOOK_URL");

    // to get all this information go to https://keyauth.win/ or https://keyauth.cc/
    std::string name = xorstr_("ADD_YOUR_AUTH_NAME");
    std::string ownerid = xorstr_("ADD_YOUR_AUTH_OWNER_ID");
    std::string secretkey = xorstr_("ADD_YOUR_AUTH_SECRET_KEY");
    std::string version = xorstr_("1.0");
    std::string url = xorstr_("https://keyauth.win/api/1.2/");
}
