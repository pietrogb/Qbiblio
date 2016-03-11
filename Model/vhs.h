#ifndef VHS_H
#define VHS_H

#include "film.h"
#include <string>
using std::string;

class VHS : public Film
{
public:
  VHS();
  VHS(string ="", string ="", string = "", int =0, QDate = QDate::currentDate());
  ~VHS();
  virtual VHS* clone() const;
  virtual bool operator==(const VHS&) const;
  virtual bool operator!=(const VHS&) const;
  bool search(const string &) const;
};

#endif // VHS_H
