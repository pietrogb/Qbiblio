#include "dvd.h"

DVD::DVD(): Film() {}

DVD::DVD(string t, string g, string r, int d, QDate u): Film(t, g, r, d, u) {}

DVD::~DVD() {}

DVD* DVD::clone() const {return new DVD(*this);}

bool DVD::operator==(const DVD& f) const{
  return Film::operator ==(f);
}

bool DVD::operator!=(const DVD& f) const{
  return !(Film::operator ==(f));
}

bool DVD::search(const string & str) const{
  return Film::search(str);
}
