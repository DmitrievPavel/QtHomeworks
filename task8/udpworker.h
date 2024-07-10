#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT 12345

class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocket( void );
    void ReadDatagram( QNetworkDatagram datagram);
    void ReadUserDatagram( QNetworkDatagram datagram);
    void SendDatagram(QByteArray data );
    void SendUserDatagram(QByteArray data);

private slots:
    void readPendingDatagrams(void);
    void readUserDatagrams(void);

private:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket* secondUdpSocket;

signals:
    void sig_sendTimeToGUI(QDateTime data);
    void sig_sendDatagramInfo(QString adress, qint64 size);

};

#endif // UDPWORKER_H
