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
#include <QJsonDocument>

#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "QtCore/qtextstream.h"
#include "request.h"
//#include "spotifyApiDelegate.h"

using namespace std;

struct MemoryStruct
{
    char* memory;
    size_t size;
};

//callback function for curl request
std::string theAccessToken;
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

    nlohmann::json myjson = nlohmann::json::parse(mem->memory);

    theAccessToken = myjson["access_token"];
    //setToken(myjson);

    mem->size += realsize;
    mem->memory[mem->size] = 0;
    free(ptr);
    return realsize;
}

void setToken(nlohmann::json myjson) {

    //initRequest(toSend);
    //accessToken = myjson["access_token"];

}

void getPlaylists(std::string accessToken)
{

}

vector<Playlist::playlist> createVector(nlohmann::json & myjson) {
    vector<Playlist::playlist> vPlaylist;

    auto& playlists = myjson["items"];

//for every date...
    for (int i = 0; i < playlists.items(); i++)
    {
        try {
        auto z = playlists[i];
        if (z.is_null()) {
            break;
        }
        std::string s_uri = playlists[i]["uri"];
        QString uri = QString::fromStdString(s_uri);

        std::string s_name = playlists[i]["name"];
        QString name = QString::fromStdString(s_name);

        std::string s_coverURL = playlists[i]["images"][0]["url"];
        QString coverURL = QString::fromStdString(s_coverURL);
        //std::cout << name ;

        //has location will be set to false, override with association json
        bool hasLocation = false;
        Playlist::playlist tempPlaylist(name, uri, coverURL, hasLocation);
        vPlaylist.push_back(tempPlaylist);
        }

        catch (...) {
            std::cout << "you fucked up somewhere";
        }
            

    }
    
    return vPlaylist;
    
}

//make curl request
QString initRequest(std::string authCode)
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
    struct curl_slist * headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");

    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    //QString myAuthCode = "AQDkpByln0BlUIvmJWEoD_NOYxvzpYiCsI4uPFk6V2Jj0iyC2hKI0LMR1uz4dhTmmljIKWFE3c1BhLqKTsWqg_qjXS5FECpvppftH9D_YDK-jROOdavJKcGWmcCm9wNSAikm8qDvQ3VPxaG7qBwdxeaM70yHjJARxsMhdmJ-x-riqgfg4rdoo9vYxv_S5tZEB0Dg8-0Im7LtQtPF9gqZi5zt3Zm5oWkF9IajdzIyYxHQ4FuruXTr7B7UdINXf5B0ctL9XRGtsGis4xa4A3VdN_sGC3gTYN245yAzqXC5zkJusANfIWzQdG71Xck";
    std::string myAuthCode = authCode;
    std::string redirectURI = "http://127.0.0.1:8080/callback";
    std::string clientId = "a0793c1022334f80aa55321895d1fef2";
    std::string clientSecret = "3f45b87694ce4e9dbdd843302f53d407";
    std::string postFields = "grant_type=authorization_code&code=" + myAuthCode + "&redirect_uri=" + redirectURI + "&client_id=" + clientId + "&client_secret=" + clientSecret;
    //string response;
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)&chunk);
    auto sfg = postFields.c_str();
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
        //nlohmann::json myjson = nlohmann::json::parse(chunk.memory);
        //nlohmann::json myjson = nlohmann::json::parse(chunk.memory);
        //std::cout << chunk.memory;
       // QTextStream out(stdout);
       // out << QString(chunk.memory);
      //  auto adskjgh = QString(chunk.memory);

       // std::string accessToken = myjson["access_token"];
       // QString q_accessToken = QString::fromStdString(accessToken);
        //         std::cout << "access token: ";
       // std::cout << "hi";
        //getPlaylists(q_accessToken);
        //std::cout << accessToken;
    }

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);
    curl_slist_free_all(headers);

    //free(chunk.memory);

    /* we are done with libcurl, so clean it up */
    curl_global_cleanup();
    return QString::fromUtf8(theAccessToken.c_str());

}


