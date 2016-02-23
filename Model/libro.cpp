#include "libro.h"

// Libro::Libro(): LibraryItem(), autore(""), annoUscita(), editore("") {}

Libro::Libro(string t, string g, string a, int u,  string e): LibraryItem(t, g), autore(a), annoUscita(u), editore(e) {}

Libro::~Libro() {}

Libro* Libro::clone() const {return new Libro(*this);}

bool Libro::operator==(const Libro& l) const {
    return ( LibraryItem::operator ==(l) && autore == l.autore && annoUscita == l.annoUscita && editore == l.editore);
}

bool Libro::operator!=(const Libro& l) const {
    return !( LibraryItem::operator ==(l) && autore == l.autore && annoUscita == l.annoUscita && editore == l.editore);
}

string Libro::getAutore() const {return autore;}

int Libro::getAnnoUscita() const {return annoUscita;}

string Libro::getEditore() const {return editore;}

bool Libro::search(const string & str) const{
    return (LibraryItem::search(str) || autore == str);
}
