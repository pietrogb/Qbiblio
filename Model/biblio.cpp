#include "biblio.h"

Biblio::Biblio(const Container<LibraryItem*>& content): b(content){
    load();
}

Biblio::~Biblio(){
    for(Container<LibraryItem*>::Iterator it=b.begin(); it!=b.end()<; ++it)
        delete *it;
}

bool Biblio::IsEmpty() const{
    return b.isEmpty();
}

int Biblio::getSize() const{
    return b.size();
}

bool Biblio::addItem(LibraryItem* li){
    bool presente=false;
    for(Container<LibraryItem*>::const_Iterator it=b.begin(); !presente && it!=b.end(); ++it){
        if(*(*it) == *li)
            presente=true;
    }
    b.insert(li);
    return presente;
}

void Biblio::removeItem(const QString& title ){
    for(int i=0; i<b.size(); ++i){
        if((getItem(i) -> getTitolo() == title)) {
            delete getItem(i);
        }
    }
}

LibraryItem* Biblio::getItem(int n){
    Container<LibraryItem*>::Iterator it = b.begin();
    for(int i=0; i<n; ++i)
        it++;
    return *it;
}

LibraryItem* Biblio::findItem(const QString& title) const {

}

void Biblio::save() const;

void Biblio::load();

Container<LibraryItem*> Biblio::getLibrary() const;

//private:
//Container<LibraryItem*> b;
