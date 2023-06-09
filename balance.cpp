#include "balance.h"
#include <QDebug>

Balance::Balance()
{

}

QByteArray Balance::lirePoids(){
    qDebug() << "entrée dans la fonction lirePoids";
    //sleep(1);

    QByteArray data=getData();

    int size=data.size();
    //poidsChariot="";
    for (int i=0; i< size; i++)
    {
        if((data[i]>= '0' && data[i] <= '9' && data[0]!= 'W'))
            poidsChariot=poidsChariot+data[i];
     else if(data[i]==46)
            poidsChariot=poidsChariot+".";
    }

    data=poidsChariot.toUtf8();
    qDebug() << "valeur trame: " << poidsChariot;
    poidsChariot.clear();
    return data;
}
