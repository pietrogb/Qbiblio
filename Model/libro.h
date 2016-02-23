#ifndef LIBRO_H
#define LIBRO_H
/*
– Un autore, memorizzato tramite un string;
– Un anno di uscita, memorizzato tramite un intero;
– Un Editore, memorizzato tramite un string.
*/

#include "libraryitem.h"
#include <string>
using std::string;

class Libro : public LibraryItem
{
private:
    string autore;
    int annoUscita;
    string editore;
public:
    // Libro();
    Libro(string ="", string ="", string ="", int =0, string ="");
    ~Libro();
    virtual Libro* clone() const;
    virtual bool operator==(const Libro&) const;
    virtual bool operator!=(const Libro&) const;
    string getAutore() const;
    int getAnnoUscita() const;
    string getEditore() const;
    bool search(const string &) const;
};

#endif // LIBRO_H
