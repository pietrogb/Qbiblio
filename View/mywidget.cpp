
#include "mywidget.h"
#include <QDesktopWidget>
#include <QFont>
#include <QGroupBox>
#include <QHeaderView>
#include <QMessageBox>
#include <QPointer>
#include <QString>

MyWidget::MyWidget(QWidget* parent) : QWidget(parent) {
  setWidget();

  /*
  qpb_gestisci_CD = new QPushButton("Gestione CD");
  qpb_gestisci_DVD = new QPushButton("Gestione DVD");
  qpb_gestisci_VHS = new QPushButton("Gestione VHS");
  qpb_gestisci_Libro = new QPushButton("Gestione Libro");
  qpb_find_e = new QPushButton("Cerca Elemento");
  qpb_quit = new QPushButton("Chiudi");

  qpb_gestisci_CD->setStyleSheet("text-align: center; padding-left: 10px; padding-right: 10px; width: 70px; height: 25px;");
  qpb_gestisci_DVD->setStyleSheet("text-align: center; padding-left: 10px; width: 70px; height: 25px;");
  qpb_gestisci_VHS->setStyleSheet("text-align: center; padding-left: 10px; width: 70px; height: 25px;");
  qpb_gestisci_Libro->setStyleSheet("text-align: center; padding-left: 10px; width: 70px; height: 25px;");
  qpb_find_e->setStyleSheet("text-align: center; padding-left: 10px; width: 140px; height: 25px;");
  qpb_quit->setStyleSheet("text-align: center; padding-left: 10px; width: 70px; height: 25px;");


  gridLayout = new QGridLayout();
  gridLayout->setSpacing(5);
  gridLayout->addWidget(qpb_gestisci_CD, 0, 0, 1, 1);
  gridLayout->addWidget(qpb_gestisci_DVD,0, 1, 1, 1);
  gridLayout->addWidget(qpb_gestisci_VHS,0, 2, 1, 1);
  gridLayout->addWidget(qpb_gestisci_Libro,0, 3, 1, 1);
  gridLayout->addWidget(qpb_find_e, 0, 4, 1, 1);

  horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum); //Spacer pulsante Trova
//  horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);

  gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);

  gridLayout->addWidget(qpb_quit, 0, 5, 1, 1);

  connect(qpb_quit, SIGNAL(clicked()), qApp, SLOT(quit()));
  connect(qpb_gestisci_CD, SIGNAL(clicked()), this, SLOT(slotGestioneCdQDialog()));
  connect(qpb_gestisci_DVD, SIGNAL(clicked()), this, SLOT(slotGestioneDvdQDialog()));
  connect(qpb_gestisci_VHS, SIGNAL(clicked()), this, SLOT(slotGestioneVhsQDialog()));
  connect(qpb_gestisci_Libro, SIGNAL(clicked()), this, SLOT(slotGestioneLibroQDialog()));
  connect(qpb_find_e, SIGNAL(clicked()), this, SLOT(slotFindItemQDialog()));*/

  //Creazione tabelle
  createMenuGroupBox();
  createCdGroupBox();
  createDvdGroupBox();
  createVhsGroupBox();
  createLibriGroupBox();
  //fine creazione tabelle

  updateTableResult();

  QVBoxLayout* verticalLayout = new QVBoxLayout(this);
  verticalLayout->setSpacing(2);
  verticalLayout->setContentsMargins(5, 5, 5, 5);
  verticalLayout->addWidget(qgb_Menu,0);
  verticalLayout->addWidget(qgb_CD, 1);
  verticalLayout->addWidget(qgb_Libri, 1);
  verticalLayout->addWidget(qgb_DVD, 1);
  verticalLayout->addWidget(qgb_VHS, 1);
}

void MyWidget::setWidget(){
    setWindowTitle("Programmazione ad Oggetti - Progetto qBiblio - 2016");
    monitorWidth = QApplication::desktop()->width();
    monitorHeight = QApplication::desktop()->height();

    resize(monitorWidth*0.97, monitorHeight*0.95);

    adjustSize();
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
}

