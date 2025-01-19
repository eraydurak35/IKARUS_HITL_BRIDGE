#ifndef SERIAL_COMMINICATION_H
#define SERIAL_COMMINICATION_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialCommunication : public QObject {
    Q_OBJECT

public:
    explicit SerialCommunication(QObject *parent = nullptr);
    ~SerialCommunication();

    bool openSerialPort(const QString &portName, qint32 baudRate);
    void closeSerialPort();
    void sendData(const QByteArray &data, qint64 size);

    QString findSerialPortByManufacturer(const QString name);

signals:
    void dataReceived(const QByteArray &data);
    void errorOccurred(const QString &error);

private slots:
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError error);

private:

    QString serial_port_name = "";
    QSerialPort *serialPort;
};



#endif // SERIAL_COMMINICATION_H
