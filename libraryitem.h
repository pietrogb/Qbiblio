#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <iostream>

#include <QString>

class LibraryItem
{
private:
    QString titolo;
    QString autore;
    int annoCreazione;
public:
    LibraryItem();
    LibraryItem(QString, QString, int);
    virtual ~LibraryItem();
    virtual LibraryItem* clone() const =0;
    virtual bool operator==(const LibraryItem&) const;
    virtual bool operator!=(const LibraryItem&) const;
    QString getTitolo() const;
    QString getAutore() const;
    int getAnno() const;
};

#endif // LIBRARYITEM_H
