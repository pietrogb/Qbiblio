#include "libraryitem.h"

// LibraryItem::LibraryItem(): titolo(""), genere("") {}

LibraryItem::LibraryItem(string t, string g): titolo(t), genere(g) {}

LibraryItem::~LibraryItem(){} //posso anche evitare di scriverlo, visto che è virtuale puro!

bool LibraryItem::operator ==(const LibraryItem& li) const{
    return (titolo == li.titolo && genere == li.genere);
}

bool LibraryItem::operator !=(const LibraryItem& li) const{
    return !(titolo == li.titolo && genere == li.genere);
}

string LibraryItem::getTitolo() const{
    return titolo;
}

string LibraryItem::getGenere() const{
    return genere;
}

bool LibraryItem::search(const string & str) const {
    return ((titolo == str) || (genere == str));
}