/////////////Menu
void MyWidget::createMenuGroupBox(){
    qgb_Menu = new QGroupBox(tr("Operazioni"));


    qpb_gestisci_CD = new QPushButton("Gestisci CD");
    qpb_gestisci_DVD = new QPushButton("Gestisci DVD");
    qpb_gestisci_VHS = new QPushButton("Gestisci VHS");
    qpb_gestisci_Libro = new QPushButton("Gestisci Libro");
    qpb_find_e = new QPushButton("Cerca Elemento");
    qpb_quit = new QPushButton("Chiudi");

    qpb_gestisci_CD->setStyleSheet("text-align: center; padding-left: 10px; padding-right: 10px; width: 70px; height: 25px;");
    qpb_gestisci_DVD->setStyleSheet("text-align: center; padding-left: 10px; width: 70px; height: 25px;");
    qpb_gestisci_VHS->setStyleSheet("text-align: center; padding-left: 10px; width: 70px; height: 25px;");
    qpb_gestisci_Libro->setStyleSheet("text-align: center; padding-left: 10px; width: 70px; height: 25px;");
    qpb_find_e->setStyleSheet("text-align: center; padding-left: 10px; width: 140px; height: 25px;");
    qpb_quit->setStyleSheet("text-align: center; padding-left: 10px; width: 70px; height: 25px;");
    gridLayout = new QGridLayout();
    gridLayout->setSpacing(5);
    gridLayout->addWidget(qpb_gestisci_CD, 0, 0, 1, 1);
    gridLayout->addWidget(qpb_gestisci_DVD,0, 1, 1, 1);
    gridLayout->addWidget(qpb_gestisci_VHS,0, 2, 1, 1);
    gridLayout->addWidget(qpb_gestisci_Libro,0, 3, 1, 1);
    gridLayout->addWidget(qpb_find_e, 0, 4, 1, 1);

    horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum); //Spacer pulsante Trova

    gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);

    gridLayout->addWidget(qpb_quit, 0, 5, 1, 1);

    connect(qpb_quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(qpb_gestisci_CD, SIGNAL(clicked()), this, SLOT(slotGestioneCdQDialog()));
    connect(qpb_gestisci_DVD, SIGNAL(clicked()), this, SLOT(slotGestioneDvdQDialog()));
    connect(qpb_gestisci_VHS, SIGNAL(clicked()), this, SLOT(slotGestioneVhsQDialog()));
    connect(qpb_gestisci_Libro, SIGNAL(clicked()), this, SLOT(slotGestioneLibroQDialog()));
    connect(qpb_find_e, SIGNAL(clicked()), this, SLOT(slotFindItemQDialog()));

    qgb_Menu->setLayout(gridLayout);
}

/////////////CD
void MyWidget::slotGestioneCdQDialog(){
  mCd = new Gestione_CD(this);
  connect(mCd, SIGNAL(signalInsertCD()), this, SLOT(slotInsertCD()));
  connect(mCd, SIGNAL(signalRemoveCD()), this, SLOT(slotRemoveCD()));
  connect(mCd, SIGNAL(signalReplaceCD()), this, SLOT(slotReplaceCD()));
  mCd->exec();
}

void MyWidget::slotInsertCD(){
  SmartPtr ins = mCd->slotNewCD();
  bib.Insert(ins);
  bib.save();
  updateTableResult();
  mCd->close();
}

void MyWidget::slotRemoveCD(){
  SmartPtr del = mCd->slotNewCD();
  bool pres = bib.Remove(del);
  if(!pres){
      QMessageBox err;
      err.setText("Il CD richiesto non è presente");
      err.exec();
  }
  bib.save();
  updateTableResult();
  mCd->close();
}

void MyWidget::slotReplaceCD(){
  SmartPtr older = mCd->slotNewCD();
  SmartPtr newer = mCd->slotReplaceCompactDisk();
  bool pres = bib.Replace(older, newer);
  if(!pres){
      QMessageBox err;
      err.setText("Il CD richiesto non è presente");
      err.exec();
  }
  bib.save();
  updateTableResult();
  mCd->close();
}

