/**
 * @file spotifyapi.cpp
 * @brief Implementation of the spotifyapi class.
 * 
 * This file contains the implementation of the spotiftyapi class, which
 * uses the Spotify API.
 * 
 * @author Shubh Fageria, Namashivayan Sivaram, Chi Zhang, Emily Chan, Valerie Lozano
 */

#include "spotifyapi.h"

#include "QtNetworkAuth/qoauthhttpserverreplyhandler.h"

#include <QOAuth2AuthorizationCodeFlow>
#include <QOAuthHttpServerReplyHandler>

#include <QDesktopServices>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QBitArray>
#include <QJsonDocument>
#include <QJsonObject>

/**
 * @brief Constructor for the SpotifyAPI class.
 *
 * This constructor creates a new instance of the SpotifyAPI class and initializes the
 * QOAuth2AuthorizationCodeFlow object used for authentication.
 *
 * @param parent The parent object for the new instance.
 */
SpotifyAPI::SpotifyAPI(QObject *parent)
    : QObject{parent}
{
    this->spotifyAuth = new QOAuth2AuthorizationCodeFlow();
}

/**
 * @brief Plays a song from the given playlist on the user's Spotify account.
 *
 * @param p A pointer to a Playlist::playlist object containing the URI of the playlist to play.
 */
void SpotifyAPI::playSong(Playlist::playlist * p){
    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
    const QUrl url(QStringLiteral("https://api.spotify.com/v1/me/player/play"));
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    std::string authBearder = "Bearer " + this->accessToken.toStdString();
    request.setRawHeader("Authorization", authBearder.c_str());
    QJsonObject obj;
    obj["context_uri"] = p->getPlaylistURI();
    obj["position_ms"] = "0";
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();

    QByteArray requestData = data; // the request body data
    QString requestUrl = url.toString(); // the request URL
    QStringList requestHeaders;
    foreach(QByteArray header, request.rawHeaderList()){
        requestHeaders.append(header + ": " + request.rawHeader(header));
    }
    qDebug() << "Request URL: " << requestUrl;
    qDebug() << "Request Headers: " << requestHeaders.join("\n");
    qDebug() << "Request Data: " << QString(requestData);

    // or
    //QNetworkReply *reply = mgr->post(request, data);
    QNetworkReply *reply = mgr->put(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=](){
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;
        }
    });
}

/**
 * @brief Sets up the authentication flow for the Spotify API.
 *
 * This function sets up the authentication flow for the Spotify API by configuring the
 * QOAuth2AuthorizationCodeFlow object used for authentication, setting various URLs,
 * and connecting signals and slots. It also sets up a QOAuthHttpServerReplyHandler to
 * handle the OAuth2 callback URL.
 */
void SpotifyAPI::setUpAuth() {
    const QString CLIENT_ID = "a0793c1022334f80aa55321895d1fef2";
    const QString CLIENT_SECRET = "3f45b87694ce4e9dbdd843302f53d407";
    const QString AUTH_URL = "https://accounts.spotify.com/en/authorize";
    const QString TOKEN_URL = "https://accounts.spotify.com/api/token";
    const QString SCOPES = "user-read-private%20user-read-email%20playlist-read-private%20playlist-read-collaborative%20user-modify-playback-state%20user-read-playback-state";
    const QString REDIRECT_URL = "http://127.0.0.1:8080/callback";
    const auto PORT_NUM = 8080;

    this->spotifyAuth->setScope(SCOPES);

    connect(this->spotifyAuth, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl);

    this->spotifyAuth->setAuthorizationUrl(QUrl(AUTH_URL));
    this->spotifyAuth->setClientIdentifier(CLIENT_ID);
    this->spotifyAuth->setAccessTokenUrl(QUrl(TOKEN_URL));
    this->spotifyAuth->setClientIdentifierSharedKey(CLIENT_SECRET);

    this->spotifyAuth->setModifyParametersFunction([this, SCOPES](QAbstractOAuth::Stage stage, QVariantMap* parameters) {
        if(stage == QAbstractOAuth::Stage::RequestingAuthorization){
            parameters->insert("redirect_uri",QUrl("http://127.0.0.1:8080/callback"));
            //parameters->insert("redirect_uri","http%3A%2F%2F127.0.0.1%3A8080%2Fcallback");
            parameters->insert("scope", SCOPES);
            //something breaks here ... but on web it says success...cant get right data??

        } if(stage == QAbstractOAuth::Stage::RequestingAccessToken) {
            parameters->insert("redirect_uri",QUrl("http://127.0.0.1:8080/callback"));
            parameters->insert("code",this->authCode);
            parameters->insert("grant_type", "client_credentials");
            //parameters->insert("port",8080);
            //return;
        }
    });

    connect(this->spotifyAuth,  &QOAuth2AuthorizationCodeFlow::granted, [this](){
        auto stop = "sgfojhdf";
        callGetPlaylist();
    });

        QOAuthHttpServerReplyHandler * replyHandler = new QOAuthHttpServerReplyHandler(PORT_NUM, this);

        this->spotifyAuth->setReplyHandler(replyHandler);

        connect(replyHandler, &QOAuthHttpServerReplyHandler::callbackReceived, [this](const QVariantMap &map) {
            auto authCoded = map.value("code");
            this->authCode = authCoded.toString();
            this->accessToken = initRequest(authCoded.toString().toStdString());
        });
}

/**
 * @brief Sets the authorization code for the OAuth2 authentication flow and initiates the request to obtain an access token.
 * 
 * @param v The authorization code as a QString.
 */
void SpotifyAPI::setAuthCode(QString v) {
    this->authCode = v;
    initRequest(v.toStdString());
}

/**
 * @brief Slot function that is called when a network reply has finished downloading data.
 * 
 * This function reads the data from the network reply and parses it into a nlohmann::json object.
 * It then calls the createVector() function to convert the JSON object into a vector of Playlist objects,
 * which is stored in the playlistVector member variable of the class.
 * 
 * @param reply A pointer to the QNetworkReply object that finished downloading data.
 */
void SpotifyAPI::downloadFinished(QNetworkReply * reply) {
    auto data = reply->readAll();
    nlohmann::json myjson = nlohmann::json::parse(data);
    this->playlistVector = createVector(myjson);
}

/**
 * @brief This function calls the Spotify API to get a list of playlists for the current user.
 */
void SpotifyAPI::callGetPlaylist() {
    QNetworkAccessManager * accessManager = new QNetworkAccessManager(this);
    connect(accessManager, &QNetworkAccessManager::finished,this, &SpotifyAPI::downloadFinished);

    const QUrl url = QUrl("https://api.spotify.com/v1/me/playlists");
    QNetworkRequest m_networkRequest(url);
    m_networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    m_networkRequest.setRawHeader("Accept", "application/json");
    std::string authBearder = "Bearer " + this->accessToken.toStdString();
    m_networkRequest.setRawHeader("Authorization", authBearder.c_str());
    accessManager->get(m_networkRequest);
}

/**
 * @brief This function returns a vector of Playlist objects.
 *
 * This function returns the private member variable playlistVector, which is a vector of Playlist
 * objects. The Playlist class represents a Spotify playlist and contains information such as the playlist's
 * name, owner, and track list.
 *
 * @return A vector of Playlist objects.
 */
std::vector<Playlist::playlist> SpotifyAPI::getVector() {
    return this->playlistVector;
}

/**
 * @brief This function authenticates the user with the Spotify API.
 */
void SpotifyAPI::authenticate() {
    this->setUpAuth();
    this->spotifyAuth->grant();
}
