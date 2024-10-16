#include "Discord.hpp"
#include <sstream>
#include <json.hpp>

using json = nlohmann::json;

Discord::Discord(const std::string& webhookUrl) : webhookUrl(webhookUrl) {}

Discord::~Discord() {}

bool Discord::SendDiscord(const std::string& title, const std::string& description, const std::string& color, const std::vector<std::pair<std::string, std::string>>& fields)
{
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        json jEmbed;
        jEmbed["title"] = title;
        jEmbed["description"] = description;
        jEmbed["color"] = std::stoi(color);

        for (const auto& field : fields)
        {
            jEmbed["fields"].push_back({ {"name", field.first}, {"value", field.second}, {"inline", true} });
        }

        json jPayload = {
            {"embeds", {jEmbed}}
        };

        std::string jsonPayload = jPayload.dump();

        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, webhookUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonPayload.c_str());

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return (res == CURLE_OK);
}
