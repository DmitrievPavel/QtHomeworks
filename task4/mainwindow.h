#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void start_stop_clicked();
    void round_clicked();
private slots:
    void time_updated(double time);
    void time_round_updated(int round,double round_time);
    void on_pb_clear_clicked();

private:
    Ui::MainWindow *ui;
    Stopwatch* stopwatch;
    bool is_running = false;

};
#endif // MAINWINDOW_H
