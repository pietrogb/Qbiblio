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

#include "../Model/container.h"
#include "../Model/smartptr.h"
#include "../Model/libraryitem.h"
#include "../Model/cd.h"
#include "../Model/dvd.h"
#include "../Model/film.h"
#include "../Model/libro.h"
#include "../Model/vhs.h"

#include "../View/"

class MyWidget : public QWidget {
  Q_OBJECT
public:
  MyWidget(QWidget* parent = 0);
  ~MyWidget() {}
private:
  Biblio bib;
  QTableWidget* tableWidget;
  QStringList tableWidgetHeader;
  int monitorWidth;
  int monitorHeight;
  QPushButton* qpb_manage_st;
  QPushButton* qpb_manage_di;
  QPushButton* qpb_find_o;
  QPushButton* qpb_quit;
  QSpacerItem* horizontalSpacer;
  QVBoxLayout* verticalLayout;
  QGridLayout* gridLayout;

  Gestione_CD* mCd;
  Gestione_DVD* mDvd;
  Gestione_VHS* mVHS;
  Gestione_Libro* mLibro;
  Trova_LibraryItem* fli;

public slots:
	void slotGestioneCdQDialog();
	void slotGestioneDvdQDialog();
	void slotGestioneVhsQDialog();
	void slotGestioneLibroQDialog();
  void slotFindItemQDialog();
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
