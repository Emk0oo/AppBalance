#ifndef BALANCE_H
#define BALANCE_H
#include "portserie.h"

class Balance: public PortSerie
{
public:
    Balance();
    QByteArray lirePoids();
private:

    QString poidsChariot;

};

#endif // BALANCE_H
