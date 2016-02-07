#include "libraryitem.h"

LibraryItem::LibraryItem(): titolo(""), autore(""), annoCreazione(0) {}

LibraryItem::LibraryItem(QString t ="", QString au ="", int a =0): titolo(t), autore(au), anno(a) {}

LibraryItem::~LibraryItem(){} //posso anche evitare di scriverlo, visto che è virtuale puro!

bool LibraryItem::operator ==(const LibraryItem& li) const{
    return (titolo == li.titolo && autore == li.autore && annoCreazione == li.annoCreazione);
}

bool LibraryItem::operator !=(const LibraryItem& li) const{
    return !(titolo == li.titolo && autore == li.autore && annoCreazione == li.annoCreazione);
}

QString LibraryItem::getTitolo() const{
    return titolo;
}

QString LibraryItem::getAutore() const{
    return autore;
}

int LibraryItem::getAnno() const{
    return annoCreazione;
}



