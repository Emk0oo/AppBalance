#ifndef APPBALANCE_H
#define APPBALANCE_H
#include "balance.h"
#include "serveurtcp.h"
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
//#include <QAppBalance>

QT_BEGIN_NAMESPACE
namespace Ui { class AppBalance; }
QT_END_NAMESPACE

class AppBalance : public QMainWindow
{
    Q_OBJECT

public:
    AppBalance(QWidget *parent = nullptr);
    ~AppBalance();
private:
    Ui::AppBalance *ui;
    Balance *maBalance=new Balance();
    ServeurTCP monServeur;
    QString idCdeConverti;
    QByteArray nomQByte;
    QByteArray idCde;

public slots:
    void envoyerTCP();
    void ordreDePesee();

};
#endif // APPBALANCE_H
