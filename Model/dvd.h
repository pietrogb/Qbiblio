#ifndef DVD_H
#define DVD_H

#include <string>
using std::string;
#include "film.h"

class DVD : public Film
{
public:
    DVD();
    DVD(string ="", string ="", string = "", int =0, QDate = QDate::currentDate());
    ~DVD();
    virtual DVD* clone() const;
    virtual bool operator==(const DVD&) const;
    virtual bool operator!=(const DVD&) const;
    bool search(const string &) const;
};

#endif // DVD_H
