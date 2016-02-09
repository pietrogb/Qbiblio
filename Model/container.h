#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
using std::cout; using std::endl; using std::ostream;

template<class T> class Container; //dichiarazione incompleta di classe.

template<class T> ostream& operator<<(ostream&, const Container<T>&);

//class Container
template<class T>
class Container {
  //dichiarazioni di amicizia
  friend class Iterator;
  friend class const_Iterator;
  friend ostream& operator<< (ostream&, const Container<T>&);
private:
  //class ContainerItem
  class ContainerItem {
    public:
    T info;
    ContainerItem* next;
    //Costruttori
    ContainerItem();
    ContainerItem(const T&, ContainerItem*);
    //Distruttore
    ~ContainerItem();
    //Operatore d'uguaglianza
    bool operator==(const ContainerItem&) const;
    //Operatore di disuguaglianza
    bool operator!=(const ContainerItem&) const;
  };
  //puntatore al primo ContainerItem della lista
  ContainerItem* first;
  //copia profonda
  static ContainerItem* deepCopy(const ContainerItem*);
  //distruzione profonda
  static void deepRemove(ContainerItem*);
  //uguaglianza sottoliste
  static bool equals(const ContainerItem*, const ContainerItem*);
  //stampa contenitore
  static void printContainer(ostream&, const ContainerItem*);
public:
  //classe Iteratore
  class Iterator {
    //dichiarazione di amicizia
    friend class Container<T>;
  private:
    Container<T>::ContainerItem* ptr; //ContainerItem puntato dall'iteratore
  public:
    //costruttore di default
    Iterator();
    //operatore di uguaglianza
    bool operator==(Iterator) const;
    //operatore di disuguaglianza
    bool operator!=(Iterator) const;
    //operator ++ prefisso
    Iterator& operator++();
    //operator ++ postfisso
    Iterator operator++(int);
    //metodo per ottenere il puntore
    T operator*() const;
  };
  //Classe iteratore_costante
  class const_Iterator {
    //dichiarazione di amicizia
    friend class Container<T>;
  private:
    Container<T>::ContainerItem* ptr; //ContainerItem puntato dal const_iterator
  public:
    //costruttore di default
    const_Iterator();
    //costruttore come convertitore di tipo da Iterator a const_iterator
    const_Iterator(const Iterator&);
    //operatore di uguaglianza
    bool operator==(const_Iterator) const;
    //operatore di disuguaglianza
    bool operator!=(const_Iterator) const;
    //operator ++ prefisso
    const_Iterator& operator++();
    //operator ++ postfisso
    const_Iterator operator++(int);
    //metodo per ottenere il puntatore
    T operator*() const;
  };
  //metodi propri di Container:
  Iterator begin() const;
  Iterator end() const;
  //operatore di dereferenziazione/indicizzazione
  T& operator[](Iterator);
  //costruttore di default di Container
  Container();
  //construttore di copia
  Container(const Container<T>&);
  //operatore d'assegnazione
  Container<T>& operator=(const Container<T>&);
  //distruttore
  ~Container();
  //metodo che controlla se il contenitore è vuoto
  bool isEmpty() const;
  //metodo che aggiunge in testa un elemento
  void insert(const T&);
  //medoto che rimuove un elemento dalla lista
  void remove(const T&);
  //metodo che restituisce il numero di oggetti contenuti
  int size() const;
  //metodo per effettuare la ricerca
  Container<T> search(const T&) const;
  //
  void replace(const T&, const T&);
  bool operator==(const Container&) const;
  bool operator!=(const Container&) const;
};

/*
 ***********************
 Metodi di ContainerItem
 ***********************
 */
//costruttore di default
template<class T>
Container<T>::ContainerItem::ContainerItem() : info(0), next(0) {}

//costruttore a 2 parametri
template<class T>
Container<T>::ContainerItem::ContainerItem(const T& ci, ContainerItem* n=0) : info(ci), next(n) {}

//operatore d'uguaglianza
template<class T>
bool Container<T>::ContainerItem::operator==(const ContainerItem& cti) const {
  return (info == cti->info);
}

//operatore di disuguaglianza
template<class T>
bool Container<T>::ContainerItem::operator!=(const ContainerItem& cti) const {
  return (info != cti->info);
}
/*
 ***********************
 Metodi di Iterator
 ***********************
 */
//costruttore di default
template<class T>
Container<T>::Iterator::Iterator(): punt(0){}

//operatore d'uguaglianza
template<class T>
bool Container<T>::Iterator::operator==(Iterator it) const {
  return ptr == it.ptr;
}

//operatore di disuguaglianza
template<class T>
bool Container<T>::Iterator::operator!=(Iterator it) const {
  return ptr != it.ptr;
}

//incremento predisso
template<class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator++() {
  if(ptr)
    ptr = ptr->next;
  return *this;
}

//incremento postfisso
template<class T>
typename Container<T>::Iterator Container<T>::Iterator::operator++(int) {
  Iterator aux = *this;
  if(ptr)
    ptr = ptr->next;
  return aux;
}

//accesso a membro/indirezione
template<class T>
T Container<T>::Iterator::operator*() const {
  return (*ptr).info;
}

