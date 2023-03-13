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


    this->spotifyAuth->setModifyParametersFunction([](QAbstractOAuth::Stage stage, QVariantMap* parameters) {
        if (stage == QAbstractOAuth::Stage::RequestingAccessToken) {
           QByteArray code = parameters->value("code").toByteArray();
           (*parameters)["code"] = QUrl::fromPercentEncoding(code);
        }
        if(stage == QAbstractOAuth::Stage::RequestingAuthorization){
            parameters->insert("redirect_uri",QUrl("http://127.0.0.1:8080/callback"));
            //something breaks here ... but on web it says success...cant get right data??

        }


    });

    QOAuthHttpServerReplyHandler * replyHandler = new QOAuthHttpServerReplyHandler(PORT_NUM, this);

    this->spotifyAuth->setReplyHandler(replyHandler);


    connect(this->spotifyAuth, &QOAuth2AuthorizationCodeFlow::granted, [=](){
            this->accessToken = this->spotifyAuth->token();
            //emit gotToken(this->accessToken);
    });
//   connect(this->spotifyAuth, &QOAuth2AuthorizationCodeFlow::authorizationCallbackReceived,(QMap<Qt::Key, QVariant> * map) {

//               auto idk = map.begin();
//           });

    connect(replyHandler, &QOAuthHttpServerReplyHandler::callbackReceived, [this](const QVariantMap &map) {
        auto authCoded = map.value("code");
        setAuthCode(authCoded);

    });




    //LoginWindow::authenticate();
}

void SpotifyAPI::setAuthCode(QVariant v) {
    this->authCode = v.toString();
}

void SpotifyAPI::setToken() {
    initRequest(this->authCode);
}

void SpotifyAPI::authenticate() {

    this->setUpAuth();
    this->spotifyAuth->grant();
    setToken();

}
