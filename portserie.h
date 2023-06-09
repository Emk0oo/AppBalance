#ifndef PORTSERIE_H
#define PORTSERIE_H
#include <QSerialPort>
#include <QObject>
#include <unistd.h> //biblio pour la fonction sleep()

class PortSerie: public QObject
{
    Q_OBJECT
public:
    PortSerie();
    QSerialPort *serie;
    QByteArray data;
    void recevoir();
    bool isConnect();
    QByteArray getData();

private :
    int octet=0;
public slots:
    void on_data_serial();

signals:
    void data_receive();
};

#endif // PORTSERIE_H
