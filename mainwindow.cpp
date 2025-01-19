#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QMessageBox>
#include <QTimer>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start_jmavsim()
{
    QString workingDir = "C:/jMAVSim";  // Çalışma dizini
    QString program = "cmd.exe";        // Command Prompt

    // Terminalde çalıştırılacak komut
    QStringList arguments = {"/k", "java -jar out/production/jmavsim_run.jar"};

    // QProcess ile terminal aç
    QProcess *process = new QProcess();
    process->setWorkingDirectory(workingDir); // Çalışma dizinini ayarla
    process->start(program, arguments);

    if (process->state() == QProcess::Running) {
        qDebug() << "jMAVSim Başlatılıyor...";
    } else {
        qDebug() << "Terminal başlatılamadı!";
    }
}

void MainWindow::on_startHitlPushButton_clicked()
{
    if (data_manager.startComminications()){
        start_jmavsim();
    } else {
        QMessageBox::warning(nullptr, "Uyarı", "Otopilot Bulunamadı!");
    }
}

