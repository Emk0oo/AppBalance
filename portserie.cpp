#include "portserie.h"
#include <iostream>
#include <QDebug>
using namespace std;

//#define PORT "/dev/ttyUSB0"
//#define PORT "/dev/ttyUSB1"

PortSerie::PortSerie()
{
    const QString PORT= "/dev/ttyUSB0"; //chemin vers le port série !!!!!
    serie= new QSerialPort(PORT);

    //configuration de la liaison
    serie->setBaudRate(QSerialPort::Baud9600);
    serie->setDataBits(QSerialPort::Data8);
    serie->setParity(QSerialPort::NoParity);
    serie->setStopBits(QSerialPort::OneStop);
    serie->setFlowControl(QSerialPort::NoFlowControl);
    serie->open(QIODevice::ReadWrite);

    connect(serie, SIGNAL(readyRead()), this, SLOT(on_data_serial()));
}

void PortSerie::on_data_serial(){
    sleep(1);
    emit data_receive();
    qDebug()<< "emit envoyé";
    }


bool PortSerie::isConnect(){
    if (serie->isOpen()==true){
        return true;
    }
    else return false;
}

QByteArray PortSerie::getData(){
    data = serie->readAll();
    return data;
}
