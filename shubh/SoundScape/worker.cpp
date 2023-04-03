//// myworker.cpp
//#include "worker.h"
//#include "QtCore/qeventloop.h"
//#include "QtCore/qthread.h"
//#include "pingingBackground.h"

//MyWorker::MyWorker(QObject *parent) : QObject(parent)
//{
//    // constructor implementation
//}

//void MyWorker::doWork()
//{
//        QEventLoop * eventLoop = new QEventLoop();
//        pingingBackground * ping = new pingingBackground();
//        while (true) {
//            // Do some work in the background
//            //mutex.lock();
//            eventLoop->processEvents();

//            location::Location curLoc = ping->pingLocation();
//            //Playlist::playlist p = ping->checkMapChange(curLoc);
//            QString latnlng = QString::number(curLoc.getLat()) + "," + QString::number(curLoc.getLng());

//            //if (p.getPlaylistName() != "dummy") {
//                emit messageReceived(latnlng);
//                //qDebug() << "Message sent from MyWorker";
//            //}

//            //mutex.unlock();
//            QThread::msleep(10*1000); // Sleep for 10 seconds (in milliseconds)
//        }
//    }

//// add implementation for messageReceived here
