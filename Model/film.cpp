#include "film.h"

//Film::Film(): LibraryItem(), regista(""), durata(0), dataUscita() {}

Film::Film(string t, string g, string r, int d, QDate u): LibraryItem(t, g), regista(r), durata(d), dataUscita(u){}

Film::~Film() {}

Film* Film::clone() const {return new Film(*this);};

bool Film::operator==(const Film& f) const{
  return (LibraryItem::operator ==(f) && regista==f.regista && durata == f.durata && dataUscita==f.dataUscita);
}

bool Film::operator!=(const Film& f) const{
  return !(LibraryItem::operator ==(f) && regista==f.regista && durata == f.durata && dataUscita==f.dataUscita);
}

string Film::getRegista() const{ return regista;}

int Film::getDurata() const {return durata;}

QDate Film::getDataUscita() const {return dataUscita;}

bool Film::search(const string & str) const{
  return (LibraryItem::search(str) || regista == str);
}
