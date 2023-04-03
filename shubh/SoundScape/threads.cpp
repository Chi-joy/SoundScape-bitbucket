//#include <QMutex>
//#include <QObject>
//#include <QMutexLocker>
//#include <mutex>

//class SharedData : public QObject
//{
//    Q_OBJECT

//public:
//    SharedData(QObject *parent = nullptr) : QObject(parent) {}

//    void setData(int value) {
//        QMutexLocker locker(&m_mutex);
//        m_data = value;
//    }

//    int getData() const {
//        std::lock_guard<QMutex> locker(m_mutex);
//        return m_data;
//    }

//    QMutex *mutex() {
//        return &m_mutex;
//    }

//signals:
//    void dataChanged(int value);

//private:
//    int m_data;
//    QMutex m_mutex;
//};

//class Sender : public QObject
//{
//    Q_OBJECT

//public:
//    Sender(SharedData *sharedData, QObject *parent = nullptr) : QObject(parent), m_sharedData(sharedData) {}

//    void sendData(int value) {
//        QMutexLocker locker(m_sharedData->mutex());
//        m_sharedData->setData(value);
//        emit dataSent(value);
//    }

//signals:
//    void dataSent(int value);

//private:
//    SharedData *m_sharedData;
//};

//class Receiver : public QObject
//{
//    Q_OBJECT

//public:
//    Receiver(SharedData *sharedData, QObject *parent = nullptr) : QObject(parent), m_sharedData(sharedData) {
//        connect(m_sharedData, &SharedData::dataChanged, this, &Receiver::handleDataChanged);
//    }

//public slots:
//    void handleDataChanged(int value) {
//        QMutexLocker locker(m_sharedData->mutex());
//        // do something with the data
//    }

//private:
//    SharedData *m_sharedData;
//};
