#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
using std::cout; using std::endl; using std::ostream;

template<class T> class Container;

template<class T>
ostream& operator<<(ostream&, const Container<T>&);

template<class T>
class Container {
  friend class iterator;
  //friend ostream& operator<<(ostream&, const Container<T>&);
  friend ostream& operator<< <T>(ostream&, const Container<T>&);
private:
  class ContainerItem {
    public:
    T info;
    ContainerItem* next;
    ContainerItem();
    ContainerItem(const T&, ContainerItem*);
    bool operator==(const ContainerItem&) const;
    bool operator!=(const ContainerItem&) const;
  };
  ContainerItem* first;
  static ContainerItem* deepCopy(const ContainerItem*);
  static void deepRemove(ContainerItem*);
  static bool equals(const ContainerItem*, const ContainerItem*);
  static void printContainer(ostream&, const ContainerItem*);
public:
  class iterator {
    friend class Container<T>;
    private:
    Container<T>::ContainerItem* ptr;
    public:
      bool operator==(iterator) const;
      bool operator!=(iterator) const;
      iterator& operator++();
      iterator operator++(int);
    T operator*() const;
  };
  iterator begin() const;
  iterator end() const;
  T& operator[](iterator);
  Container();
  Container(const Container<T>&);
  Container<T>& operator=(const Container<T>&);
  ~Container();
  bool isEmpty() const;
  void insert(const T&);
  void remove(T);
  int size() const;
  Container<T> search(const T&) const;
  void replace(const T&, const T&);
  bool operator==(const Container&) const;
  bool operator!=(const Container&) const;
};

template<class T>
Container<T>::ContainerItem::ContainerItem() : info(0), next(0) {}

template<class T>
Container<T>::ContainerItem::ContainerItem(const T& ci, ContainerItem* n=0) : info(ci), next(n) {}

template<class T>
bool Container<T>::ContainerItem::operator==(const ContainerItem& cti) const {
  return (info == cti->info);
}

template<class T>
bool Container<T>::ContainerItem::operator!=(const ContainerItem& cti) const {
  return (info != cti->info);
}

template<class T>
bool Container<T>::iterator::operator==(iterator it) const {
  return ptr == it.ptr;
}

template<class T>
bool Container<T>::iterator::operator!=(iterator it) const {
  return ptr != it.ptr;
}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator++() {
  if(ptr)
    ptr = ptr->next;
  return *this;
}

template<class T>
typename Container<T>::iterator Container<T>::iterator::operator++(int) {
  iterator aux = *this;
  if(ptr)
    ptr = ptr->next;
  return aux;
}

template<class T>
T Container<T>::iterator::operator*() const {
  return (*ptr).info;
}

template<class T>
typename Container<T>::iterator Container<T>::begin() const {
  iterator aux;
  aux.ptr = first;
  return aux;
}

template<class T>
typename Container<T>::iterator Container<T>::end() const {
  iterator aux;
  aux.ptr = 0;
  return aux;
}

template<class T>
T& Container<T>::operator[](Container<T>::iterator it) {
  return (it.ptr)->info;
}

template<class T>
Container<T>::Container() : first(0) {}

template<class T>
Container<T>::Container(const Container<T>& cnt) : first(deepCopy(cnt.first)) { }

template<class T>
Container<T>& Container<T>::operator=(const Container<T>& cnt) {
  if(this != &cnt){
    deepRemove(first);
    first = deepCopy(cnt.first);
  }
  return *this;
}

template<class T>
Container<T>::~Container() {
  deepRemove(first);
}

template<class T>
typename Container<T>::ContainerItem* Container<T>::deepCopy(const ContainerItem* ci) {
  if(!ci)
    return 0;
  else
    return new ContainerItem(ci->info, deepCopy(ci->next));
}

template<class T>
void Container<T>::deepRemove(ContainerItem* ci) {
  if(ci){
    deepRemove(ci->next);
    delete ci;
  }
}

template<class T>
bool Container<T>::equals(const ContainerItem* a, const ContainerItem* b) {
  if(a == 0 && b == 0) return true;
  if(a == 0 || b == 0) return false;
  return a->info == b->info && equals(a->next, b->next);
}

template<class T>
void Container<T>::printContainer(ostream& os, const ContainerItem* cti) {
  if(cti){
    os << cti->info;
    printContainer(os, cti->next);
  }
}

template<class T>
bool Container<T>::isEmpty() const {
  return (first == 0);
}

template<class T>
void Container<T>::insert(const T& value) {
  first = new ContainerItem(value, first);
}

template<class T>
void Container<T>::remove(T value) {
  ContainerItem* p = first;
  ContainerItem* prec = 0;
  while(p && (p->info != value)){
    prec = p;
    p = p->next;
  }
  if(p){
    if(!prec)
      first = p->next;
    else
      prec->next = p->next;
  }
  delete p;
}

template<class T>
Container<T> Container<T>::search(const T& item) const {
  Container<T> temp;
  for(Container<T>::iterator it = begin(); it != end(); ++it)
    if(it.ptr->info == item)
      temp.insert(item);
  return temp;
}

template<class T>
void Container<T>::replace(const T& older, const T& newer) {
  for(Container<T>::iterator it = begin(); it !=end(); ++it)
    if(it.ptr->info == older)
      it.ptr->info = newer;
}

template<class T>
int Container<T>::size() const{
  int tot = 0;
  for(Container<T>::iterator it = begin(); it !=end(); ++it)
    tot++;
  return tot;
}

template<class T>
bool Container<T>::operator==(const Container<T>& cnt) const {
  return equals(first, cnt.first);
}

template<class T>
bool Container<T>::operator!=(const Container<T>& cnt) const {
  return !(equals(first, cnt.first));
}

template<class T>
ostream& operator<<(ostream& os, const Container<T>& cnt) {
  Container<T>::printContainer(os, cnt.first);
  return os;
}

#endif
