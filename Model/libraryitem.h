#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <iostream>
#include <QString>

class LibraryItem
{
private:
    QString titolo;
    QString genere;
public:
    LibraryItem();
    LibraryItem(QString, QString);
    virtual ~LibraryItem();
    virtual LibraryItem* clone() const =0;
    virtual bool operator==(const LibraryItem&) const;
    virtual bool operator!=(const LibraryItem&) const;
    QString getTitolo() const;
    int getGenere() const;
};

#endif // LIBRARYITEM_H
