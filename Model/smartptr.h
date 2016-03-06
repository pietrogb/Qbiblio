#ifndef SMARTPTR_H
#define SMARTPTR_H

#include "libraryitem.h"
#include <iostream>
#include <QString>

class SmartPtr {
private:
  LibraryItem* li;
public:
  SmartPtr();
  SmartPtr(LibraryItem*);
  SmartPtr(const SmartPtr&);
  SmartPtr& operator=(const SmartPtr&);
  ~SmartPtr();
  bool operator==(const SmartPtr&) const;
  bool operator!=(const SmartPtr&) const;
  LibraryItem* operator->() const;
  LibraryItem& operator*() const;
  LibraryItem* getItem();
  LibraryItem* getItem() const;
};

#endif
