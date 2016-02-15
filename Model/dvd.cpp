#include "dvd.h"

DVD::DVD(): Film() {}

DVD::DVD(QString t ="", QString g ="", QString r ="", int d =0, QDate u =QDate::currentDate()): Film(t, g, r, d, u) {}

DVD::~DVD() {}

DVD* DVD::clone() const {return new DVD(*this);}

bool DVD::operator==(const DVD& f) const{
    return Film::operator ==(f);
}

bool DVD::operator!=(const DVD& f) const{
    return !(Film::operator ==(f));
}

bool DVD::search(const QString & str) const{
    return Film::search(str);
}
