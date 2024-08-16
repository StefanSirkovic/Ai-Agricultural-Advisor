#include "Preporuke.h"


Preporuke::Preporuke(const std::string& key, const std::string& endpoint) :apiKey(key),
apiEndpoint(endpoint) {}

std::string Preporuke::sendRequest(const std::string& prompt)
{
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, apiEndpoint.c_str());
        // Set API key in the headers
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + apiKey).c_str());
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Create JSON data with the prompt
        std::string jsonData = R"({
            "model": "gpt-4o-mini", 
            "messages": [
                            {
                                "role": "user", 
                                "content": ")" + prompt + R"("
                            }
                         ],
            "max_tokens": 50
            })";
        
        
        // Set POST fields
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonData.c_str());

        // Callback function to handle data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        // Clean up
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return readBuffer;
  }

std::string Preporuke::extractResponse(const std::string& jsonResponse)
{
    using json = nlohmann::json;
    
    try {
        auto parsedJson = json::parse(jsonResponse);
        std::string content = parsedJson["choices"][0]["message"]["content"];
        
        return content;
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        return "";
    }
}

size_t Preporuke::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


