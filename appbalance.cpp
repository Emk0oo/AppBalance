#include "appbalance.h"
#include "ui_appbalance.h"
#include "balance.h"
#include <iostream>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <unistd.h> //sleep()


AppBalance::AppBalance(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AppBalance)
{
    ui->setupUi(this);
    ui->textEdit->setEnabled(false);

    if (maBalance->isConnect()==true)
    {
        ui->textEdit->setTextColor(Qt::green);
        ui->textEdit->setText("La connexion à la balance a réussi");
        ui->textEdit->setAlignment(Qt::AlignCenter);
    }
    else {
        ui->textEdit->setTextColor(Qt::red);
        ui->textEdit->setText("La connexion à la balance a échoué");
        ui->textEdit->setAlignment(Qt::AlignCenter);
    }

    connect(maBalance, SIGNAL(data_receive()), this, SLOT(envoyerTCP())); // ** Permet d'envoyer un signal, de réception du port serie, vers une méthode **
    connect(&monServeur,SIGNAL(dataTCP_receive()),this, SLOT(ordreDePesee()));// ** Permet d'envoyer un signal, d'un ordre de pesee, vers une méthode **
}

AppBalance::~AppBalance()
{
    delete ui;

}

void AppBalance::ordreDePesee(){
    idCde=monServeur.getDataTcp();
    QString idCdeConverti=QString(idCde);
    ui->labelOrdre->setText("Ordre de pesée reçu : veuillez réaliser la pesée pour la commande " + idCdeConverti + "\n Appuyez sur le bouton PRINT de la balance");
    nomQByte= idCdeConverti.toUtf8();
    idCde=" "+idCde;
    qDebug()<< idCde;
}

void AppBalance::envoyerTCP(){
    qDebug() << "AppBalance: Déclenchement envoyerTCP()";
    QByteArray data="";
    data=maBalance->lirePoids();
    ui->textEdit->setText("Poids envoyé : "+data+"g");
    QByteArray poidsMesure= data;
    monServeur.envoyer(poidsMesure);
    qDebug()<< "Poids envoyé= " << poidsMesure;
    qDebug()<< idCde;
    qDebug()<< data;

}
