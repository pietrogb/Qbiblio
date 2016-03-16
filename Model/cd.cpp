#include "cd.h"

// CD::CD(): LibraryItem(), artista(""), annoUscita(0), nDischi(0){}

CD::CD(string t, string g, string a, int u, int n): LibraryItem(t,g), artista(a), annoUscita(u), nDischi(n){}

CD::~CD() {}

CD* CD::clone() const {return new CD(*this);}

bool CD::operator==(const CD& c) const {
  return (LibraryItem::operator ==(c) && artista == c.artista && annoUscita==c.annoUscita && nDischi == c.nDischi);
}

bool CD::operator!=(const CD& c) const{
  return !(LibraryItem::operator ==(c) && artista == c.artista && annoUscita==c.annoUscita && nDischi == c.nDischi);
}

string CD::getArtista() const {return artista;}

int CD::getAnnoUscita() const {return annoUscita;}

int CD::getDischi() const {return nDischi;}

bool CD::search(const string& str)const{
  return (LibraryItem::search(str) || artista == str);
}
