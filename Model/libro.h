#ifndef LIBRO_H
#define LIBRO_H
/*
– Un autore, memorizzato tramite un QString;
– Un anno di uscita, memorizzato tramite un intero;
– Un Editore, memorizzato tramite un QString.
*/

#include "libraryitem.h"
#include <QString>

class Libro : public LibraryItem
{
private:
    QString autore;
    int annoUscita;
    QString editore;
public:
    Libro();
    Libro(QString, QString, QString, int, QString);
    ~Libro();
    virtual Libro* clone() const;
    virtual bool operator==(const Libro&) const;
    virtual bool operator!=(const Libro&) const;
    QString getAutore() const;
    int getAnnoUscita() const;
    QString getEditore() const;
    bool search(const QString &) const;
};

#endif // LIBRO_H
