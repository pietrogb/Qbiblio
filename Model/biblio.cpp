#include "biblio.h"

Biblio::Biblio(const Container<SmartPtr>& content): b(content){
    load();
}

Biblio::~Biblio(){
    for(Container<SmartPtr>::Iterator it=b.begin(); it!=b.end(); ++it)
        delete(&(*(*it)));
    delete(&b);
}

bool Biblio::IsEmpty() const{
    return b.isEmpty();
}

int Biblio::getSize() const{
    return b.size();
}

bool Biblio::addItem(SmartPtr li){
    bool presente=false;
    for(Container<SmartPtr>::const_Iterator it=b.begin(); !presente && it!=b.end(); ++it){
        if(*(*it) == *li)
            presente=true;
    }
    b.insert(li);
    return presente;
}

void Biblio::removeItem(const string& title ){
    for(int i=0; i<b.size(); ++i){
        if((getItem(i) -> getTitolo() == title)) {
            b.remove((getItem(i)).getItem());
        }
    }
}

SmartPtr Biblio::getItem(int n){
    Container<SmartPtr>::Iterator it = b.begin();
    for(int i=0; i<n; ++i)
        it++;
    return *it;
}

Container<SmartPtr> Biblio::findItem(const string& title) const {
    Container<SmartPtr> ris;
    for(Container<SmartPtr>::const_Iterator it= b.begin(); it!= b.end(); it++){
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
           for(Container<SmartPtr>::const_Iterator it = b.begin(); it != b.end(); ++it)
           {
               SmartPtr li= *it;
               inp->writeStartElement("Elemento");
               if(typeid(li) == typeid(CD*))
               {
                  inp->writeAttribute("tipo","CD");
                  CD* cd=dynamic_cast<CD*>(li.getItem());
                  inp->writeTextElement("Titolo", QString::fromStdString(cd->getTitolo()));
                  inp->writeTextElement("Genere", QString::fromStdString(cd->getGenere()));
                  inp->writeTextElement("Artista", QString::fromStdString(cd->getArtista()));
                  inp->writeTextElement("AnnoUscita", QString::number(cd->getAnnoUscita()));
                  inp->writeTextElement("Dischi", QString::number(cd->getDischi()));
               }
               else if(typeid(li) == typeid(DVD*))
               {
                  DVD* dvd=dynamic_cast<DVD*>(li.getItem());
                  inp->writeAttribute("tipo","DVD");
                  inp->writeTextElement("Titolo", QString::fromStdString(dvd->getTitolo()));
                  inp->writeTextElement("Genere", QString::fromStdString(dvd->getGenere()));
                  inp->writeTextElement("Regista", QString::fromStdString(dvd->getRegista()));
                  inp->writeTextElement("Durata", QString::number(dvd->getDurata()));
                  inp->writeTextElement("DataUscita", (dvd->getDataUscita()).toString("dd.MM.yyyy"));
               }
               else if(typeid(li) == typeid(Libro*))
               {
                  Libro* lib=dynamic_cast<Libro*>(li.getItem());
                  inp->writeAttribute("tipo", "Libro");
                  inp->writeTextElement("Titolo", QString::fromStdString(lib->getTitolo()));
                  inp->writeTextElement("Genere", QString::fromStdString(lib->getGenere()));
                  inp->writeTextElement("Autore", QString::fromStdString(lib->getAutore()));
                  inp->writeTextElement("AnnoUscita", QString::number(lib->getAnnoUscita()));
                  inp->writeTextElement("Editore", QString::fromStdString(lib->getEditore()));

               }
               else if(typeid(li) == typeid(VHS*))
               {
                  VHS* vhs=dynamic_cast<VHS*>(li.getItem());
                  inp->writeAttribute("tipo","VHS");
                  inp->writeTextElement("Titolo", QString::fromStdString(vhs->getTitolo()));
                  inp->writeTextElement("Genere", QString::fromStdString(vhs->getGenere()));
                  inp->writeTextElement("Regista", QString::fromStdString(vhs->getRegista()));
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
        SmartPtr li;
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
          li=new CD(titolo.toStdString(), genere.toStdString(), artista.toStdString(), annoUscita, nDischi);
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
          li=new DVD(titolo.toStdString(), genere.toStdString(), regista.toStdString(), durata, dataUscita);
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
          li=new Libro(titolo.toStdString(), genere.toStdString(), autore.toStdString(), annoUscita, editore.toStdString());
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
          li=new VHS(titolo.toStdString(), genere.toStdString(), regista.toStdString(), durata, dataUscita);
          addItem(li); 
        }
      }
      file->close();
    }
  }
}

Container<SmartPtr> Biblio::getLibrary() const{
    return b;
}



