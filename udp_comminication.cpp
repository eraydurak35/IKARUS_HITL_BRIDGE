#include "udp_comminication.h"
#include <QThread>
#include <QDebug>

UdpCommunication::UdpCommunication(QObject *parent)
    : QObject(parent), udpSocket(new QUdpSocket(this)) {

    connect(udpSocket, &QUdpSocket::readyRead, this, &UdpCommunication::handleReadyRead);
}


UdpCommunication::~UdpCommunication() {
    if (udpSocket) {
        udpSocket->close();
        delete udpSocket;
    }
}

void UdpCommunication::sendData(const QByteArray &data, qint64 size) {
    udpSocket->writeDatagram(data.constData(), size, QHostAddress("127.0.0.1"), 14560);  // 14560 jMAVSim dinlediği port
}

void UdpCommunication::handleReadyRead()
{
    QByteArray data;
    QHostAddress sender;
    quint16 senderPort;

    while (udpSocket->hasPendingDatagrams()) {
        data.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(data.data(), data.size(), &sender, &senderPort);
        emit dataReceived(data);
    }
}




































// #include <udp_comminication.h>

// QUdpSocket *udpSocket;

// void udp_data_received_handler();

// void start_udp_comminication()
// {
//     udpSocket = new QUdpSocket();

//     // Simülatörün çalışmaya başlamasını bekle
//     QThread::sleep(8);

//     // 14560 portunda dinleme başlat
//     udpSocket->bind(QHostAddress("127.0.0.1"), 14560);

//     // Gelen verileri kontrol etmek için hazır
//     connect(udpSocket, &QUdpSocket::readyRead, &udp_data_received_handler);
// }

// void udp_data_received_handler()
// {

// }
