#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <serial_comminication.h>
#include <udp_comminication.h>
#include <data_manager.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void start_jmavsim();

    void on_startHitlPushButton_clicked();

private:
    Ui::MainWindow *ui;

    DataManager data_manager;
};
#endif // MAINWINDOW_H
