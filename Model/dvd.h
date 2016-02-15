#ifndef DVD_H
#define DVD_H

#include "film.h"

class DVD : public Film
{
public:
    DVD();
    DVD(QString, QString, QString, int, QDate);
    ~DVD();
    virtual DVD* clone() const;
    virtual bool operator==(const DVD&) const;
    virtual bool operator!=(const DVD&) const;
};

#endif // DVD_H
