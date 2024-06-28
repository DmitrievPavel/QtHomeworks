#include "stopwatch.h"



Stopwatch::Stopwatch(QObject *parent) : QObject{parent}
{
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Stopwatch::update_time);
}

void Stopwatch::start()
{
    timer->start(100);
}

void Stopwatch::stop()
{
    timer->stop();
}

void Stopwatch::reset()
{
    time = 0.0;
    last_round_time = 0;
    round_ = 0;
    emit sig_time_updated(time);
    emit sig_round_updated(round_,last_round_time);
}

void Stopwatch::round()
{
    double round_time = time - last_round_time;
    round_++;
    emit sig_round_updated(round_,round_time);
    last_round_time = time;
}

void Stopwatch::update_time()
{
    time += 0.1;
    emit sig_time_updated(time);
}
