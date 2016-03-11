#include "vhs.h"

VHS::VHS(): Film() {}

VHS::VHS(string t, string g, string r, int d, QDate u): Film(t, g, r, d, u) {}

VHS::~VHS() {}

VHS* VHS::clone() const {return new VHS(*this);}

bool VHS::operator==(const VHS& f) const{
  return Film::operator ==(f);
}

bool VHS::operator!=(const VHS& f) const{
  return !(Film::operator ==(f));
}

bool VHS::search(const string & str) const{
  return Film::search(str);
}
