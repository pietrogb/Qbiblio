#ifndef CD_H
#define CD_H

#include <iostream>
//#include <QVector>
#include "libraryitem.h"

class CD : public LibraryItem
{
private:
    QString artista;
    int annoUscita;
    int nDischi;
public:
    CD();
    CD(QString, QString, QString, int, int);
    virtual ~CD();
    virtual CD* clone() const;
    virtual bool operator==(const CD&) const;
    virtual bool operator!=(const CD&) const;
    QString getArtista() const;
    int getAnnoUscita() const;
    int getDischi() const;
};

#endif // CD_H
