#include "libro.h"
/*
    QString autore;
    int annoUscita;
    QString Editore;*/
Libro::Libro(): LibraryItem(), autore(""), annoUscita(), editore("") {}

Libro::Libro(QString t ="", QString g ="", QString a ="", int u =0,  QString e =""): LibraryItem(t, g), autore(a), annoUscita(u), editore(e) {}

Libro::~Libro() {}

Libro* Libro::clone() const {return new Libro(*this);}

bool Libro::operator==(const Libro& l) const {
    return ( LibraryItem::operator ==(l) && autore == l.autore && annoUscita == l.annoUscita && editore == l.editore);
}

bool Libro::operator!=(const Libro& l) const {
    return !( LibraryItem::operator ==(l) && autore == l.autore && annoUscita == l.annoUscita && editore == l.editore);
}

QString Libro::getautore() const {return autore;}

int Libro::getannoUscita() const {return annoUscita;}

QString Libro::getEditore() const {return editore;}

