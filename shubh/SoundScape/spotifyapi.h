#ifndef SPOTIFYAPI_H
#define SPOTIFYAPI_H

#include "QtNetworkAuth/qoauth2authorizationcodeflow.h"
#include <QObject>
#include "request.h"


class SpotifyAPI : public QObject
{
    Q_OBJECT
public:
    explicit SpotifyAPI(QObject *parent = nullptr);
    void authenticate();
    void setUpAuth();
    void callGetPlaylist();
    void downloadFinished(QNetworkReply * reply);
    void playSong(Playlist::playlist *);
    std::vector<Playlist::playlist> getVector();

private:

    QOAuth2AuthorizationCodeFlow * spotifyAuth;
    void setToken();
    void setAuthCode(QString v);
    QString authCode;
    QString accessToken;
    std::vector<Playlist::playlist> playlistVector;

signals:

};

#endif // SPOTIFYAPI_H
