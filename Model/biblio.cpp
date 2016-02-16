#include "biblio.h"

Biblio::Biblio(const Container<LibraryItem*>& content): b(content){
    load();
}

Biblio::~Biblio(){
    for(Container<LibraryItem*>::Iterator it=b.begin(); it!=b.end(); ++it)
        delete *it;
}

bool Biblio::IsEmpty() const{
    return b.isEmpty();
}

int Biblio::getSize() const{
    return b.size();
}

bool Biblio::addItem(LibraryItem* li){
    bool presente=false;
    for(Container<LibraryItem*>::const_Iterator it=b.begin(); !presente && it!=b.end(); ++it){
        if(*(*it) == *li)
            presente=true;
    }
    b.insert(li);
    return presente;
}

void Biblio::removeItem(const QString& title ){
    for(int i=0; i<b.size(); ++i){
        if((getItem(i) -> getTitolo() == title)) {
            delete getItem(i);
        }
    }
}

LibraryItem* Biblio::getItem(int n){
    Container<LibraryItem*>::Iterator it = b.begin();
    for(int i=0; i<n; ++i)
        it++;
    return *it;
}

Container<LibraryItem*> Biblio::findItem(const QString& title) const {
    Container<LibraryItem*> ris;
    for(Container<LibraryItem*>::const_Iterator it= b.begin(); it!= b.end(); it++){
        if((*it)->search(title))
            ris.insert(*it);
    }
    return ris;
}

void Biblio::save() const{
    QFile* file = new QFile("/home/pietro/https:/github.com/pit1988/QBiblio/qbiblio.xml");
        if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
        {
           QMessageBox err;
           err.setText("Errore nell'apertura del file");
           err.exec();
        }
        else
        {
           QXmlStreamWriter* inp = new QXmlStreamWriter;
           inp->setAutoFormatting(true);
           inp->setDevice(file);
           inp->writeStartDocument();
           inp->writeStartElement("Biblioteca");
           for(Container<LibraryItem*>::const_Iterator it = b.begin(); it != b.end(); ++it)
           {
               LibraryItem* li= *it;
               inp->writeStartElement("Elemento");
               if(typeid(li) == typeid(CD*))
               {
                  inp->writeAttribute("tipo","CD");
                  CD* cd=dynamic_cast<CD*>(*(it));
                  inp->writeTextElement("Titolo", cd->getTitolo());
                  inp->writeTextElement("Genere", cd->getGenere());
                  inp->writeTextElement("Artista", cd->getArtista());
                  inp->writeTextElement("AnnoUscita", QString::number(cd->getAnnoUscita()));
                  inp->writeTextElement("Dischi", QString::number(cd->getDischi()));
               }
               else if(typeid(li) == typeid(DVD*))
               {
                  DVD* dvd=dynamic_cast<DVD*>(*(it));
                  inp->writeAttribute("tipo","DVD");
                  inp->writeTextElement("Titolo", dvd->getTitolo());
                  inp->writeTextElement("Genere", dvd->getGenere());
                  inp->writeTextElement("Regista", (dvd->getRegista()));
                  inp->writeTextElement("Durata", QString::number(dvd->getDurata()));
                  inp->writeTextElement("DataUscita", (dvd->getDataUscita()).toString("dd.MM.yyyy"));
               }
               else if(typeid(li) == typeid(Libro*))
               {
                  Libro* lib=dynamic_cast<Libro*>(*(it));
                  inp->writeAttribute("tipo", "Libro");
                  inp->writeTextElement("Titolo", lib->getTitolo());
                  inp->writeTextElement("Genere", lib->getGenere());
                  inp->writeTextElement("Autore", lib->getAutore());
                  inp->writeTextElement("AnnoUscita", QString::number(lib->getAnnoUscita()));
                  inp->writeTextElement("Editore", lib->getEditore());

               }
               else if(typeid(li) == typeid(VHS*))
               {
                  VHS* vhs=dynamic_cast<VHS*>(*(it));
                  inp->writeAttribute("tipo","VHS");
                  inp->writeTextElement("Titolo", vhs->getTitolo());
                  inp->writeTextElement("Genere", vhs->getGenere());
                  inp->writeTextElement("Regista", vhs->getRegista());
                  inp->writeTextElement("Durata", QString::number(vhs->getDurata()));
                  inp->writeTextElement("DataUscita", (vhs->getDataUscita()).toString("dd.MM.yyyy"));
               }
               inp->writeEndElement();
            }
            inp->writeEndElement();
            inp->writeEndDocument();
            file->close();
        }
    }

