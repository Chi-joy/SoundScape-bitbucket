/* -------------------
SHUBH FAGERIA
FEBRUARY 7, 2023
CS3307
Assignment 1
--------------------*/

#include <cstddef>
#include <iostream>
#include <array>
#include <curl/curl.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string>


#include "request.h"
//#include "spotifyApiDelegate.h"

using namespace std;

struct MemoryStruct
{
    char* memory;
    size_t size;
};

struct team* teams;

//callback function for curl request
static size_t
WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;


    struct MemoryStruct* mem = (struct MemoryStruct*)userp;

    char* ptr = (char*)realloc(mem->memory, mem->size + realsize + 1);
    if (!ptr)
    {
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

void getPlaylists(std::string accessToken)
{


    CURL* curl_handle;
    CURLcode res;

    struct MemoryStruct chunk;

    chunk.memory = (char*)malloc(1); /* will be grown as needed by the realloc above */
    chunk.size = 0;                  /* no data at this point */

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* specify URL to get */

    
    curl_easy_setopt(curl_handle, CURLOPT_URL, "https://api.spotify.com/v1/me/playlists");
    curl_easy_setopt(curl_handle, CURLOPT_CUSTOMREQUEST, "GET");
    //curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, "client_id=f6d6bc1e9dce452eb812a9f9973925ee&response_type=code&scope=&redirect_uri=soundscape-login://callback");
    struct curl_slist * headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "Accept: application/json");
    curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, headers);
    std::string authBearer = "Authorization: Bearer " + accessToken;
    headers = curl_slist_append(headers, authBearer.c_str());
    std::cout << authBearer.c_str();

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

    /* we pass our 'chunk' struct to the callback function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)&chunk);
    //curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, postFields.c_str()); 

    /* some servers do not like requests that are made without a user-agent
     field, so we provide one */
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    /* get it! */
    res = curl_easy_perform(curl_handle);

    /* check for errors */
    if (res != CURLE_OK)
    {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
    else
    {
	    //parse returned json
        nlohmann::json myjson = nlohmann::json::parse(chunk.memory);
	    std::cout << chunk.memory;
    }

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);
    curl_slist_free_all(headers);

    free(chunk.memory);

    /* we are done with libcurl, so clean it up */
    curl_global_cleanup();

}

//make curl request
void initRequest(std::string authCode)
{
    CURL* curl_handle;
    CURLcode res;

    struct MemoryStruct chunk;

    chunk.memory = (char*)malloc(1); /* will be grown as needed by the realloc above */
    chunk.size = 0;                  /* no data at this point */

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* specify URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, "https://accounts.spotify.com/api/token");
    //curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, "client_id=f6d6bc1e9dce452eb812a9f9973925ee&response_type=code&scope=&redirect_uri=soundscape-login://callback");
    struct curl_slist * headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
    //headers = curl_slist_append(headers, "Authorization: Basic ZjZkNmJjMWU5ZGNlNDUyZWI4MTJhOWY5OTczOTI1ZWU6ODk3MWI5MDc5NTkxNDNhZGFmNTljZDE5ZjhhZTA0Y2U=");//encoded secret 

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    //std::string myAuthCode = "AQDkpByln0BlUIvmJWEoD_NOYxvzpYiCsI4uPFk6V2Jj0iyC2hKI0LMR1uz4dhTmmljIKWFE3c1BhLqKTsWqg_qjXS5FECpvppftH9D_YDK-jROOdavJKcGWmcCm9wNSAikm8qDvQ3VPxaG7qBwdxeaM70yHjJARxsMhdmJ-x-riqgfg4rdoo9vYxv_S5tZEB0Dg8-0Im7LtQtPF9gqZi5zt3Zm5oWkF9IajdzIyYxHQ4FuruXTr7B7UdINXf5B0ctL9XRGtsGis4xa4A3VdN_sGC3gTYN245yAzqXC5zkJusANfIWzQdG71Xck";
    std::string myAuthCode = authCode;
    std::string redirectURI = "http%3A%2F%2Flocalhost%3A8080%2Fcallback";
    std::string clientId = "f6d6bc1e9dce452eb812a9f9973925ee";
    std::string clientSecret = "8971b907959143adaf59cd19f8ae04ce";
    std::string postFields = "grant_type=authorization_code&code=" + myAuthCode + "&redirect_uri=" + redirectURI + "&client_id=" + clientId + "&client_secret=" + clientSecret;
    //string response;
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)&chunk);
    curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, postFields.c_str()); 

    /* some servers do not like requests that are made without a user-agent
     field, so we provide one */
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    /* get it! */
    res = curl_easy_perform(curl_handle);

    /* check for errors */
    if (res != CURLE_OK)
    {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
    else
    {
	    //parse returned json
        nlohmann::json myjson = nlohmann::json::parse(chunk.memory);
	    //std::cout << chunk.memory;
        std::string accessToken = myjson["access_token"];
        //         std::cout << "access token: ";
        // std::cout << accessToken;
        getPlaylists(accessToken);
        //std::cout << accessToken;
    }

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);
    curl_slist_free_all(headers);

    free(chunk.memory);

    /* we are done with libcurl, so clean it up */
    curl_global_cleanup();

}


