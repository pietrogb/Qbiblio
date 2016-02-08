#include "vhs.h"

VHS::VHS(): Film() {}

VHS::VHS(QString t ="", QString g ="", QString r ="", int d =0, QDate u =new QDate()): Film(t, g, r,d,u){}

VHS::~VHS() {}

VHS::VHS* clone() const {return new VHS(*this);}

bool VHS::operator==(const VHS& f) const{
    return Film::operator ==(f);
}

bool VHS::operator!=(const VHS& f) const{
    return !(Film::operator ==(f));
}
