#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stopwatch = new Stopwatch(this);
    connect(ui->pb_start_stop,&QPushButton::clicked,this,&MainWindow::start_stop_clicked);
    connect(stopwatch,&Stopwatch::sig_time_updated,this,&MainWindow::time_updated);
    connect(stopwatch,&Stopwatch::sig_round_updated,this,&MainWindow::time_round_updated);
    connect(ui->pb_round,&QPushButton::clicked,this,&MainWindow::round_clicked);
    ui->pb_round->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start_stop_clicked()
{
    if(!is_running){
        stopwatch->start();
        ui->pb_start_stop->setText("Стоп");
        ui->pb_round->setEnabled(true);
    }else {
        stopwatch->stop();
        ui->pb_start_stop->setText("Старт");
        ui->pb_round->setEnabled(false);
    }
    is_running = !is_running;
}



void MainWindow::round_clicked()
{
    stopwatch->round();
}

void MainWindow::time_updated(double time)
{
    ui->lb_time->setText(QString("%1").arg(time));
}

void MainWindow::time_round_updated(int round, double round_time)
{
    ui->tb_round_time->append(QString("Круг '%1' Время '%2'").arg(round).arg(round_time));
}


void MainWindow::on_pb_clear_clicked()
{
    stopwatch->reset();
    ui->lb_time->clear();
    ui->tb_round_time->clear();
    if(!is_running){
        ui->lb_time->setText("Время");
    }
}

