#include "biblio.h"

Biblio::Biblio(const Container<LibraryItem*>& content): b(content){
    load();
}

Biblio::~Biblio(){
    for(Container<LibraryItem*>::Iterator it=b.begin(); it!=b.end()<; ++it)
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
    for(Container<LibraryItem*>::Iterator it= b.begin(); it!= b.end(); it++){
        if(*it->search())
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
               if(dynamic_cast<CD*>(*(it)))
               {
                   inp->writeAttribute("tipo","CD");
                   inp->writeTextElement("Titolo", QString::fromStdString(li->getTitolo()));
                   inp->writeTextElement("Genere", QString::fromStdString(li->getGenere()));
                   inp->writeTextElement("Artista", QString::fromStdString(li->getArtista()));
                   inp->writeTextElement("AnnoUscita", li->getAnnoUscita());
                   inp->writeTextElement("Dischi", li->getDischi());
               }
               else if(dynamic_cast<DVD*>(*(it)))
               {
                   inp->writeAttribute("tipo","DVD");
                   inp->writeTextElement("Titolo", QString::fromStdString(li->getTitolo()));
                   inp->writeTextElement("Genere", QString::fromStdString(li->getGenere()));
                   inp->writeTextElement("Regista", QString::fromStdString((li->getRegista())));
                   inp->writeTextElement("Durata", li->getDurata());
                   inp->writeTextElement("DataUscita", (li->getDataUscita()).toString("dd.MM.yyyy"));
               }
               else if(dynamic_cast<Libro*>(*(it)))
               {
                   inp->writeAttribute("tipo", "Libro");
                   inp->writeTextElement("Titolo", QString::fromStdString(li->getTitolo()));
                   inp->writeTextElement("Genere", QString::fromStdString(li->getGenere()));
                   inp->writeTextElement("Autore", QString::fromStdString(li->getautore()));
                   inp->writeTextElement("AnnoUscita", li->getAnnoUscita());
                   inp->writeTextElement("Editore", QString::fromStdString(li->getEditore()));

               }
               else if(dynamic_cast<VHS*>(*(it)))
               {
                   inp->writeAttribute("tipo","VHS");
                   inp->writeTextElement("Titolo", QString::fromStdString(li->getTitolo()));
                   inp->writeTextElement("Genere", QString::fromStdString(li->getGenere()));
                   inp->writeTextElement("Regista", QString::fromStdString((li->getRegista())));
                   inp->writeTextElement("Durata", li->getDurata());
                   inp->writeTextElement("DataUscita", (li->getDataUscita()).toString("dd.MM.yyyy"));
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
                    QString titolo=e;

                    QString u, n, c, d;
                    QDate data;
                    Competenze* comp;
                    Esperienze* esp;
                    Formazione* form;
                    Lingue* ling;
                    Rete* re;
                    vector<Rete*> rete;
                    Profilo* p=new Profilo();
                    while(!nodo.isNull()){
                        QDomElement elemento = nodo.toElement();
                        QString tagName = elemento.tagName();
                        if(tagName == "Username")
                        {
                            u=elemento.text();
                        }
                        if(tagName == "Nome")
                        {
                            n=elemento.text();
                        }
                        if(tagName == "Cognome")
                        {
                            c=elemento.text();
                        }
                        if(tagName == "DataNascita")
                        {
                            QString aux=elemento.text();
                            QStringList l=aux.split(".");
                            data.setDate(l[2].toInt(),l[1].toInt(),l[0].toInt());
                        }
                        if(tagName == "Descrizione")
                        {
                            d=elemento.text();
                        }

                        if(tagName == "Competenze")
                        {
                            QString nomeC=elemento.attributeNode("nome").value();
                            int votoC=elemento.attributeNode("voto").value().toInt();
                            comp=new Competenze(nomeC.toStdString(), votoC);
                            p->addInC(*comp);
                        }
                        if(tagName == "Esperienze")
                        {
                            QString nomeE=elemento.attributeNode("nome").value();
                            QString inizio=elemento.attributeNode("inizio").value();
                            QString fine=elemento.attributeNode("fine").value();
                            QStringList i=inizio.split(".");
                            QStringList f=fine.split(".");
                            QDate in(i[2].toInt(),i[1].toInt(),i[0].toInt());
                            QDate fi(f[2].toInt(),f[1].toInt(),f[0].toInt());
                            esp=new Esperienze(nomeE.toStdString(), in, fi);
                            p->addInE(*esp);
                        }
                        if(tagName == "Studi")
                        {
                            QString nomeS=elemento.attributeNode("percorso").value();
                            int annoS=elemento.attributeNode("anno").value().toInt();
                            form=new Formazione(nomeS.toStdString(), annoS);
                            p->addInF(*form);
                        }
                        if(tagName == "Lingue")
                        {
                            QString nomeL=elemento.attributeNode("nome").value();
                            QString livelloL=elemento.attributeNode("livello").value();
                            ling = new Lingue(nomeL.toStdString(), livelloL.toStdString());
                            p->addInL(*ling);
                        }
                        if(tagName == "Rete")
                        {
                            QString nomeUser=elemento.attributeNode("username").value();
                            re=new Rete(nomeUser.toStdString());
                            rete.push_back(re);
                        }
                        nodo=nodo.nextSibling();
                    }
                    Utente* ut = 0;
                    if(tipo=="Basic")
                    {
                        ut=new UtenteBasic(u.toStdString(), n.toStdString(), c.toStdString(), data, d.toStdString(), p, rete);
                    }
                    if(tipo=="Executive")
                    {
                        ut=new UtenteExecutive(u.toStdString(), n.toStdString(), c.toStdString(), data, d.toStdString(), p, rete);
                    }
                    if(tipo=="Business"){
                        ut=new UtenteBusiness(u.toStdString(), n.toStdString(), c.toStdString(), data, d.toStdString(), p, rete);
                    }
                    addUtenti(ut);
                }
                file->close();
            }
        }
    }
}

Container<LibraryItem*> Biblio::getLibrary() const{
    return b;
}



