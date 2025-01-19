#ifndef UDP_COMMINICATION_H
#define UDP_COMMINICATION_H

#include <QObject>
#include <QUdpSocket>

class UdpCommunication : public QObject {
    Q_OBJECT

public:
    explicit UdpCommunication(QObject *parent = nullptr);
    ~UdpCommunication();

    void sendData(const QByteArray &data, qint64 size);

signals:
    void dataReceived(const QByteArray &data);

private slots:
    void handleReadyRead();

private:
    QUdpSocket *udpSocket;


};


#endif // UDP_COMMINICATION_H