void Biblio::load(){
  QFile *file=new QFile("/home/pietro/https:/github.com/pit1988/QBiblio/qbiblio.xml");
  if(file->exists()){
    if(!file->open(QFile::ReadOnly | QFile::Text)){
      QMessageBox err;
      err.setText("Errore nell'apertura del file");
      err.exec();
    }
    else{
      QDomDocument doc;
      if(!doc.setContent(file))
      {
        return;
      }
      QDomElement docElem=doc.documentElement();
      QDomNodeList nodes=docElem.elementsByTagName("Elemento");
      for(int i=0; i<nodes.count();++i){
        QDomElement el=nodes.at(i).toElement();
        QDomNode nodo=el.firstChild();
        QDomAttr t=el.attributeNode("tipo");
        QString tipo=t.value();
        LibraryItem* li;
        if(tipo=="CD"){
          QDomAttr t=el.attributeNode("Titolo");
          QString titolo=t.value();
          QDomAttr g=el.attributeNode("Genere");
          QString genere=g.value();
          QDomAttr a=el.attributeNode("Artista");
          QString artista=a.value();
          QDomAttr u=el.attributeNode("AnnoUscita");
          int annoUscita=u.value().toInt();
          QDomAttr d=el.attributeNode("Dischi");
          int nDischi=d.value().toInt();
          li=new CD(titolo, genere, artista, annoUscita, nDischi);
          addItem(li); 
        }
        else if(tipo=="DVD"){
          QDomAttr t=el.attributeNode("Titolo");
          QString titolo=t.value();
          QDomAttr g=el.attributeNode("Genere");
          QString genere=g.value();
          QDomAttr r=el.attributeNode("Regista");
          QString regista=r.value();
          QDomAttr d=el.attributeNode("Durata");
          int durata=d.value().toInt();
          QString aux=el.attributeNode("DataUscita").value();
          QStringList u=aux.split(".");
          QDate dataUscita(u[2].toInt(),u[1].toInt(),u[0].toInt());
          li=new DVD(titolo, genere, regista, durata, dataUscita);
          addItem(li); 
        }
        else if(tipo=="Libro"){
          QDomAttr t=el.attributeNode("Titolo");
          QString titolo=t.value();
          QDomAttr g=el.attributeNode("Genere");
          QString genere=g.value();
          QDomAttr a=el.attributeNode("Autore");
          QString autore=a.value();
          QDomAttr u=el.attributeNode("AnnoUscita");
          int annoUscita=u.value().toInt();
          QDomAttr e=el.attributeNode("Editore");
          QString editore=e.value();
          li=new Libro(titolo, genere, autore, annoUscita, editore);
          addItem(li); 
        }
        else if(tipo=="VHS"){
          QDomAttr t=el.attributeNode("Titolo");
          QString titolo=t.value();
          QDomAttr g=el.attributeNode("Genere");
          QString genere=g.value();
          QDomAttr r=el.attributeNode("Regista");
          QString regista=r.value();
          QDomAttr d=el.attributeNode("Durata");
          int durata=d.value().toInt();
          QString aux=el.attributeNode("DataUscita").value();
          QStringList u=aux.split(".");
          QDate dataUscita(u[2].toInt(),u[1].toInt(),u[0].toInt());
          li=new VHS(titolo, genere, regista, durata, dataUscita);
          addItem(li); 
        }
      }
      file->close();
    }
  }
}

Container<LibraryItem*> Biblio::getLibrary() const{
    return b;
}



