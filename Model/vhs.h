#ifndef VHS_H
#define VHS_H

#include "film.h"

class VHS : public Film
{
public:
    VHS();
    VHS(QString, QString, QString, int, QDate);
    ~VHS();
    virtual VHS* clone() const;
    virtual bool operator==(const VHS&) const;
    virtual bool operator!=(const VHS&) const;
    bool search(const QString &) const;
};

#endif // VHS_H
