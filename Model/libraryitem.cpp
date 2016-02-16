#include "libraryitem.h"

LibraryItem::LibraryItem(): titolo(""), genere("") {}

LibraryItem::LibraryItem(QString t ="", QString g =""): titolo(t), genere(g) {}

LibraryItem::~LibraryItem(){} //posso anche evitare di scriverlo, visto che è virtuale puro!

bool LibraryItem::operator ==(const LibraryItem& li) const{
    return (titolo == li.titolo && genere == li.genere);
}

bool LibraryItem::operator !=(const LibraryItem& li) const{
    return !(titolo == li.titolo && genere == li.genere);
}

QString LibraryItem::getTitolo() const{
    return titolo;
}

QString LibraryItem::getGenere() const{
    return genere;
}

bool LibraryItem::search(const QString & str) const {
    return ((titolo == str) || (genere == str));
}

