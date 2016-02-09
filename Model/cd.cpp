#include "cd.h"

CD::CD(): LibraryItem(), artista(""), annoUscita(0), nDischi(0){}

CD::CD(QString t ="", QString g="", QString a="", int u =0, int n =0): LibraryItem(t,g), artista(a), annoUscita(u), nDischi(n){}

CD::~CD() {}

CD* CD::clone() const {return new CD(*this);}

bool CD::operator==(const CD& c) const {
    return (LibraryItem::operator ==(c) && artista == c.artista && annoUscita==c.annoUscita && nDischi == c.nDischi);
}

bool CD::operator!=(const CD& c) const{
    return !(LibraryItem::operator ==(c) && artista == c.artista && annoUscita==c.annoUscita && nDischi == c.nDischi);
}

QString CD::getArtista() const {return artista;}

int CD::getAnnoUscita() const {return annoUscita;}

int CD::getDischi() const {return nDischi;}
