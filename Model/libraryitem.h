#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::ostream;
#include <QDate>

class LibraryItem
{
private:
  string titolo;
  string genere;

public:
  LibraryItem(string ="", string ="");
  virtual ~LibraryItem() =0;
  virtual LibraryItem* clone() const =0;
  virtual bool operator==(const LibraryItem&) const;
  virtual bool operator!=(const LibraryItem&) const;
  string getTitolo() const;
  string getGenere() const;
  virtual bool search(const string &) const;
};

#endif // LIBRARYITEM_H
