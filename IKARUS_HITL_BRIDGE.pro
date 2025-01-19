QT       += core gui
QT       += serialport
QT       += core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data_manager.cpp \
    main.cpp \
    mainwindow.cpp \
    serial_comminication.cpp \
    udp_comminication.cpp

HEADERS += \
    Mavlink/checksum.h \
    Mavlink/common/common.h \
    Mavlink/common/mavlink.h \
    Mavlink/common/mavlink_msg_actuator_control_target.h \
    Mavlink/common/mavlink_msg_adsb_vehicle.h \
    Mavlink/common/mavlink_msg_altitude.h \
    Mavlink/common/mavlink_msg_att_pos_mocap.h \
    Mavlink/common/mavlink_msg_attitude.h \
    Mavlink/common/mavlink_msg_attitude_quaternion.h \
    Mavlink/common/mavlink_msg_attitude_quaternion_cov.h \
    Mavlink/common/mavlink_msg_attitude_target.h \
    Mavlink/common/mavlink_msg_auth_key.h \
    Mavlink/common/mavlink_msg_autopilot_version.h \
    Mavlink/common/mavlink_msg_battery_status.h \
    Mavlink/common/mavlink_msg_camera_trigger.h \
    Mavlink/common/mavlink_msg_change_operator_control.h \
    Mavlink/common/mavlink_msg_change_operator_control_ack.h \
    Mavlink/common/mavlink_msg_collision.h \
    Mavlink/common/mavlink_msg_command_ack.h \
    Mavlink/common/mavlink_msg_command_cancel.h \
    Mavlink/common/mavlink_msg_command_int.h \
    Mavlink/common/mavlink_msg_command_long.h \
    Mavlink/common/mavlink_msg_control_system_state.h \
    Mavlink/common/mavlink_msg_data_stream.h \
    Mavlink/common/mavlink_msg_data_transmission_handshake.h \
    Mavlink/common/mavlink_msg_debug.h \
    Mavlink/common/mavlink_msg_debug_vect.h \
    Mavlink/common/mavlink_msg_distance_sensor.h \
    Mavlink/common/mavlink_msg_efi_status.h \
    Mavlink/common/mavlink_msg_encapsulated_data.h \
    Mavlink/common/mavlink_msg_estimator_status.h \
    Mavlink/common/mavlink_msg_extended_sys_state.h \
    Mavlink/common/mavlink_msg_fence_status.h \
    Mavlink/common/mavlink_msg_file_transfer_protocol.h \
    Mavlink/common/mavlink_msg_follow_target.h \
    Mavlink/common/mavlink_msg_global_position_int.h \
    Mavlink/common/mavlink_msg_global_position_int_cov.h \
    Mavlink/common/mavlink_msg_global_vision_position_estimate.h \
    Mavlink/common/mavlink_msg_gps2_raw.h \
    Mavlink/common/mavlink_msg_gps2_rtk.h \
    Mavlink/common/mavlink_msg_gps_global_origin.h \
    Mavlink/common/mavlink_msg_gps_inject_data.h \
    Mavlink/common/mavlink_msg_gps_input.h \
    Mavlink/common/mavlink_msg_gps_raw_int.h \
    Mavlink/common/mavlink_msg_gps_rtcm_data.h \
    Mavlink/common/mavlink_msg_gps_rtk.h \
    Mavlink/common/mavlink_msg_gps_status.h \
    Mavlink/common/mavlink_msg_high_latency.h \
    Mavlink/common/mavlink_msg_high_latency2.h \
    Mavlink/common/mavlink_msg_highres_imu.h \
    Mavlink/common/mavlink_msg_hil_actuator_controls.h \
    Mavlink/common/mavlink_msg_hil_controls.h \
    Mavlink/common/mavlink_msg_hil_gps.h \
    Mavlink/common/mavlink_msg_hil_optical_flow.h \
    Mavlink/common/mavlink_msg_hil_rc_inputs_raw.h \
    Mavlink/common/mavlink_msg_hil_sensor.h \
    Mavlink/common/mavlink_msg_hil_state.h \
    Mavlink/common/mavlink_msg_hil_state_quaternion.h \
    Mavlink/common/mavlink_msg_home_position.h \
    Mavlink/common/mavlink_msg_landing_target.h \
    Mavlink/common/mavlink_msg_link_node_status.h \
    Mavlink/common/mavlink_msg_local_position_ned.h \
    Mavlink/common/mavlink_msg_local_position_ned_cov.h \
    Mavlink/common/mavlink_msg_local_position_ned_system_global_offset.h \
    Mavlink/common/mavlink_msg_log_data.h \
    Mavlink/common/mavlink_msg_log_entry.h \
    Mavlink/common/mavlink_msg_log_erase.h \
    Mavlink/common/mavlink_msg_log_request_data.h \
    Mavlink/common/mavlink_msg_log_request_end.h \
    Mavlink/common/mavlink_msg_log_request_list.h \
    Mavlink/common/mavlink_msg_mag_cal_report.h \
    Mavlink/common/mavlink_msg_manual_control.h \
    Mavlink/common/mavlink_msg_manual_setpoint.h \
    Mavlink/common/mavlink_msg_memory_vect.h \
    Mavlink/common/mavlink_msg_message_interval.h \
    Mavlink/common/mavlink_msg_mission_ack.h \
    Mavlink/common/mavlink_msg_mission_clear_all.h \
    Mavlink/common/mavlink_msg_mission_count.h \
    Mavlink/common/mavlink_msg_mission_current.h \
    Mavlink/common/mavlink_msg_mission_item.h \
    Mavlink/common/mavlink_msg_mission_item_int.h \
    Mavlink/common/mavlink_msg_mission_item_reached.h \
    Mavlink/common/mavlink_msg_mission_request.h \
    Mavlink/common/mavlink_msg_mission_request_int.h \
    Mavlink/common/mavlink_msg_mission_request_list.h \
    Mavlink/common/mavlink_msg_mission_request_partial_list.h \
    Mavlink/common/mavlink_msg_mission_set_current.h \
    Mavlink/common/mavlink_msg_mission_write_partial_list.h \
    Mavlink/common/mavlink_msg_named_value_float.h \
    Mavlink/common/mavlink_msg_named_value_int.h \
    Mavlink/common/mavlink_msg_nav_controller_output.h \
    Mavlink/common/mavlink_msg_optical_flow.h \
    Mavlink/common/mavlink_msg_optical_flow_rad.h \
    Mavlink/common/mavlink_msg_param_map_rc.h \
    Mavlink/common/mavlink_msg_param_request_list.h \
    Mavlink/common/mavlink_msg_param_request_read.h \
    Mavlink/common/mavlink_msg_param_set.h \
    Mavlink/common/mavlink_msg_param_value.h \
    Mavlink/common/mavlink_msg_ping.h \
    Mavlink/common/mavlink_msg_position_target_global_int.h \
    Mavlink/common/mavlink_msg_position_target_local_ned.h \
    Mavlink/common/mavlink_msg_power_status.h \
    Mavlink/common/mavlink_msg_radio_status.h \
    Mavlink/common/mavlink_msg_raw_imu.h \
    Mavlink/common/mavlink_msg_raw_pressure.h \
    Mavlink/common/mavlink_msg_rc_channels.h \
    Mavlink/common/mavlink_msg_rc_channels_override.h \
    Mavlink/common/mavlink_msg_rc_channels_raw.h \
    Mavlink/common/mavlink_msg_rc_channels_scaled.h \
    Mavlink/common/mavlink_msg_request_data_stream.h \
    Mavlink/common/mavlink_msg_resource_request.h \
    Mavlink/common/mavlink_msg_safety_allowed_area.h \
    Mavlink/common/mavlink_msg_safety_set_allowed_area.h \
    Mavlink/common/mavlink_msg_scaled_imu.h \
    Mavlink/common/mavlink_msg_scaled_imu2.h \
    Mavlink/common/mavlink_msg_scaled_imu3.h \
    Mavlink/common/mavlink_msg_scaled_pressure.h \
    Mavlink/common/mavlink_msg_scaled_pressure2.h \
    Mavlink/common/mavlink_msg_scaled_pressure3.h \
    Mavlink/common/mavlink_msg_serial_control.h \
    Mavlink/common/mavlink_msg_servo_output_raw.h \
    Mavlink/common/mavlink_msg_set_actuator_control_target.h \
    Mavlink/common/mavlink_msg_set_attitude_target.h \
    Mavlink/common/mavlink_msg_set_gps_global_origin.h \
    Mavlink/common/mavlink_msg_set_home_position.h \
    Mavlink/common/mavlink_msg_set_mode.h \
    Mavlink/common/mavlink_msg_set_position_target_global_int.h \
    Mavlink/common/mavlink_msg_set_position_target_local_ned.h \
    Mavlink/common/mavlink_msg_sim_state.h \
    Mavlink/common/mavlink_msg_statustext.h \
    Mavlink/common/mavlink_msg_sys_status.h \
    Mavlink/common/mavlink_msg_system_time.h \
    Mavlink/common/mavlink_msg_terrain_check.h \
    Mavlink/common/mavlink_msg_terrain_data.h \
    Mavlink/common/mavlink_msg_terrain_report.h \
    Mavlink/common/mavlink_msg_terrain_request.h \
    Mavlink/common/mavlink_msg_timesync.h \
    Mavlink/common/mavlink_msg_v2_extension.h \
    Mavlink/common/mavlink_msg_vfr_hud.h \
    Mavlink/common/mavlink_msg_vibration.h \
    Mavlink/common/mavlink_msg_vicon_position_estimate.h \
    Mavlink/common/mavlink_msg_vision_position_estimate.h \
    Mavlink/common/mavlink_msg_vision_speed_estimate.h \
    Mavlink/common/mavlink_msg_wind_cov.h \
    Mavlink/common/testsuite.h \
    Mavlink/common/version.h \
    Mavlink/mavlink_conversions.h \
    Mavlink/mavlink_helpers.h \
    Mavlink/mavlink_types.h \
    Mavlink/minimal/mavlink.h \
    Mavlink/minimal/mavlink_msg_heartbeat.h \
    Mavlink/minimal/minimal.h \
    Mavlink/minimal/testsuite.h \
    Mavlink/minimal/version.h \
    Mavlink/protocol.h \
    Mavlink/standard/mavlink.h \
    Mavlink/standard/standard.h \
    Mavlink/standard/testsuite.h \
    Mavlink/standard/version.h \
    data_manager.h \
    mainwindow.h \
    serial_comminication.h \
    udp_comminication.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += $$[QT_INSTALL_HEADERS]/QtSerialPort

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
