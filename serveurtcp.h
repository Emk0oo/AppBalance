#ifndef SERVEURTCP_H
#define SERVEURTCP_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>

class ServeurTCP: public QObject
{
    Q_OBJECT
public:
    ServeurTCP(QObject *parent = nullptr);
    void envoyer(QByteArray data);
    QByteArray getDataTcp();
private:
    QTcpServer* server;
    QTcpSocket* socket;
    QTcpSocket* socket2;
    QByteArray dataTCP;

public slots:
    void Connexion();
    void lireDoneesRecues();
    void Deconnexion();

signals:
    void dataTCP_receive();

};

#endif // SERVEURTCP_H
