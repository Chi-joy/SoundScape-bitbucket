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
    QNetworkRequest m_networkRequest;
    m_networkRequest.setUrl(QUrl("https://api.spotify.com/v1/me/playlists"));
    m_networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    m_networkRequest.setRawHeader("Accept", "application/json");
    std::string authBearder = "Bearer " + accessToken;
    m_networkRequest.setRawHeader("Authorization", authBearder.c_str());

    QNetworkAccessManager accessManager;
    QNetworkReply * m_networkReply = accessManager.get(m_networkRequest);
    QByteArray data = m_networkReply->readAll();

    QObject::connect(m_networkReply, &QNetworkReply::sslErrors, [=]() {

        qDebug() << data;
    });
                    std::cout << "access token: ";
//        //std::cout << accessToken;

//    CURL* curl_handle;
//    CURLcode res;

//    struct MemoryStruct chunk;

//    chunk.memory = (char*)malloc(1); /* will be grown as needed by the realloc above */
//    chunk.size = 0;                  /* no data at this point */

//    curl_global_init(CURL_GLOBAL_ALL);

//    /* init the curl session */
//    curl_handle = curl_easy_init();

//    /* specify URL to get */

//    //redirect them to this URL thatll let them log in, have a callback function where the token returned goes
//    // curl_easy_setopt(curl_handle, CURLOPT_URL, "https://accounts.spotify.com/authorize");
//    // curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, "client_id=f6d6bc1e9dce452eb812a9f9973925ee&response_type=code&redirect_uri=soundscape-login://callback");
//    // playlist-read-private%20playlist-read-collaborative%20user-modify-playback-state%20user-read-playback-state
//    //https://accounts.spotify.com/en/authorize?client_id=f6d6bc1e9dce452eb812a9f9973925ee&response_type=code&scope=playlist-read-private%20playlist-read-collaborative%20user-modify-playback-state%20user-read-playback-state&redirect_uri=soundscape-login://callback


//    curl_easy_setopt(curl_handle, CURLOPT_URL, "https://api.spotify.com/v1/me/playlists");
//    curl_easy_setopt(curl_handle, CURLOPT_CUSTOMREQUEST, "GET");
//    //curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, "client_id=f6d6bc1e9dce452eb812a9f9973925ee&response_type=code&scope=&redirect_uri=soundscape-login://callback");
//    struct curl_slist * headers = NULL;
//    headers = curl_slist_append(headers, "Content-Type: application/json");
//    headers = curl_slist_append(headers, "Accept: application/json");
//    curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, headers);
//    std::string authBearer = "Authorization: Bearer " + accessToken;
//    headers = curl_slist_append(headers, authBearer.c_str());
//    std::cout << authBearer.c_str();

//    /* send all data to this function  */
//    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
//    //std::string myAuthCode = "AQA7IzLYtx-1Vmn6yG2J1MD5yzg8p2fioUunx3NDnBYHBdxUJ2ap29istdVzsf_hnP95RormtLUB5Ldr37oK8Ep2PQBzEQ-pib7Y06fvpWN4Vzzklxicg1gwGykvTEZIlyDut9V8ZpzCYppFS-TdPRy9KonPjdpuhAosKyZ3W-sVbbcvDPPX7jUWj5USSb2uRN4sBt1mPl-aMC3VNWbNswSM8hJQoVJUiAB7qekWx-yL62XmUQd3I5iFLTDB3DX45jMJkwsnHsi_c11aItSFpa2pepr-SvebG4IfZ9ILvzr6t7cBzRXO5JJt3a4";
//    //std::string redirectURI = "http%3A%2F%2Flocalhost%3A8080%2Fcallback";
//    //std::string clientId = "f6d6bc1e9dce452eb812a9f9973925ee";
//    //std::string clientSecret = "8971b907959143adaf59cd19f8ae04ce";
//    //std::string postFields = "grant_type=authorization_code&code=" + myAuthCode + "&redirect_uri=" + redirectURI + "&client_id=" + clientId + "&client_secret=" + clientSecret;
//    //string response;
//    //curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &response);

//    /* we pass our 'chunk' struct to the callback function */
//    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)&chunk);
//    //curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, postFields.c_str());

//    /* some servers do not like requests that are made without a user-agent
//     field, so we provide one */
//    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

//    /* get it! */
//    res = curl_easy_perform(curl_handle);

//    /* check for errors */
//    if (res != CURLE_OK)
//    {
//        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
//    }
//    else
//    {
//        //parse returned json
//        nlohmann::json myjson = nlohmann::json::parse(chunk.memory);
//        std::cout << chunk.memory;
//        //std::string accessToken = myjson["access_token"];
//        //std::cout << "access token: ";
//        //std::cout << accessToken;


//        // //create vector of games
//        // vector<Game> vGame = createVector(myjson);
//        // int size = vGame.size();

//        // //std output
//        // for (int i = 0; i < size; i++) {
//        //     Game tempGame = vGame[i];
//        //     cout << tempGame.getHomeTeam();
//        //     cout << " vs. ";
//        //     cout << tempGame.getAwayTeam();
//        //     cout << ":   ";
//        //     cout << tempGame.getHomeScore();
//        //     cout << " - ";
//        //     cout << tempGame.getAwayScore() << endl;
//        // }

//    }

//    /* cleanup curl stuff */
//    curl_easy_cleanup(curl_handle);
//    curl_slist_free_all(headers);

//    free(chunk.memory);

//    /* we are done with libcurl, so clean it up */
//    curl_global_cleanup();

}

vector<Playlist::playlist> createVector(nlohmann::json & myjson) {
//    vector<Playlist::playlist> vPlaylist;

//    auto& playlists = myjson["items"];

////for every date...
//    for (int i = 0; i < playlists.items(); i++)
//    {
//        try {
//        auto z = playlists[i];
//        if (z.is_null()) {
//            break;
//        }
//        std::string s_uri = playlists[i]["uri"];
//        QString uri = QString::fromStdString(s_uri);

//        std::string s_name = playlists[i]["name"];
//        QString name = QString::fromStdString(s_uri);

//        std::string s_coverURL = playlists[i]["images"][0]["url"];
//        QString coverURL = QString::fromStdString(s_coverURL);
//        //std::cout << name ;

//        //has location will be set to false, override with association json
//        bool hasLocation = false;
//        Playlist::playlist tempPlaylist(name, uri, coverURL, hasLocation);
//        vPlaylist.push_back(tempPlaylist);
//        }

//        catch (...) {
//            std::cout << "you fucked up somewhere";
//        }
            

//    }
    
//    return vPlaylist;
    
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