//Catalogo CD
void MyWidget::createCdGroupBox(){
  qgb_CD = new QGroupBox(tr("Catalogo CD"));
  tableWidget_CD = new QTableWidget;
  int w_border = (QApplication::desktop()->width())*0.95 - 100;
  tableWidget_CD->setColumnCount(5);
//  tableWidget_CD->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
  tableWidget_CD->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
  tableWidget_CD->setColumnWidth(1,w_border/100*20);
  tableWidget_CD->setColumnWidth(2,w_border/100*20);
  tableWidget_CD->setColumnWidth(3,w_border/100*20);
  tableWidget_CD->setColumnWidth(4,w_border/100*20);
  tableWidget_CD->setColumnWidth(5,w_border/100*20);

  tableWidget_CD->verticalHeader()->setDefaultSectionSize(30);

  tableWidget_CD->setAlternatingRowColors(true);

  tableWidgetCdHeader<<"Titolo"<<"Genere"<<"Artista"<<"Anno d'Uscita"<<"Numero Dischi";
  tableWidget_CD->setHorizontalHeaderLabels(tableWidgetCdHeader);

  tableWidget_CD->verticalHeader()->setVisible(false);

  tableWidget_CD->setEditTriggers(QAbstractItemView::NoEditTriggers);
  tableWidget_CD->setSelectionBehavior(QAbstractItemView::SelectRows);
  tableWidget_CD->setSelectionMode(QAbstractItemView::SingleSelection);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(tableWidget_CD);
  qgb_CD->setLayout(layout);
}

/////////////////DVD
void MyWidget::slotGestioneDvdQDialog(){
  mDvd = new Gestione_DVD(this);
  connect(mDvd, SIGNAL(signalInsertDVD()), this, SLOT(slotInsertDVD()));
  connect(mDvd, SIGNAL(signalRemoveDVD()), this, SLOT(slotRemoveDVD()));
  connect(mDvd, SIGNAL(signalReplaceDVD()), this, SLOT(slotReplaceDVD()));
  mDvd->exec();
}

void MyWidget::slotInsertDVD(){
  SmartPtr ins = mDvd->slotNewDVD();
  bib.Insert(ins);
  bib.save();
  updateTableResult();
  mDvd->close();
}

void MyWidget::slotRemoveDVD(){
  SmartPtr del = mDvd->slotNewDVD();
  bool pres=bib.Remove(del);
  if(!pres){
      QMessageBox err;
      err.setText("Il DVD richiesto non è presente");
      err.exec();
  }
  bib.save();
  updateTableResult();
  mDvd->close();
}

void MyWidget::slotReplaceDVD(){
  LibraryItem* older = mDvd->slotNewDVD();
  LibraryItem* newer = mDvd->slotReplaceDigitalVersatileDisk();
  bool pres = bib.Replace(older, newer);
  if(!pres){
      QMessageBox err;
      err.setText("Il DVD richiesto non è presente");
      err.exec();
  }
  bib.save();
  updateTableResult();
  mDvd->close();
}

void MyWidget::createDvdGroupBox(){
    qgb_DVD = new QGroupBox(tr("Catalogo DVD"));
    //Catalogo DVD
    tableWidget_DVD = new QTableWidget(this);
    int w_border = (QApplication::desktop()->width())*0.95 - 100;
    tableWidget_DVD->setColumnCount(5);
//    tableWidget_DVD->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    tableWidget_DVD->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
    tableWidget_DVD->setColumnWidth(1,w_border/100*20);
    tableWidget_DVD->setColumnWidth(2,w_border/100*20);
    tableWidget_DVD->setColumnWidth(3,w_border/100*20);
    tableWidget_DVD->setColumnWidth(4,w_border/100*20);
    tableWidget_DVD->setColumnWidth(5,w_border/100*20);

    tableWidget_DVD->verticalHeader()->setDefaultSectionSize(30);

    tableWidget_DVD->setAlternatingRowColors(true);

    tableWidgetDvdHeader<<"Titolo"<<"Genere"<<"Regista"<<"Data Uscita"<<"Durata";
    tableWidget_DVD->setHorizontalHeaderLabels(tableWidgetDvdHeader);

    tableWidget_DVD->verticalHeader()->setVisible(false);

    tableWidget_DVD->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget_DVD->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_DVD->setSelectionMode(QAbstractItemView::SingleSelection);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tableWidget_DVD);
    qgb_DVD->setLayout(layout);
}

