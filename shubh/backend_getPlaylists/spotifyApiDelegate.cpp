#include <cstddef>
#include <iostream>
#include <array>
#include <curl/curl.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "spotifyApiDelegate.h"


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

//make curl request
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

    //redirect them to this URL thatll let them log in, have a callback function where the token returned goes
    // curl_easy_setopt(curl_handle, CURLOPT_URL, "https://accounts.spotify.com/authorize");
    // curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, "client_id=f6d6bc1e9dce452eb812a9f9973925ee&response_type=code&redirect_uri=soundscape-login://callback");
    // playlist-read-private%20playlist-read-collaborative%20user-modify-playback-state%20user-read-playback-state
    //https://accounts.spotify.com/en/authorize?client_id=f6d6bc1e9dce452eb812a9f9973925ee&response_type=code&scope=playlist-read-private%20playlist-read-collaborative%20user-modify-playback-state%20user-read-playback-state&redirect_uri=soundscape-login://callback
    
    
    curl_easy_setopt(curl_handle, CURLOPT_URL, "https://api.spotify.com/v1/me/playlists");
    //curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, "client_id=f6d6bc1e9dce452eb812a9f9973925ee&response_type=code&scope=&redirect_uri=soundscape-login://callback");
    struct curl_slist * headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "Accept: application/json");
    std::string authBearer = "Authorization: Bearer " + accessToken;
    headers = curl_slist_append(headers, authBearer.c_str());

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    //std::string myAuthCode = "AQA7IzLYtx-1Vmn6yG2J1MD5yzg8p2fioUunx3NDnBYHBdxUJ2ap29istdVzsf_hnP95RormtLUB5Ldr37oK8Ep2PQBzEQ-pib7Y06fvpWN4Vzzklxicg1gwGykvTEZIlyDut9V8ZpzCYppFS-TdPRy9KonPjdpuhAosKyZ3W-sVbbcvDPPX7jUWj5USSb2uRN4sBt1mPl-aMC3VNWbNswSM8hJQoVJUiAB7qekWx-yL62XmUQd3I5iFLTDB3DX45jMJkwsnHsi_c11aItSFpa2pepr-SvebG4IfZ9ILvzr6t7cBzRXO5JJt3a4";
    //std::string redirectURI = "http%3A%2F%2Flocalhost%3A8080%2Fcallback";
    //std::string clientId = "f6d6bc1e9dce452eb812a9f9973925ee";
    //std::string clientSecret = "8971b907959143adaf59cd19f8ae04ce";
    //std::string postFields = "grant_type=authorization_code&code=" + myAuthCode + "&redirect_uri=" + redirectURI + "&client_id=" + clientId + "&client_secret=" + clientSecret;
    //string response;
    //curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &response);

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
        //std::string accessToken = myjson["access_token"];
        //std::cout << accessToken;


	    // //create vector of games
        // vector<Game> vGame = createVector(myjson);
        // int size = vGame.size();

	    // //std output 
        // for (int i = 0; i < size; i++) {
        //     Game tempGame = vGame[i];
        //     cout << tempGame.getHomeTeam();
        //     cout << " vs. ";
        //     cout << tempGame.getAwayTeam();
        //     cout << ":   ";
        //     cout << tempGame.getHomeScore();
        //     cout << " - ";
        //     cout << tempGame.getAwayScore() << endl;
        // }

    }

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

    free(chunk.memory);

    /* we are done with libcurl, so clean it up */
    curl_global_cleanup();

}