//inizio della lista
template<class T>
typename Container<T>::Iterator Container<T>::begin() const {
  Iterator aux;
  aux.ptr = first;
  return aux;
}

//fine della lista
template<class T>
typename Container<T>::Iterator Container<T>::end() const {
  Iterator aux;
  aux.ptr = 0;
  return aux;
}

//indicizzazione
template<class T>
T& Container<T>::operator[](Container<T>::Iterator it) {
  return (it.ptr)->info;
}
/*
 ***********************
 Metodi di const_Iterator
 ***********************
 */

//costruttore di default
template<class T>
Container<T>::const_Iterator::const_Iterator(): ptr(0) {}

//operatore d'uguaglianza
template<class T>
bool Container<T>::const_Iterator::operator==(const_Iterator it) const {
  return ptr == it.ptr;
}

//operatore di disuguaglianza
template<class T>
bool Container<T>::const_Iterator::operator!=(const_Iterator it) const {
  return ptr != it.ptr;
}

//incremento prefisso
template<class T>
typename Container<T>::const_Iterator& Container<T>::const_Iterator::operator++() {
  if(ptr)
    ptr = ptr->next;
  return *this;
}

//incremento postfisso
template<class T>
typename Container<T>::const_Iterator Container<T>::const_Iterator::operator++(int) {
  const_Iterator aux = *this;
  if(ptr)
    ptr = ptr->next;
  return aux;
}

//indirezione
template<class T>
T Container<T>::const_Iterator::operator*() const {
  return (*ptr).info;
}

//inizio della lista
template<class T>
typename Container<T>::const_Iterator Container<T>::begin() const {
  const_Iterator aux;
  aux.ptr = first;
  return aux;
}

//fine della lista
template<class T>
typename Container<T>::const_Iterator Container<T>::end() const {
  const_Iterator aux;
  aux.ptr = 0;
  return aux;
}

//inidicizzazione
template<class T>
T& Container<T>::operator[](Container<T>::const_Iterator it) {
  return (it.ptr)->info;
}

//convertitore di tipo
template<class T>
Container<T>::const_Iterator::const_Iterator(const Iterator & it){
    ptr=it.ptr;
}

/*
 ***********************
 Metodi di Container
 ***********************
 */
//costruttore di default
template<class T>
Container<T>::Container() : first(0) {}

//costruttore di copia profonda
template<class T>
Container<T>::Container(const Container<T>& cnt) : first(deepCopy(cnt.first)) { }

//operatore d'assegnazione profonda
template<class T>
Container<T>& Container<T>::operator=(const Container<T>& cnt) {
  if(this != &cnt){
    deepRemove(first);
    first = deepCopy(cnt.first);
  }
  return *this;
}

//distruzione profonda
template<class T>
Container<T>::~Container() {
  deepRemove(first);
}

//copia profonda
template<class T>
typename Container<T>::ContainerItem* Container<T>::deepCopy(const ContainerItem* ci) {
  if(!ci)
    return 0;
  else
    return new ContainerItem(ci->info, deepCopy(ci->next));
}

//distruzione profonda
template<class T>
void Container<T>::deepRemove(ContainerItem* ci) {
  if(ci){
    deepRemove(ci->next);
    delete ci;
  }
}

//uguaglianza tra 2 oggetti ContainerItem
template<class T>
bool Container<T>::equals(const ContainerItem* a, const ContainerItem* b) {
  if(a == 0 && b == 0) return true;
  if(a == 0 || b == 0) return false;
  return a->info == b->info && equals(a->next, b->next);
}

//metodo per la stampa
template<class T>
void Container<T>::printContainer(ostream& os, const ContainerItem* cti) {
  if(cti){
    os << cti->info;
    printContainer(os, cti->next);
  }
}

//lista vuota?
template<class T>
bool Container<T>::isEmpty() const {
  return (first == 0);
}

//inserimento in testa
template<class T>
void Container<T>::insert(const T& value) {
  first = new ContainerItem(value, first);
}

//rimozione elemento
template<class T>
void Container<T>::remove(const T & value) {
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

//ricerca elemento
template<class T>
Container<T> Container<T>::search(const T& item) const {
  Container<T> temp;
  for(Container<T>::Iterator it = begin(); it != end(); ++it)
    if(it.ptr->info == item)
      temp.insert(item);
  return temp;
}

//sostituzione elemento
template<class T>
void Container<T>::replace(const T& older, const T& newer) {
  for(Container<T>::Iterator it = begin(); it !=end(); ++it)
    if(it.ptr->info == older)
      it.ptr->info = newer;
}

//numero elementi presenti nel contenitore
template<class T>
int Container<T>::size() const{
  int tot = 0;
  for(Container<T>::Iterator it = begin(); it !=end(); ++it)
    tot++;
  return tot;
}

//operatore d'uguaglianza tra containers
template<class T>
bool Container<T>::operator==(const Container<T>& cnt) const {
  return equals(first, cnt.first);
}

//disugualglianza contenitori.
template<class T>
bool Container<T>::operator!=(const Container<T>& cnt) const {
  return !(equals(first, cnt.first));
}

/*
 *******************
 Operatore di output
 *******************
*/
template<class T>
ostream& operator<<(ostream& os, const Container<T>& cnt) {
  Container<T>::printContainer(os, cnt.first);
  return os;
}

#endif
