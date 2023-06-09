#include "serveurtcp.h"
#include <iostream>
using namespace std;


ServeurTCP::ServeurTCP(QObject *parent) : QObject(parent)
{
    // ** CREATION SERVEUR TCP **
    server = new QTcpServer(this);
    socket2= new QTcpSocket(this);

    if (!server->listen(QHostAddress::Any, 1234)) {
        qDebug() << "Erreur: " << server->errorString();
        return;
    } qDebug() << "Serveur en écoute sur le port 1234...";

    connect(server, SIGNAL(newConnection()), this, SLOT(Connexion())); //** Permet d'envoyer un signal de connexion client sur le serveur TCP vers une méthode **


}

void ServeurTCP::Connexion()
{
    // Prend les connexions
    socket2 = server->nextPendingConnection();
    qDebug() << "Un client vient de se connecter: " << socket2->peerAddress().toString();

    connect(socket2, SIGNAL(disconnected()), this, SLOT(Deconnexion())); //** Permet d'envoyer un signal de deconnexion client sur le serveur TCP vers une méthode **


    connect(socket2, SIGNAL(readyRead()), this, SLOT(lireDoneesRecues()));//** Permet d'envoyer un signal de reception du client sur le serveur TCP vers une méthode **


}

void ServeurTCP::lireDoneesRecues(){
    qDebug()<<"Une donnée recue a ete detecte";
    dataTCP = socket2->readAll();
   //out << dataTCP << endl;
    // Echo data back to client
    emit dataTCP_receive();


}

QByteArray ServeurTCP::getDataTcp(){

        return dataTCP;
}
void ServeurTCP::Deconnexion(){
    // Gere la deconnexion

        qDebug() << "Client deconnecte: " << socket2->peerAddress().toString();
        socket2->deleteLater();
}

void ServeurTCP::envoyer(QByteArray data){
        qDebug()<< "Entrée fonction ServeurTCP::envoyer";

        socket2->write(data);
}
