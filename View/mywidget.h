#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QApplication>
#include <QGridLayout>
#include <QIcon>
#include <QMainWindow>
#include <QPushButton>
#include <QSize>
#include <QSpacerItem>
#include <QStringList>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "../Model/biblio.h"

#include "../View/gestione_libro.h"
#include "gestione_cd.h"
#include "gestione_dvd.h"
#include "gestione_vhs.h"
//#include "trova_elemento.h"


class MyWidget : public QWidget {
  Q_OBJECT
public:
  MyWidget(QWidget* parent = 0);
  ~MyWidget() {}
private:
  Biblio bib;
  QTableWidget* tableWidget_CD;
  QTableWidget* tableWidget_DVD;
  QTableWidget* tableWidget_VHS;
  QTableWidget* tableWidget_Libri;
  QStringList tableWidgetHeader;
  int monitorWidth;
  int monitorHeight;
  QPushButton* qpb_gestisci_CD;
  QPushButton* qpb_gestisci_DVD;
  QPushButton* qpb_gestisci_VHS;
  QPushButton* qpb_gestisci_Libro;
  QPushButton* qpb_find_e;
  QPushButton* qpb_quit;
  QSpacerItem* horizontalSpacer;
  QVBoxLayout* verticalLayout;
  QGridLayout* gridLayout;

  Gestione_CD* mCd;
  Gestione_DVD* mDvd;
  Gestione_VHS* mVHS;
  Gestione_Libro* mLibro;
//  Trova_Elemento* t_el;

public slots:
	void slotGestioneCdQDialog();
	void slotGestioneDvdQDialog();
	void slotGestioneVhsQDialog();
	void slotGestioneLibroQDialog();
//  void slotFindItemQDialog();
  void slotInsertCD();
  void slotInsertDVD();
  void slotInsertVHS();
  void slotInsertLibro();
  void slotRemoveCD();
  void slotRemoveDVD();
  void slotRemoveVHS();
  void slotRemoveLibro();
  void slotReplaceCD();
  void slotReplaceDVD();
  void slotReplaceVHS();
  void slotReplaceLibro();
  void updateTableResult();
};

#endif
