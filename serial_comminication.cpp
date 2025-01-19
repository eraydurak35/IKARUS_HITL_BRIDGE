#include <serial_comminication.h>
#include <QDebug>

SerialCommunication::SerialCommunication(QObject *parent)
    : QObject(parent), serialPort(new QSerialPort(this)) {

    connect(serialPort, &QSerialPort::readyRead, this, &SerialCommunication::handleReadyRead);
    connect(serialPort, &QSerialPort::errorOccurred, this, &SerialCommunication::handleError);
}

SerialCommunication::~SerialCommunication() {
    if (serialPort->isOpen()) {
        serialPort->close();
    }
    delete serialPort;
}

bool SerialCommunication::openSerialPort(const QString &portName, qint32 baudRate) {
    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Seri port açıldı:" << portName;
        return true;
    } else {
        emit errorOccurred(serialPort->errorString());
        return false;
    }
}

void SerialCommunication::closeSerialPort() {
    if (serialPort->isOpen()) {
        serialPort->close();
        qDebug() << "Seri port kapatıldı.";
    }
}

void SerialCommunication::sendData(const QByteArray &data, qint64 size) {
    if (serialPort->isOpen()) {
        serialPort->write(data.constData(), size);
    } else {
        qDebug() << "Seri port açık değil, veri gönderilemiyor!";
    }
}

QString SerialCommunication::findSerialPortByManufacturer(const QString name) {
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.manufacturer().contains(name)) {
            return info.portName();
        }
    }
    return "";
}

void SerialCommunication::handleReadyRead() {
    QByteArray data = serialPort->readAll();
    emit dataReceived(data);
}

void SerialCommunication::handleError(QSerialPort::SerialPortError error) {
    if (error != QSerialPort::NoError) {
        emit errorOccurred(serialPort->errorString());
    }
}
