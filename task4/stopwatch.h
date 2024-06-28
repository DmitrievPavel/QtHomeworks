#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
public slots:
    void start();
    void stop();
    void reset();
    void round();
private slots:
    void update_time();
signals:
    void sig_time_updated(double time);
    void sig_round_updated(int round, double round_time);
private:
    QTimer* timer;
    double time = 0.0;
    int round_ = 0;
    double last_round_time = 0.0;
};

#endif // STOPWATCH_H
