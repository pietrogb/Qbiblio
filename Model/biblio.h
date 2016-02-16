#ifndef BIBLIO_H
#define BIBLIO_H

#include<iostream>

#include"QFile"
#include"QXmlStreamReader"
#include"QXmlStreamWriter"
#include"QStringList"
#include"QFileDialog"
#include"QMessageBox"
#include"QDomDocument"

#include "../Model/container.h"
#include "../Model/smartptr.h"
#include "../Model/libraryitem.h"
#include "../Model/cd.h"
#include "../Model/dvd.h"
#include "../Model/film.h"
#include "../Model/libro.h"
#include "../Model/vhs.h"

class Biblio
{
public:
    Biblio(const Container<LibraryItem*>& = Container<LibraryItem*>());

    ~Biblio();

    bool IsEmpty() const;

    int getSize() const;

    bool addItem(LibraryItem*); //SmartPtr?

    void removeItem(const QString&);

    LibraryItem* getItem(int);

    Container<LibraryItem*> findItem(const QString&) const;

    void save() const;

    void load();

    Container<LibraryItem*> getLibrary() const;

private:
    Container<LibraryItem*> b;
};

#endif // BIBLIO_H
