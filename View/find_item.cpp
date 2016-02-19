#include
#include "../Gui/Trova_LibraryItem.h"

#include <QVBoxLayout>

Trova_LibraryItem::Trova_LibraryItem(QWidget* parent, Container<SmartAptr>* p) : QDialog(parent) {
  setWindowTitle("Trova Opera");
  ctp = p;

  gridLayout_main = new QGridLayout();
  gridLayout_main->setSpacing(5);
  gridLayout_main->setContentsMargins(5,5,5,5);

  horizontalLayout_top = new QHBoxLayout();
  horizontalLayout_top->setSpacing(5);

  gridLayout_topLeft = new QGridLayout();
  gridLayout_topLeft->setSpacing(5);

  checkBox_tile = new QCheckBox();
  label_title = new QLabel("Titolo");
  lineEdit_title = new QLineEdit();
  label_title->setIndent(5);
  gridLayout_topLeft->addWidget(checkBox_tile,0,0,1,1);
  gridLayout_topLeft->addWidget(label_title,0,1,1,1);
  gridLayout_topLeft->addWidget(lineEdit_title,0,2,1,1);

  checkBox_artist = new QCheckBox();
  label_artist = new QLabel("Artista");
  lineEdit_artist = new QLineEdit();
  label_artist->setIndent(5);
  gridLayout_topLeft->addWidget(checkBox_artist,1,0,1,1);
  gridLayout_topLeft->addWidget(label_artist,1,1,1,1);
  gridLayout_topLeft->addWidget(lineEdit_artist,1,2,1,1);

  checkBox_location = new QCheckBox();
  label_location = new QLabel("Ubicazione");
  lineEdit_location = new QLineEdit();
  label_location->setIndent(5);
  gridLayout_topLeft->addWidget(checkBox_location,2,0,1,1);
  gridLayout_topLeft->addWidget(label_location,2,1,1,1);
  gridLayout_topLeft->addWidget(lineEdit_location,2,2,1,1);

  checkBox_yearOfCreation = new QCheckBox();
  label_yearOfCreation = new QLabel("Anno Creazione");
  lineEdit_yearOfCreation = new QLineEdit();
  label_yearOfCreation->setIndent(5);
  gridLayout_topLeft->addWidget(checkBox_yearOfCreation,3,0,1,1);
  gridLayout_topLeft->addWidget(label_yearOfCreation,3,1,1,1);
  gridLayout_topLeft->addWidget(lineEdit_yearOfCreation,3,2,1,1);

  horizontalLayout_top->addLayout(gridLayout_topLeft);

  horizontalSpacer_top = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  horizontalLayout_top->addItem(horizontalSpacer_top);

  gridLayout_topRight = new QGridLayout();
  gridLayout_topRight->setSpacing(5);

  label_info_filter = new QLabel("Filtro:");
  gridLayout_topRight->addWidget(label_info_filter,0,0,1,1);

  radioButton_opere = new QRadioButton("Opere");
  radioButton_opere->setChecked(true);
  gridLayout_topRight->addWidget(radioButton_opere,1,0,1,1);

  radioButton_Dipinti = new QRadioButton("Dipinto");
  gridLayout_topRight->addWidget(radioButton_Dipinti,2,0,1,1);

  radioButton_Statue = new QRadioButton("Statua");
  gridLayout_topRight->addWidget(radioButton_Statue,3,0,1,1);

  verticalSpacer_radioButtonDown = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);
  gridLayout_topRight->addItem(verticalSpacer_radioButtonDown,4,0,1,1);

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

  
void Trova_LibraryItem::slot_pushButton_search() {
  textEdit_resultFilter->clear();

  textEdit_resultFilter->setStyleSheet("font-size: 10px");

  int num = 0;

  for(Container<SmartAptr>::iterator it = ctp->begin(); it != ctp->end(); ++it) {
    bool toPrint = false;
    QString strToPtint;
    
    QString title(QString::fromStdString((*it).getOpera()->getTitle()));
    QString artist(QString::fromStdString((*it).getOpera()->getArtist()));
    QString location(QString::fromStdString((*it).getOpera()->getLocation()));
    QString yearOfCreation(QString::number((*it).getOpera()->getYearOfCreation()));
        
    Statua* st = dynamic_cast<Statua*>((*it).getOpera());
    
    if((radioButton_opere->isChecked() || radioButton_Statue->isChecked()) && st){
      if(checkBox_tile->isChecked()){
        QString title_f = lineEdit_title->text();
        toPrint = title.contains(title_f, Qt::CaseInsensitive);
      }
      if(checkBox_artist->isChecked()){
        QString artist_f = lineEdit_artist->text();
        toPrint = artist.contains(artist_f, Qt::CaseInsensitive);
      }
      if(checkBox_location->isChecked()){
        QString location_f = lineEdit_location->text();
        toPrint = location.contains(location_f, Qt::CaseInsensitive);
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
      if(checkBox_artist->isChecked()){
        QString artist_f = lineEdit_artist->text();
        toPrint = artist.contains(artist_f, Qt::CaseInsensitive);
      }
      if(checkBox_location->isChecked()){
        QString location_f = lineEdit_location->text();
        toPrint = location.contains(location_f, Qt::CaseInsensitive);
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
      strToPtint.prepend(location.toUpper());
      strToPtint.prepend(" | Ubicazione: " );
      strToPtint.prepend(artist.toUpper());
      strToPtint.prepend(" | Artista: " );
      strToPtint.prepend(title.toUpper());
      strToPtint.prepend(") Titolo: " );
      strToPtint.prepend(QString::number(++num));
      textEdit_resultFilter->append(strToPtint);
      textEdit_resultFilter->show();
    }
  }
  textEdit_resultFilter->setReadOnly(true);
}
