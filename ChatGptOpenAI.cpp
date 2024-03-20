#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Callback function to handle the response data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
	size_t newLength = size*nmemb;
	size_t oldLength = s->size();
	try {
		s->resize(oldLength + newLength);
	} catch(std::bad_alloc &e) {
		// handle memory problem
		return 0;
	}

	std::copy((char*)contents,(char*)contents+newLength,s->begin()+oldLength);
	return size*nmemb;
}

// Function to send a POST request to the OpenAI API
std::string sendPostRequest(const std::string& url, const std::string& postFields, const std::string& apiKey) {
	CURL* curl;
	CURLcode res;
	std::string response;

	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();

	if(curl) {
		struct curl_slist *headers = NULL;
		headers = curl_slist_append(headers, ("Authorization: Bearer " + apiKey).c_str());
		headers = curl_slist_append(headers, "Content-Type: application/json");

		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		res = curl_easy_perform(curl);

		if(res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}

		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();

	return response;
}

int main() {
	std::string apiKey = "your-api-key";
	std::string url = "https://api.openai.com/v1/engines/davinci-codex/completions";
	json data;
	data["prompt"] = "Translate the following English text to French: '{}'";
	data["max_tokens"] = 60;

	std::string response = sendPostRequest(url, data.dump(), apiKey);
	json responseJson = json::parse(response);

	std::cout << responseJson["choices"][0]["text"]["content"] << std::endl;

	return 0;
}
