#pragma once
#include "includes.h"
#include "Biljka.h"
#include "BazaZnanja.h"
#include "Voce.h"
#include <curl/curl.h>
#include <nlohmann/json.hpp>
class Preporuke
{
private:
	std::string apiKey;
	std::string apiEndpoint;
public:
	Preporuke(const std::string& key, const std::string& endpoint);
	std::string sendRequest(const std::string& prompt);
	std::string extractResponse(const std::string& jsonResponse);
private:
	static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

