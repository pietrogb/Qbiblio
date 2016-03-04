#include "biblio.h"

Biblio::Biblio(const Container<SmartPtr>& content): b(content){
//    load();
}

Biblio::~Biblio(){
//    for(Container<SmartPtr>::Iterator it=b.begin(); it!=b.end(); ++it)
//        delete(&(*(*it)));
//    delete(&b);
    delete &b;
}

bool Biblio::IsEmpty() const{
    return b.isEmpty();
}

int Biblio::size() const{
    return b.size();
}

void Biblio::Insert(const SmartPtr& ins){
    b.insert(ins);
}

void Biblio::Remove(const SmartPtr& rmv){
    b.remove(rmv);
}

void Biblio::Replace(const SmartPtr & older, const SmartPtr & newer){
    b.replace(older, newer);
}

//bool Biblio::addItem(SmartPtr li){
//    bool presente=false;
//    for(Container<SmartPtr>::const_Iterator it=b.begin(); !presente && it!=b.end(); ++it){
//        if(*(*it) == *li)
//            presente=true;
//    }
//    b.insert(li);
//    return presente;
//}

//void Biblio::removeItem(const string& title ){
//    for(int i=0; i<b.size(); ++i){
//        if((getItem(i) -> getTitolo() == title)) {
//            b.remove((getItem(i)).getItem());
//        }
//    }
//}

LibraryItem* Biblio::getItem(int n){
    Container<SmartPtr>::Iterator it = b.begin();
    for(int i=0; i<n; ++i)
        it++;
    return (*it).getItem();
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
    QFile* file = new QFile("/home/pietro/qbiblio.xml");
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
           CD* cd=dynamic_cast<CD*>((*it).getItem());
           if(cd)
           {
              inp->writeAttribute("tipo","CD");
              inp->writeTextElement("Titolo", QString::fromStdString(cd->getTitolo()));
              inp->writeTextElement("Genere", QString::fromStdString(cd->getGenere()));
              inp->writeTextElement("Artista", QString::fromStdString(cd->getArtista()));
              inp->writeTextElement("AnnoUscita", QString::number(cd->getAnnoUscita()));
              inp->writeTextElement("Dischi", QString::number(cd->getDischi()));
           }
           else
           {
              DVD* dvd=dynamic_cast<DVD*>((*it).getItem());
              if(dvd){
                  inp->writeAttribute("tipo","DVD");
                  inp->writeTextElement("Titolo", QString::fromStdString(dvd->getTitolo()));
                  inp->writeTextElement("Genere", QString::fromStdString(dvd->getGenere()));
                  inp->writeTextElement("Regista", QString::fromStdString(dvd->getRegista()));
                  inp->writeTextElement("Durata", QString::number(dvd->getDurata()));
                  inp->writeTextElement("DataUscita", (dvd->getDataUscita()).toString("dd.MM.yyyy"));
              }
              else
              {
                Libro* lib=dynamic_cast<Libro*>((*it).getItem());
                if(lib){
                  inp->writeAttribute("tipo", "Libro");
                  inp->writeTextElement("Titolo", QString::fromStdString(lib->getTitolo()));
                  inp->writeTextElement("Genere", QString::fromStdString(lib->getGenere()));
                  inp->writeTextElement("Autore", QString::fromStdString(lib->getAutore()));
                  inp->writeTextElement("AnnoUscita", QString::number(lib->getAnnoUscita()));
                  inp->writeTextElement("Editore", QString::fromStdString(lib->getEditore()));
                }
                else
                {
                    VHS* vhs=dynamic_cast<VHS*>((*it).getItem());
                    if(vhs){
                        inp->writeAttribute("tipo","VHS");
                        inp->writeTextElement("Titolo", QString::fromStdString(vhs->getTitolo()));
                        inp->writeTextElement("Genere", QString::fromStdString(vhs->getGenere()));
                        inp->writeTextElement("Regista", QString::fromStdString(vhs->getRegista()));
                        inp->writeTextElement("Durata", QString::number(vhs->getDurata()));
                        inp->writeTextElement("DataUscita", (vhs->getDataUscita()).toString("dd.MM.yyyy"));
                    }
                }
              }
           }
           /* /////////////OLD
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
           */
           inp->writeEndElement();
        }
        inp->writeEndElement();
        inp->writeEndDocument();
        file->close();
    }
}

