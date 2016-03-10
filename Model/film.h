#ifndef FILM_H
#define FILM_H

#include "libraryitem.h"
#include <QTime>
#include <QDate>
#include <string>
using std::string;

class Film : public LibraryItem{
private:
    string regista;
    int durata; //minuti
    QDate dataUscita;
public:
    // Film();
    Film(string ="", string ="", string ="", int =0, QDate = QDate::currentDate() );
    virtual ~Film();
    virtual Film* clone() const;
    virtual bool operator==(const Film&) const;
    virtual bool operator!=(const Film&) const;
    string getRegista() const;
    int getDurata() const;
    QDate getDataUscita() const;
    bool search(const string &) const;


    //Film(string, string, string, int, QDate, QVector<string>);
    //QVector<string> getAttori() const;
};

#endif // FILM_H