/////////////////VHS
void MyWidget::slotGestioneVhsQDialog(){
  mVHS = new Gestione_VHS(this);
  connect(mVHS, SIGNAL(signalInsertVHS()), this, SLOT(slotInsertVHS()));
  connect(mVHS, SIGNAL(signalRemoveVHS()), this, SLOT(slotRemoveVHS()));
  connect(mVHS, SIGNAL(signalReplaceVHS()), this, SLOT(slotReplaceVHS()));
  mVHS->exec();
}

void MyWidget::slotInsertVHS(){
  SmartPtr ins = mVHS->slotNewVHS();
  bib.Insert(ins);
  bib.save();
  updateTableResult();
  mVHS->close();
}

void MyWidget::slotRemoveVHS(){
  SmartPtr del = mVHS->slotNewVHS();
  bool pres = bib.Remove(del);
  if(!pres){
      QMessageBox err;
      err.setText("La VHS richiesta non è presente");
      err.exec();
  }
  bib.save();
  updateTableResult();
  mVHS->close();
}

void MyWidget::slotReplaceVHS(){
  SmartPtr older = mVHS->slotNewVHS();
  SmartPtr newer = mVHS->slotReplaceVideoCassetta();
  bool pres = bib.Replace(older, newer);
  if(!pres){
      QMessageBox err;
      err.setText("La VHS richiesta non è presente");
      err.exec();
  }
  bib.save();
  updateTableResult();
  mVHS->close();
}

void MyWidget::createVhsGroupBox(){
    qgb_VHS = new QGroupBox(tr("Catalogo VHS"));
    //Catalogo VHS
      tableWidget_VHS = new QTableWidget(this);

      int w_border = (QApplication::desktop()->width())*0.95 - 100;
      tableWidget_VHS->setColumnCount(5);
//      tableWidget_VHS->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
      tableWidget_VHS->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
      tableWidget_VHS->setColumnWidth(1,w_border/100*20);
      tableWidget_VHS->setColumnWidth(2,w_border/100*20);
      tableWidget_VHS->setColumnWidth(3,w_border/100*20);
      tableWidget_VHS->setColumnWidth(4,w_border/100*20);
      tableWidget_VHS->setColumnWidth(5,w_border/100*20);

      tableWidget_VHS->verticalHeader()->setDefaultSectionSize(30);

      tableWidget_VHS->setAlternatingRowColors(true);

      tableWidgetVhsHeader<<"Titolo"<<"Genere"<<"Regista"<<"Data Uscita"<<"Durata";
      tableWidget_VHS->setHorizontalHeaderLabels(tableWidgetVhsHeader);

      tableWidget_VHS->verticalHeader()->setVisible(false);

      tableWidget_VHS->setEditTriggers(QAbstractItemView::NoEditTriggers);
      tableWidget_VHS->setSelectionBehavior(QAbstractItemView::SelectRows);
      tableWidget_VHS->setSelectionMode(QAbstractItemView::SingleSelection);
      QVBoxLayout *layout = new QVBoxLayout;
      layout->addWidget(tableWidget_VHS);
      qgb_VHS->setLayout(layout);

}

////////////////Libro
void MyWidget::slotGestioneLibroQDialog(){
  mLibro = new Gestione_Libro(this);
  connect(mLibro, SIGNAL(signalInsertLibro()), this, SLOT(slotInsertLibro()));
  connect(mLibro, SIGNAL(signalRemoveLibro()), this, SLOT(slotRemoveLibro()));
  connect(mLibro, SIGNAL(signalReplaceLibro()), this, SLOT(slotReplaceLibro()));
  mLibro->exec();
}

