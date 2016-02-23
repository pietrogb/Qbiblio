#ifndef CD_H
#define CD_H


#include "libraryitem.h"
#include <string>
using std::string;

class CD : public LibraryItem
{
private:
    string artista;
    int annoUscita;
    int nDischi;
public:
    // CD();
    CD(string ="", string = "", string = "", int =0, int =0);
    ~CD();
    virtual CD* clone() const;
    virtual bool operator==(const CD&) const;
    virtual bool operator!=(const CD&) const;
    string getArtista() const;
    int getAnnoUscita() const;
    int getDischi() const;
    bool search(const string &) const;
};

#endif // CD_H
