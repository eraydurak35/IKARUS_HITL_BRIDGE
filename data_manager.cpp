#include <data_manager.h>

DataManager::DataManager(QObject *parent)
    : QObject(parent) {

    QObject::connect(&udp_comminication, &UdpCommunication::dataReceived, [this](const QByteArray &data) {
        handleUDPBytes(data);
    });

    QObject::connect(&serial_comminication, &SerialCommunication::dataReceived, [this](const QByteArray &data) {
        handleSerialBytes(data);
    });

    QObject::connect(&serial_comminication, &SerialCommunication::errorOccurred, [](const QString &error) {
        qDebug() << "Serial Hata:" << error;
    });

    heartbeat_timer = new QTimer(this);
    connect(heartbeat_timer, &QTimer::timeout, this, &DataManager::sendMavlinkHeartBeat);
}

DataManager::~DataManager() {}

void DataManager::handleUDPBytes(const QByteArray &data) {

    serial_comminication.sendData(data, data.length());


    // Gelen datagramı çözümle
    //static mavlink_message_t msg;
    //static mavlink_status_t status;

    //static uint32_t msg_size = 0;

    //for (int i = 0; i < data.size(); i++) {

        //msg_size++;

    //    if (mavlink_parse_char(MAVLINK_COMM_0, data[i], &msg, &status)) {
    //        parseMavlinkMessages(msg);

            // qDebug() << msg_size;
            // msg_size = 0;
    //    }
    //}



}

void DataManager::handleSerialBytes(const QByteArray &data) {
    //qDebug() << "serial: " << data;

    udp_comminication.sendData(data, data.length());
}

void DataManager::parseMavlinkMessages(mavlink_message_t msg) {

    // Alınan mesaj türüne göre işlem yapın
    switch (msg.msgid) {
    case MAVLINK_MSG_ID_HEARTBEAT:
    {
        //mavlink_msg_heartbeat_decode(&msg, &heartbeat);

        // Gelen heartbeat mesajındaki verileri işleme
        // qDebug() << "Heartbeat alındı!";
        // qDebug() << "Type: " << heartbeat.type;
        // qDebug() << "Autopilot: " << heartbeat.autopilot;
        // qDebug() << "Base mode: " << heartbeat.base_mode;
        // qDebug() << "Custom mode: " << heartbeat.custom_mode;
        // qDebug() << "System status: " << heartbeat.system_status;
        break;
    }
    case MAVLINK_MSG_ID_HIL_GPS:
    {
        mavlink_msg_hil_gps_decode(&msg, &hil_gps);

        // Gelen GPS verilerini işleme
        //qDebug() << "HIL GPS alındı!";
        // qDebug() << "Fix: " << hil_gps.fix_type;
        // qDebug() << "Latitude: " << hil_gps.lat;
        // qDebug() << "Longitude: " << hil_gps.lon;
        // qDebug() << "Altitude: " << hil_gps.alt;
        // qDebug() << "HDOP: " << hil_gps.eph;
        // qDebug() << "VDOP: " << hil_gps.epv;
        // qDebug() << "vel: " << hil_gps.vel;
        // qDebug() << "vn: " << hil_gps.vn;
        // qDebug() << "ve: " << hil_gps.ve;
        // qDebug() << "vd: " << hil_gps.vd;
        // qDebug() << "cog: " << hil_gps.cog;
        // qDebug() << "Satelite Count: " << hil_gps.satellites_visible;
        break;
    }
    case MAVLINK_MSG_ID_HIL_SENSOR:
    {
        mavlink_msg_hil_sensor_decode(&msg, &hil_sensor);

        // Gelen sensör verilerini işleme
        //qDebug() << "HIL Sensor alındı!";
        // qDebug() << "Accelerometer X: " << hil_sensor.xacc;
        // qDebug() << "Accelerometer Y: " << hil_sensor.yacc;
        // qDebug() << "Accelerometer Z: " << hil_sensor.zacc;
        // qDebug() << "Gyro X: " << hil_sensor.xgyro;
        // qDebug() << "Gyro Y: " << hil_sensor.ygyro;
        // qDebug() << "Gyro Z: " << hil_sensor.zgyro;
        // qDebug() << "Magnetometer X: " << hil_sensor.xmag;
        // qDebug() << "Magnetometer Y: " << hil_sensor.ymag;
        // qDebug() << "Magnetometer Z: " << hil_sensor.zmag;
        // qDebug() << "Abs_p: " << hil_sensor.abs_pressure;
        // qDebug() << "Diff_p: " << hil_sensor.diff_pressure;
        // qDebug() << "Alt_press: " << hil_sensor.pressure_alt;
        // qDebug() << "Temp: " << hil_sensor.temperature;

        break;
    }
    default:
        qDebug() << "Bilinmeyen mesaj türü: " << msg.msgid;
        break;
    }
}


void DataManager::sendMavlinkHeartBeat() {

    static mavlink_message_t heartBeatMessage;
    static uint8_t buffer[MAVLINK_MAX_PACKET_LEN];

    mavlink_msg_heartbeat_pack(1, 1, &heartBeatMessage, MAV_TYPE_QUADROTOR, MAV_AUTOPILOT_GENERIC, 0, 0, MAV_STATE_ACTIVE);
    mavlink_msg_to_send_buffer(buffer, &heartBeatMessage);

    QByteArray byteArray(reinterpret_cast<const char*>(buffer), sizeof(buffer));
    udp_comminication.sendData(byteArray, byteArray.length());

    //qDebug() << "Heartbeat gönderildi!";

    /* TEST */
    //sendMavlinkActuator();

    //serial_comminication.sendData(byteArray, byteArray.length());
}


void DataManager::sendMavlinkActuator() {

    static mavlink_message_t actuatorMessage;
    static uint8_t buffer[MAVLINK_MAX_PACKET_LEN];

    // Aktüatör kontrol değerleri
    static float controls[8] = {0.5f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f};

    // HIL actuator kontrol mesajı paketleme
    mavlink_msg_hil_actuator_controls_pack(1, 1, &actuatorMessage, 0, controls, 0, 0);
    mavlink_msg_to_send_buffer(buffer, &actuatorMessage);

    QByteArray byteArray(reinterpret_cast<const char*>(buffer), sizeof(buffer));
    udp_comminication.sendData(byteArray, byteArray.length());

    //qDebug() << "Actuator gönderildi!";
}


bool DataManager::startComminications() {

    QString port = serial_comminication.findSerialPortByManufacturer("Espressif");
    if (port != "") {

        serial_comminication.openSerialPort(port, 921600);

        // Saniyede 1 defa Heartbeat mesajı gönder
        heartbeat_timer->start(1000); // 1000 ms = 1 saniye
        return true;
    }
    return false;
}
