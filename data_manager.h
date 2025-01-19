#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <udp_comminication.h>
#include <serial_comminication.h>
#include <Mavlink/common/mavlink.h>

class DataManager : public QObject {
    Q_OBJECT

public:
    explicit DataManager(QObject *parent = nullptr);
    ~DataManager();

    void handleUDPBytes(const QByteArray &data);

    void handleSerialBytes(const QByteArray &data);

    void sendMavlinkHeartBeat();

    void sendMavlinkActuator();

    bool startComminications();

private:

    UdpCommunication udp_comminication;

    SerialCommunication serial_comminication;

    void parseMavlinkMessages(mavlink_message_t msg);

    mavlink_hil_gps_t hil_gps;

    mavlink_hil_sensor_t hil_sensor;

    mavlink_heartbeat_t heartbeat;

    QTimer *heartbeat_timer;
};


#endif // DATA_MANAGER_H
