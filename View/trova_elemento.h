#ifndef TROVA_ELEMENTO_H
#define TROVA_ELEMENTO_H

#include "../Model/biblio.h"

#include <QCheckBox>
#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSpacerItem>
#include <QTextEdit>
#include <QWidget>


class Trova_Elemento : public QDialog {
  Q_OBJECT
public:
  Trova_Elemento(QWidget*, Biblio* );
  ~Trova_Elemento() {}
private:
  Container<SmartPtr> items;

  QGridLayout* gridLayout_main;
  QGridLayout* gridLayout_topLeft;
  QGridLayout* gridLayout_topRight;

  QHBoxLayout* horizontalLayout_top;
  QHBoxLayout* horizontalLayout_bottom;

  QCheckBox* checkBox_titolo;
  QCheckBox* checkBox_autore;
  QCheckBox* checkBox_genere;

  QLabel* label_titolo;
  QLabel* label_autore;
  QLabel* label_genere;
  QLabel* label_info_filter;
  QLabel* label_cerca;
  
  QLineEdit* lineEdit_titolo;
  QLineEdit* lineEdit_autore;
  QLineEdit* lineEdit_genere;
  QLineEdit* lineEdit_yearOfCreation;

  QSpacerItem* horizontalSpacer_top;
  QSpacerItem* verticalSpacer_radioButtonDown;
  QSpacerItem* horizontalSpacer_bottom;

  QRadioButton* radioButton_all;
  QRadioButton* radioButton_Libri;
  QRadioButton* radioButton_CD;
  QRadioButton* radioButton_DVD;
  QRadioButton* radioButton_VHS;

  QTextEdit* textEdit_resultFilter;
  
  QPushButton* pushButton_search;
  QPushButton* pushButton_close;
public slots:
  void slot_start_search();
};

#endif