void MyWidget::slotInsertLibro(){
  SmartPtr ins = mLibro->slotNewLibro();
  bib.Insert(ins);
  bib.save();
  updateTableResult();
  mLibro->close();
}

void MyWidget::slotRemoveLibro(){
  SmartPtr del = mLibro->slotNewLibro();
  bool pres = bib.Remove(del);
  if(!pres){
      QMessageBox err;
      err.setText("Il libro richiesto non è presente");
      err.exec();
  }
  bib.save();
  updateTableResult();
  mLibro->close();
}

void MyWidget::slotReplaceLibro(){
  SmartPtr older = mLibro->slotNewLibro();
  SmartPtr newer = mLibro->slotReplaceLibro();
  bool pres = bib.Replace(older, newer);
  if(!pres){
      QMessageBox err;
      err.setText("Il libro richiesto non è presente");
      err.exec();
  }
  bib.save();
  updateTableResult();
  mLibro->close();
}

void MyWidget::createLibriGroupBox(){
  qgb_Libri = new QGroupBox(tr("Catalogo Libri"));
  //Catalogo Libri
    tableWidget_Libri = new QTableWidget(this);

    int w_border = (QApplication::desktop()->width())*0.95 - 100;
    tableWidget_Libri->setColumnCount(5);
//    tableWidget_Libri->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    tableWidget_Libri->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
    tableWidget_Libri->setColumnWidth(1,w_border/100*20);
    tableWidget_Libri->setColumnWidth(2,w_border/100*20);
    tableWidget_Libri->setColumnWidth(3,w_border/100*20);
    tableWidget_Libri->setColumnWidth(4,w_border/100*20);
    tableWidget_Libri->setColumnWidth(5,w_border/100*20);

    tableWidget_Libri->verticalHeader()->setDefaultSectionSize(30);

    tableWidget_Libri->setAlternatingRowColors(true);

    tableWidgetLibriHeader<<"Titolo"<<"Genere"<<"Autore"<<"Anno d'Uscita"<<"Editore";
    tableWidget_Libri->setHorizontalHeaderLabels(tableWidgetLibriHeader);

    tableWidget_Libri->verticalHeader()->setVisible(false);

    tableWidget_Libri->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget_Libri->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_Libri->setSelectionMode(QAbstractItemView::SingleSelection);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tableWidget_Libri);
    qgb_Libri->setLayout(layout);
}


void MyWidget::slotFindItemQDialog(){
  t_el = new Trova_Elemento(this, &bib);
  t_el->resize(monitorWidth*0.6, monitorHeight*0.5);
  t_el->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, t_el->size(), qApp->desktop()->availableGeometry()));
  t_el->exec();
}


