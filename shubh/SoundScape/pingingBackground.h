#ifndef PINGINGBACKGROUND_H
#define PINGINGBACKGROUND_H

#include "Location.h"
#include "spotifyapi.h"
#include <QCoreApplication>
#include <QThread>

class pingingBackground
{
    public:
        pingingBackground();
        location::Location pingLocation();
        Playlist::playlist checkMapChange(location::Location currentLocation);

    protected:

    private:
};

#endif // PINGINGBACKGROUND_H
