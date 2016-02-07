#include "film.h"
/*
QString regista;
int durata; //minuti
QDate dataUscita;
QVector<QString> attori;*/
Film::Film(): LibraryItem(), regista(""), durata(0), dataUscita(), attori() {}
Film::Film(QString t, QString g, QString r, int d, QDate u, QVector<QString> a): LibraryItem(t, g), regista(r),
    durata(d), dataUscita(u), attori(a) {}

Film::~Film() {}

Film::Film* clone() const {return new Film(*this);};

Film::bool operator==(const Film&) const{

}
Film::bool operator!=(const Film&) const;
Film::QString getRegista() const;
Film::int getDurata() const;
Film::QDate getDataUscita() const;
Film::QVector<QString> getAttori;

Film::Film()
{
}