void MyWidget::updateTableResult(){
  tableWidget_Libri->setRowCount(0);
  tableWidget_CD->setRowCount(0);
  tableWidget_DVD->setRowCount(0);
  tableWidget_VHS->setRowCount(0);
  //Richiama Libreria;
  for(int i=0; i<bib.size(); ++i){
  //for(Container<LibraryItem*>::Iterator it = b.begin(); it != b.end(); ++it) {
    const int ultm_riga_Libro = tableWidget_Libri->rowCount();
    const int ultm_riga_CD = tableWidget_CD->rowCount();
    const int ultm_riga_DVD = tableWidget_DVD->rowCount();
    const int ultm_riga_VHS = tableWidget_VHS->rowCount();
    //Catalogo Libri
    Libro* l = dynamic_cast<Libro*>(bib.getItem(i));
    if(l){
        //tableWidgetLibriHeader<<"Titolo"<<"Genere"<<"Autore"<<"Anno d'Uscita"<<"Editore";
      tableWidget_Libri->insertRow(ultm_riga_Libro);
      tableWidget_Libri->setItem(ultm_riga_Libro, 0, new QTableWidgetItem(QString::fromStdString(l->getTitolo())));
      tableWidget_Libri->setItem(ultm_riga_Libro, 1, new QTableWidgetItem(QString::fromStdString(l->getGenere())));
      tableWidget_Libri->setItem(ultm_riga_Libro, 2, new QTableWidgetItem(QString::fromStdString(l->getAutore())));
      tableWidget_Libri->setItem(ultm_riga_Libro, 3, new QTableWidgetItem(QString::number(l->getAnnoUscita())));
      tableWidget_Libri->setItem(ultm_riga_Libro, 4, new QTableWidgetItem(QString::fromStdString(l->getEditore())));

      for(int j=0; j<5; j++){
          tableWidget_Libri->item(ultm_riga_Libro,j)->setTextAlignment(Qt::AlignCenter);
      }
    }
    //Catalogo CD
    CD* c = dynamic_cast<CD*>(bib.getItem(i));
    if(c){
//     tableWidgetCdHeader<<"Titolo"<<"Genere"<<"Artista"<<"Anno d'Uscita"<<"Numero Dischi";
      tableWidget_CD->insertRow(ultm_riga_CD);
      tableWidget_CD->setItem(ultm_riga_CD, 0, new QTableWidgetItem(QString::fromStdString(c->getTitolo())));
      tableWidget_CD->setItem(ultm_riga_CD, 1, new QTableWidgetItem(QString::fromStdString(c->getGenere())));
      tableWidget_CD->setItem(ultm_riga_CD, 2, new QTableWidgetItem(QString::fromStdString(c->getArtista())));
      tableWidget_CD->setItem(ultm_riga_CD, 3, new QTableWidgetItem(QString::number(c->getAnnoUscita())));
      tableWidget_CD->setItem(ultm_riga_CD, 4, new QTableWidgetItem(QString::number(c->getDischi())));

      for(int j=0; j<5; j++){
          tableWidget_CD->item(ultm_riga_CD,j)->setTextAlignment(Qt::AlignCenter);
      }
    }
    //catalogo DVD;
    DVD* d = dynamic_cast<DVD*>(bib.getItem(i));
//    if(typeid(bib.getItem(i)) == typeid(DVD*)){
    if(d){
      tableWidget_DVD->insertRow(ultm_riga_DVD);
      tableWidget_DVD->setItem(ultm_riga_DVD, 0, new QTableWidgetItem(QString::fromStdString(d->getTitolo())));
      tableWidget_DVD->setItem(ultm_riga_DVD, 1, new QTableWidgetItem(QString::fromStdString(d->getGenere())));
      tableWidget_DVD->setItem(ultm_riga_DVD, 2, new QTableWidgetItem(QString::fromStdString(d->getRegista())));
      tableWidget_DVD->setItem(ultm_riga_DVD, 3, new QTableWidgetItem((d->getDataUscita()).toString("yyyy.MM.dd")));
      tableWidget_DVD->setItem(ultm_riga_DVD, 4, new QTableWidgetItem(QString::number(d->getDurata())));

      for(int j=0; j<5; j++){
          tableWidget_DVD->item(ultm_riga_DVD,j)->setTextAlignment(Qt::AlignCenter);
      }
    }
//catalogo VHS; fare conversione con typeid
    VHS* v = dynamic_cast<VHS*>(bib.getItem(i));
//    if(typeid(bib.getItem(i)) == typeid(VHS*)){
    if(v){
      tableWidget_VHS->insertRow(ultm_riga_VHS);
      tableWidget_VHS->setItem(ultm_riga_VHS, 0, new QTableWidgetItem(QString::fromStdString(v->getTitolo())));
      tableWidget_VHS->setItem(ultm_riga_VHS, 1, new QTableWidgetItem(QString::fromStdString(v->getGenere())));
      tableWidget_VHS->setItem(ultm_riga_VHS, 2, new QTableWidgetItem(QString::fromStdString(v->getRegista())));
      tableWidget_VHS->setItem(ultm_riga_VHS, 3, new QTableWidgetItem((v->getDataUscita()).toString("yyyy.MM.dd")));
      tableWidget_VHS->setItem(ultm_riga_VHS, 4, new QTableWidgetItem(QString::number(v->getDurata())));

      for(int j=0; j<5; j++){
          tableWidget_VHS->item(ultm_riga_VHS,j)->setTextAlignment(Qt::AlignCenter);
      }
    }
  }
}