void Biblio::load(){
  QFile *file=new QFile("/home/pietro/qbiblio.xml");
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
      for(int i=0; i<nodes.count(); ++i){
        QDomElement el=nodes.at(i).toElement();
        QDomNode nodo=el.firstChild();
        QDomAttr t=el.attributeNode("tipo");
        QString tipo=t.value();
        SmartPtr li;
        if(tipo=="CD"){
          QString titolo, genere, artista;
          int annoUscita, nDischi;
          while(!nodo.isNull()){
              QDomElement elemento = nodo.toElement();
              QString tagName = elemento.tagName();
              if(tagName=="Titolo")
                  titolo=elemento.text();
              if(tagName=="Genere")
                  genere=elemento.text();
              if(tagName=="Artista")
                  artista=elemento.text();
              if(tagName=="AnnoUscita")
                  annoUscita=elemento.text().toInt();
              if(tagName=="Dischi")
                  nDischi=elemento.text().toInt();
              nodo=nodo.nextSibling();
          }
          li=new CD(titolo.toStdString(), genere.toStdString(), artista.toStdString(), annoUscita, nDischi);
          Insert(li);
        }
        else if(tipo=="DVD"){
          QString titolo, genere, regista;
          int durata;
          QDate dataUscita;
          while(!nodo.isNull()){
              QDomElement elemento = nodo.toElement();
              QString tagName = elemento.tagName();
              if(tagName=="Titolo")
                  titolo=elemento.text();
              if(tagName=="Genere")
                  genere=elemento.text();
              if(tagName=="Regista")
                  regista=elemento.text();
              if(tagName=="Durata")
                  durata=elemento.text().toInt();
              if(tagName=="DataUscita"){
                  QString aux=elemento.text();
                  QStringList l=aux.split(".");
                  dataUscita.setDate(l[2].toInt(),l[1].toInt(),l[0].toInt());
              }
              nodo=nodo.nextSibling();
          }
          li=new DVD(titolo.toStdString(), genere.toStdString(), regista.toStdString(), durata, dataUscita);
          Insert(li);
        }
        else if(tipo=="Libro"){
            QString titolo, genere, autore, editore;
            int annoUscita;
            while(!nodo.isNull()){
                QDomElement elemento = nodo.toElement();
                QString tagName = elemento.tagName();
                if(tagName=="Titolo")
                    titolo=elemento.text();
                if(tagName=="Genere")
                    genere=elemento.text();
                if(tagName=="Autore")
                    autore=elemento.text();
                if(tagName=="AnnoUscita")
                    annoUscita=elemento.text().toInt();
                if(tagName=="Editore")
                    editore=elemento.text();
                nodo=nodo.nextSibling();
            }
          li=new Libro(titolo.toStdString(), genere.toStdString(), autore.toStdString(), annoUscita, editore.toStdString());
          Insert(li);
        }
        else if(tipo=="VHS"){
            QString titolo, genere, regista;
            int durata;
            QDate dataUscita;
            while(!nodo.isNull()){
                QDomElement elemento = nodo.toElement();
                QString tagName = elemento.tagName();
                if(tagName=="Titolo")
                    titolo=elemento.text();
                if(tagName=="Genere")
                    genere=elemento.text();
                if(tagName=="Regista")
                    regista=elemento.text();
                if(tagName=="Durata")
                    durata=elemento.text().toInt();
                if(tagName=="DataUscita"){
                    QString aux=elemento.text();
                    QStringList l=aux.split(".");
                    dataUscita.setDate(l[2].toInt(),l[1].toInt(),l[0].toInt());
                }
                nodo=nodo.nextSibling();
            }
            li=new VHS(titolo.toStdString(), genere.toStdString(), regista.toStdString(), durata, dataUscita);
            Insert(li);
        }
      }
      file->close();
    }
  }
}

Container<SmartPtr> Biblio::getLibrary() const{
    return b;
}



