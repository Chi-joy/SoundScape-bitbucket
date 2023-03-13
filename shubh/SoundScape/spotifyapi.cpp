#include "spotifyapi.h"

#include "QtNetworkAuth/qoauthhttpserverreplyhandler.h"


#include <QOAuth2AuthorizationCodeFlow>
#include <QOAuthHttpServerReplyHandler>


#include <QDesktopServices>
#include <QUrlQuery>


SpotifyAPI::SpotifyAPI(QObject *parent)
    : QObject{parent}
{

    this->spotifyAuth = new QOAuth2AuthorizationCodeFlow();
}


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

//    std::string r = "redirect_uri";
//    this->spotifyAuth->setProperty(r.c_str(),QVariant::fromValue(REDIRECT_URL));



    this->spotifyAuth->setModifyParametersFunction([this](QAbstractOAuth::Stage stage, QVariantMap* parameters) {
        if(stage == QAbstractOAuth::Stage::RequestingAuthorization){
            parameters->insert("redirect_uri",QUrl("http://127.0.0.1:8080/callback"));
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
    });

    QOAuthHttpServerReplyHandler * replyHandler = new QOAuthHttpServerReplyHandler(PORT_NUM, this);

    this->spotifyAuth->setReplyHandler(replyHandler);

    connect(replyHandler, &QOAuthHttpServerReplyHandler::callbackReceived, [this](const QVariantMap &map) {
        auto authCoded = map.value("code");
        this->authCode = authCoded.toString();
        this->accessToken = initRequest(authCoded.toString().toStdString());




    });



    //LoginWindow::authenticate();
}

void SpotifyAPI::setAuthCode(QString v) {
    this->authCode = v;
    initRequest(v.toStdString());
}



void SpotifyAPI::authenticate() {

    this->setUpAuth();
    this->spotifyAuth->grant();

    ///catch error statement???

}
