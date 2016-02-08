#include "film.h"

Film::Film(): LibraryItem(), regista(""), durata(0), dataUscita() {}

Film::Film(QString t ="", QString g ="", QString r ="", int d =0, QDate u =new QDate()): LibraryItem(t, g), regista(r), durata(d), dataUscita(u){}

Film::~Film() {}

Film::Film* clone() const {return new Film(*this);};

bool Film::operator==(const Film& f) const{
    return (LibraryItem::operator ==(f) && regista==f.regista && durata == f.durata && dataUscita==f.dataUscita);
}

bool Film::operator!=(const Film& f) const{
    return !(LibraryItem::operator ==(f) && regista==f.regista && durata == f.durata && dataUscita==f.dataUscita);
}

QString Film::getRegista() const{ return regista;}

int Film::getDurata() const {return durata;}

QDate Film::getDataUscita() const {return dataUscita;}


//Film::Film(): LibraryItem(), regista(""), durata(0), dataUscita(), attori() {}
//Film::Film(QString t, QString g, QString r, int d, QDate u, QVector<QString> a): LibraryItem(t, g), regista(r), durata(d), dataUscita(u), attori(a) {}
//Film::QVector<QString> getAttori() const;

