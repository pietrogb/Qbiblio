#ifndef Trova_LibraryItem_H
#define Trova_LibraryItem_H

#include "../Model/Biblio.h"

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


class Trova_LibraryItem : public QDialog {
  Q_OBJECT
public:
  Trova_LibraryItem(QWidget*, Container<SmartAptr>* );
  ~Trova_LibraryItem() {}
private:
  Container<SmartAptr>* ctp;

  QGridLayout* gridLayout_main;
  QGridLayout* gridLayout_topLeft;
  QGridLayout* gridLayout_topRight;

  QHBoxLayout* horizontalLayout_top;
  QHBoxLayout* horizontalLayout_bottom;

  QCheckBox* checkBox_tile;
  QCheckBox* checkBox_artist;
  QCheckBox* checkBox_location;
  QCheckBox* checkBox_yearOfCreation;

  QLabel* label_title;
  QLabel* label_artist;
  QLabel* label_location;
  QLabel* label_yearOfCreation;
  QLabel* label_info_filter;
  
  QLineEdit* lineEdit_title;
  QLineEdit* lineEdit_artist;
  QLineEdit* lineEdit_location;
  QLineEdit* lineEdit_yearOfCreation;

  QSpacerItem* horizontalSpacer_top;
  QSpacerItem* verticalSpacer_radioButtonDown;
  QSpacerItem* horizontalSpacer_bottom;

  QRadioButton* radioButton_opere;
  QRadioButton* radioButton_Dipinti;
  QRadioButton* radioButton_Statue;

  QTextEdit* textEdit_resultFilter;
  
  QPushButton* pushButton_search;
  QPushButton* pushButton_close;
public slots:
  void slot_pushButton_search();
};

#endif
