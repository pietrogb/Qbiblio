
#include <iostream>
#include "../Model/libraryitem.h"
#include "../Model/cd.h"
#include "../Model/dvd.h"
#include "../Model/vhs.h"
#include "../Model/libro.h"
#include "../Model/smartptr.h"
#include "../Model/biblio.h"
using namespace std;

int main(){
    LibraryItem* s=new CD("Il racconto dei racconti", "Avventura", "Potato", 0, 0);
    cout<<s->getTitolo()<<endl;
    LibraryItem* j=new DVD("Il racconto del gatto", "fantastico", "gatto", 0);
    DVD* d= dynamic_cast<DVD*>(j);
    cout<<d->getTitolo()<<d->getRegista();
    j=new Libro("C'era una volta in america");
    cout<<j->getTitolo();
    Container<LibraryItem*> bib;
    bib.insert(j);
    cout<<(*bib.begin())->getTitolo();
}
