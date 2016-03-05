
#include "../View/trova_elemento.h"
#include <QVBoxLayout>

Trova_Elemento::Trova_Elemento(QWidget* parent, Biblio* b) : QDialog(parent) {
  setWindowTitle("Trova Elemento");
  items = (b)->getLibrary();

  gridLayout_main = new QGridLayout();
  gridLayout_main->setSpacing(5);
  gridLayout_main->setContentsMargins(5,5,5,5);

  horizontalLayout_top = new QHBoxLayout();
  horizontalLayout_top->setSpacing(5);

  gridLayout_topLeft = new QGridLayout();
  gridLayout_topLeft->setSpacing(5);

  checkBox_titolo = new QCheckBox();
  label_titolo = new QLabel("Titolo");
  lineEdit_titolo = new QLineEdit();
  label_titolo->setIndent(5);
  gridLayout_topLeft->addWidget(checkBox_titolo,0,0,1,1);
  gridLayout_topLeft->addWidget(label_titolo,0,1,1,1);
  gridLayout_topLeft->addWidget(lineEdit_autore,0,2,1,1);

  checkBox_autore = new QCheckBox();
  label_autore = new QLabel("Autore");
  lineEdit_autore = new QLineEdit();
  label_autore->setIndent(5);
  gridLayout_topLeft->addWidget(checkBox_autore,1,0,1,1);
  gridLayout_topLeft->addWidget(label_autore,1,1,1,1);
  gridLayout_topLeft->addWidget(lineEdit_autore,1,2,1,1);

  checkBox_genere = new QCheckBox();
  label_genere = new QLabel("Genere");
  lineEdit_genere = new QLineEdit();
  label_genere->setIndent(5);
  gridLayout_topLeft->addWidget(checkBox_genere,2,0,1,1);
  gridLayout_topLeft->addWidget(label_genere,2,1,1,1);
  gridLayout_topLeft->addWidget(lineEdit_genere,2,2,1,1);


  horizontalLayout_top->addLayout(gridLayout_topLeft);

  horizontalSpacer_top = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout_top->addItem(horizontalSpacer_top);

  gridLayout_topRight = new QGridLayout();
  gridLayout_topRight->setSpacing(5);

  label_info_filter = new QLabel("Filtro:");
  gridLayout_topRight->addWidget(label_info_filter,0,0,1,1);

  radioButton_all = new QRadioButton("Tutti");
  radioButton_all->setChecked(true);
  gridLayout_topRight->addWidget(radioButton_all,1,0,1,1);

  radioButton_Libri = new QRadioButton("Libri");
  gridLayout_topRight->addWidget(radioButton_Libri,2,0,1,1);

  radioButton_CD = new QRadioButton("CD");
  gridLayout_topRight->addWidget(radioButton_CD,3,0,1,1);

  radioButton_DVD = new QRadioButton("DVD");
  gridLayout_topRight->addWidget(radioButton_DVD,4,0,1,1);

  radioButton_VHS = new QRadioButton("VHS");
  gridLayout_topRight->addWidget(radioButton_VHS,5,0,1,1);

  verticalSpacer_radioButtonDown = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);
  gridLayout_topRight->addItem(verticalSpacer_radioButtonDown,6,0,1,1);

  horizontalLayout_top->addLayout(gridLayout_topRight);

  gridLayout_main->addLayout(horizontalLayout_top, 1, 0, 1, 1);

  textEdit_resultFilter = new QTextEdit();

  gridLayout_main->addWidget(textEdit_resultFilter,2,0,1,1);

  horizontalLayout_bottom = new QHBoxLayout();
  horizontalLayout_bottom->setSpacing(5);

  horizontalSpacer_bottom = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout_bottom->addItem(horizontalSpacer_bottom);

  pushButton_search = new QPushButton("Trova");
  horizontalLayout_bottom->addWidget(pushButton_search);
  connect(pushButton_search,SIGNAL(clicked()),this,SLOT(slot_pushButton_search()));

  pushButton_close = new QPushButton("Chiudi");
  horizontalLayout_bottom->addWidget(pushButton_close);
  connect(pushButton_close,SIGNAL(clicked()),this,SLOT(close()));

  gridLayout_main->addLayout(horizontalLayout_bottom, 3, 0, 1, 1);

  setLayout(gridLayout_main);
}

  
void Trova_Elemento::slot_pushButton_search() {
  textEdit_resultFilter->clear();

  textEdit_resultFilter->setStyleSheet("font-size: 10px");

  int num = 0;

  for(Container<SmartPtr>::const_Iterator it = items->begin(); it != items->end(); ++it) {
    bool toPrint = false;
    QString strRisultato;
    
    QString title(QString::fromStdString((*it).getItem()->getTitle())); //controllare
    QString genere(QString::fromStdString((*it).getItem()->getgenere())); //controllare
    CD* cd=dynamic_cast<CD*>((*it).getItem());
    if((radioButton_all->isChecked() || radioButton_CD->isChecked()) && cd){
        if(checkBox_titolo->isChecked()){
            QString title_f=lineEdit_titolo->text();
            toPrint=title.contains(title_f, Qt::CaseInsensitive);
        }
        if(checkBox_autore->isChecked()){
            QString artista(QString::fromStdString(cd->getArtista()));
            QString autore_f=lineEdit_autore->text();
            toPrint = artista.contains(autore_f, Qt::CaseInsensitive);
        }
        if(checkBox_genere->isChecked()){
            QString genere_f=lineEdit_genere_f->text();
            toPrint=genere_f.contains(genere_f, Qt::CaseInsensitive);
        }
        if(toPrint){
            strRisultato.prepend(QString::number(cd->getAnnoUscita()));
            strRisultato.prepend(" | AnnoUscita: ");
            strRisultato.prepend(QString::number(cd->getDischi()));
            strRisultato.prepend(" | Dischi: ");
            strRisultato.prepend(QString::fromStdString(cd->getArtista()));
            strRisultato.prepend(" | Artista: ");
        }
    }
    Libro* lib=dynamic_cast<Libro*>((*it).getItem());
    if((radioButton_all->isChecked() || radioButton_Libri->isChecked()) && lib){
        if(checkBox_titolo->isChecked()){
            QString title_f=lineEdit_titolo->text();
            toPrint=title.contains(title_f, Qt::CaseInsensitive);
        }
        if(checkBox_autore->isChecked()){
            QString autore(QString::fromStdString(lib->getArtista()));
            QString autore_f=lineEdit_autore->text();
            toPrint = autore.contains(autore_f, Qt::CaseInsensitive);
        }
        if(checkBox_genere->isChecked()){
            QString genere_f=lineEdit_genere_f->text();
            toPrint=genere_f.contains(genere_f, Qt::CaseInsensitive);
        }
        if(toPrint){ //in ordine inverso
            strRisultato.prepend(QString::fromStdString(lib->getEditore()));
            strRisultato.prepend(" | Editore: ");
            strRisultato.prepend(QString::number(lib->getAnnoUscita()));
            strRisultato.prepend(" | AnnoUscita: ");
            strRisultato.prepend(QString::fromStdString(lib->getAutore()));
            strRisultato.prepend(" | Autore: ");
        }
    }
    DVD* dvd=dynamic_cast<DVD*>((*it).getItem());
    if((radioButton_all->isChecked() || radioButton_DVD->isChecked()) && dvd){
        if(checkBox_titolo->isChecked()){
            QString title_f=lineEdit_titolo->text();
            toPrint=title.contains(title_f, Qt::CaseInsensitive);
        }
        if(checkBox_autore->isChecked()){
            QString regista(QString::fromStdString(dvd->getRegista()));
            QString autore_f=lineEdit_autore->text();
            toPrint = regista.contains(autore_f, Qt::CaseInsensitive);
        }
        if(checkBox_genere->isChecked()){
            QString genere_f=lineEdit_genere_f->text();
            toPrint=genere_f.contains(genere_f, Qt::CaseInsensitive);
        }
        if(toPrint){ //in ordine inverso
            strRisultato.prepend((dvd->getDataUscita()).toString("dd.MM.yyyy"));
            strRisultato.prepend(" | DataUscita: ");
            strRisultato.prepend(QString::number(dvd->getDurata()));
            strRisultato.prepend(" | Durata: ");
            strRisultato.prepend(QString::fromStdString(dvd->getRegista()));
            strRisultato.prepend(" | Regista: ");
        }
    }
    VHS* vhs=dynamic_cast<VHS*>((*it).getItem());
    if((radioButton_all->isChecked() || radioButton_DVD->isChecked()) && vhs){
        if(checkBox_titolo->isChecked()){
            QString title_f=lineEdit_titolo->text();
            toPrint=title.contains(title_f, Qt::CaseInsensitive);
        }
        if(checkBox_autore->isChecked()){
            QString regista(QString::fromStdString(vhs->getRegista()));
            QString autore_f=lineEdit_autore->text();
            toPrint = regista.contains(autore_f, Qt::CaseInsensitive);
        }
        if(checkBox_genere->isChecked()){
            QString genere_f=lineEdit_genere_f->text();
            toPrint=genere_f.contains(genere_f, Qt::CaseInsensitive);
        }
        if(toPrint){ //in ordine inverso
            strRisultato.prepend((vhs->getDataUscita()).toString("dd.MM.yyyy"));
            strRisultato.prepend(" | DataUscita: ");
            strRisultato.prepend(QString::number(vhs->getDurata()));
            strRisultato.prepend(" | Durata: ");
            strRisultato.prepend(QString::fromStdString(vhs->getRegista()));
            strRisultato.prepend(" | Regista: ");
        }
    }
//        //************FROM HERE
//    Statua* st = dynamic_cast<Statua*>((*it).getOpera());

    //    if((radioButton_opere->isChecked() || radioButton_Statue->isChecked()) && st){
    //      if(checkBox_tile->isChecked()){
    //        QString title_f = lineEdit_title->text();
    //        toPrint = title.contains(title_f, Qt::CaseInsensitive);
    //      }
//      if(checkBox_autore->isChecked()){
//        QString autore_f = lineEdit_autore->text();
//        toPrint = autore.contains(autore_f, Qt::CaseInsensitive);
//      }
//      if(checkBox_genere->isChecked()){
//        QString genere_f = lineEdit_genere->text();
//        toPrint = genere.contains(genere_f, Qt::CaseInsensitive);
//      }
//      if(checkBox_yearOfCreation->isChecked()){
//        QString yearOfCreation_f = lineEdit_yearOfCreation->text();
//        toPrint = yearOfCreation.contains(yearOfCreation_f, Qt::CaseInsensitive);
//      }
//      if(toPrint){
//        strRisultato.prepend(QString::fromStdString(st->getMaterial()));
//        strRisultato.prepend(" | Materiale: ");
//        strRisultato.prepend(QString::number(st->getHeight()));
//        strRisultato.prepend(" | Altezza: ");
//      }
//    }

//    Dipinto* di = dynamic_cast<Dipinto*>((*it).getOpera());

//    if((radioButton_opere->isChecked() || radioButton_Dipinti->isChecked()) && di){
//      if(checkBox_tile->isChecked()){
//        QString title_f = lineEdit_title->text();
//        toPrint = title.contains(title_f, Qt::CaseInsensitive);
//      }
//      if(checkBox_autore->isChecked()){
//        QString autore_f = lineEdit_autore->text();
//        toPrint = autore.contains(autore_f, Qt::CaseInsensitive);
//      }
//      if(checkBox_genere->isChecked()){
//        QString genere_f = lineEdit_genere->text();
//        toPrint = genere.contains(genere_f, Qt::CaseInsensitive);
//      }
//      if(checkBox_yearOfCreation->isChecked()){
//        QString yearOfCreation_f = lineEdit_yearOfCreation->text();
//        toPrint = yearOfCreation.contains(yearOfCreation_f, Qt::CaseInsensitive);
//      }
//      if(toPrint){
//        strRisultato.prepend(QString::fromStdString(di->getType()));
//        strRisultato.prepend(" | Tecnica: ");
//        strRisultato.prepend(QString::number(di->getWidth()));
//        strRisultato.prepend(" | Larghezza: ");
//        strRisultato.prepend(QString::number(di->getHeight()));
//        strRisultato.prepend(" | Altezza: ");
//      }
//      //************TO HERE
//    }
    if(toPrint){ //solo Titolo e Genere (in ordine inverso)
      strRisultato.prepend(genere.toUpper());
      strRisultato.prepend(" | Genere: " );
      strRisultato.prepend(titolo.toUpper());
      strRisultato.prepend(") Titolo: " );
      strRisultato.prepend(QString::number(++num));
      textEdit_resultFilter->append(strRisultato);
      textEdit_resultFilter->show();
    }
  }
  textEdit_resultFilter->setReadOnly(true);
}
