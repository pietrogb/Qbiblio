#include
#include "../Gui/Trova_Elemento.h"

#include <QVBoxLayout>

Trova_Elemento::Trova_Elemento(QWidget* parent, Biblio* b) : QDialog(parent) {
  setWindowTitle("Trova Elemento");
  items = b->getLibrary();

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
  gridLayout_topLeft->addWidget(checkBox_tile,0,0,1,1);
  gridLayout_topLeft->addWidget(label_title,0,1,1,1);
  gridLayout_topLeft->addWidget(lineEdit_title,0,2,1,1);

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

  for(Container<LibraryItem*>::Const_Iterator it = items.begin(); it != items.end(); ++it) {
    bool toPrint = false;
    QString strToPtint;
    
    QString title(QString::fromStdString((*it)->getTitle()));
    QString autore(QString::fromStdString((*it)->getAutore()));
    QString genere(QString::fromStdString((*it)->getgenere()));
        
    Statua* st = dynamic_cast<Statua*>((*it).getOpera());
    
    if((radioButton_opere->isChecked() || radioButton_Statue->isChecked()) && st){
      if(checkBox_tile->isChecked()){
        QString title_f = lineEdit_title->text();
        toPrint = title.contains(title_f, Qt::CaseInsensitive);
      }
      if(checkBox_autore->isChecked()){
        QString autore_f = lineEdit_autore->text();
        toPrint = autore.contains(autore_f, Qt::CaseInsensitive);
      }
      if(checkBox_genere->isChecked()){
        QString genere_f = lineEdit_genere->text();
        toPrint = genere.contains(genere_f, Qt::CaseInsensitive);
      }
      if(checkBox_yearOfCreation->isChecked()){
        QString yearOfCreation_f = lineEdit_yearOfCreation->text();
        toPrint = yearOfCreation.contains(yearOfCreation_f, Qt::CaseInsensitive);
      }
      if(toPrint){
        strToPtint.prepend(QString::fromStdString(st->getMaterial()));
        strToPtint.prepend(" | Materiale: ");
        strToPtint.prepend(QString::number(st->getHeight()));
        strToPtint.prepend(" | Altezza: ");
      }
    }

    Dipinto* di = dynamic_cast<Dipinto*>((*it).getOpera());

    if((radioButton_opere->isChecked() || radioButton_Dipinti->isChecked()) && di){
      if(checkBox_tile->isChecked()){
        QString title_f = lineEdit_title->text();
        toPrint = title.contains(title_f, Qt::CaseInsensitive);
      }
      if(checkBox_autore->isChecked()){
        QString autore_f = lineEdit_autore->text();
        toPrint = autore.contains(autore_f, Qt::CaseInsensitive);
      }
      if(checkBox_genere->isChecked()){
        QString genere_f = lineEdit_genere->text();
        toPrint = genere.contains(genere_f, Qt::CaseInsensitive);
      }
      if(checkBox_yearOfCreation->isChecked()){
        QString yearOfCreation_f = lineEdit_yearOfCreation->text();
        toPrint = yearOfCreation.contains(yearOfCreation_f, Qt::CaseInsensitive);
      }
      if(toPrint){
        strToPtint.prepend(QString::fromStdString(di->getType()));
        strToPtint.prepend(" | Tecnica: ");
        strToPtint.prepend(QString::number(di->getWidth()));
        strToPtint.prepend(" | Larghezza: ");
        strToPtint.prepend(QString::number(di->getHeight()));
        strToPtint.prepend(" | Altezza: ");
      }
    }
    if(toPrint){
      strToPtint.prepend(yearOfCreation.toUpper());
      strToPtint.prepend(" | Anno Creazione: " );
      strToPtint.prepend(genere.toUpper());
      strToPtint.prepend(" | Ubicazione: " );
      strToPtint.prepend(autore.toUpper());
      strToPtint.prepend(" | Autore: " );
      strToPtint.prepend(title.toUpper());
      strToPtint.prepend(") Titolo: " );
      strToPtint.prepend(QString::number(++num));
      textEdit_resultFilter->append(strToPtint);
      textEdit_resultFilter->show();
    }
  }
  textEdit_resultFilter->setReadOnly(true);
}
