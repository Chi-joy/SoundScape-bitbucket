#ifndef SPOTIFYAPI_H
#define SPOTIFYAPI_H

#include "QtNetworkAuth/qoauth2authorizationcodeflow.h"
#include <QObject>

class SpotifyAPI : public QObject
{
    Q_OBJECT
public:
    explicit SpotifyAPI(QObject *parent = nullptr);
    void authenticate();
    void setUpAuth();

private:

    QOAuth2AuthorizationCodeFlow * spotifyAuth;
    void authorizationCallbackReceived(const QString &callbackUri);
    QString authCode;
    QString accessToken;

signals:

};

#endif // SPOTIFYAPI_H
