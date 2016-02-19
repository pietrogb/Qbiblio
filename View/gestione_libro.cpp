#include "gestione_libro.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
Gestione_Libro::Gestione_Libro()
{
}

Management_Statua::Management_Statua(QWidget* parent) : QDialog(parent) {
  setWindowTitle(tr("Gestione Statua"));

  qpb_insert = new QPushButton("Insert");
  qpb_remove = new QPushButton("Remove");
  qpb_replace = new QPushButton("Replace");

  qpb_insert->setStyleSheet("text-align: left; padding-left: 5px; width: 80px; height: 25px;");
  qpb_remove->setStyleSheet("text-align: left; padding-left: 5px; width: 80px; height: 25px;");
  qpb_replace->setStyleSheet("text-align: left; padding-left: 5px; width: 80px; height: 25px;");

  ql_title = new QLabel("Titolo");
  ql_artist = new QLabel("Artista");
  ql_location = new QLabel("Ubicazione");
  ql_yearOfCreation = new QLabel("Anno");
  ql_material = new QLabel("Materiale");
  ql_height = new QLabel("Altezza(cm)");

  qle_title = new QLineEdit;
  qle_artist = new QLineEdit;
  qle_location = new QLineEdit;
  qsb_yearOfCreation = new QSpinBox;
  qle_material = new QLineEdit;
  qsb_height = new QSpinBox;

  qsb_yearOfCreation->setMinimum(0);
  qsb_yearOfCreation->setMaximum(2100);
  qsb_yearOfCreation->setValue(2014);
  qsb_height->setMinimum(0);
  qsb_height->setMaximum(10000);
  qsb_height->setValue(1);

  gLayout = new QGridLayout;
  gLayout->setColumnStretch(1, 2);
  gLayout->addWidget(ql_title, 0, 0);
  gLayout->addWidget(qle_title, 0, 1);
  gLayout->addWidget(ql_artist, 1, 0);
  gLayout->addWidget(qle_artist, 1, 1);
  gLayout->addWidget(ql_location, 2, 0);
  gLayout->addWidget(qle_location, 2, 1);
  gLayout->addWidget(ql_yearOfCreation, 3, 0);
  gLayout->addWidget(qsb_yearOfCreation, 3, 1);
  gLayout->addWidget(ql_material, 4, 0);
  gLayout->addWidget(qle_material, 4, 1);
  gLayout->addWidget(ql_height, 5, 0);
  gLayout->addWidget(qsb_height, 5, 1);

  QHBoxLayout* buttonLayout = new QHBoxLayout;
  buttonLayout->addWidget(qpb_insert);
  buttonLayout->addWidget(qpb_remove);
  buttonLayout->addWidget(qpb_replace);

  gLayout->addLayout(buttonLayout, 6, 1, Qt::AlignCenter);

  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->addLayout(gLayout);

  setLayout(mainLayout);

  connect(qpb_insert,SIGNAL(clicked()),this,SLOT(slotInsertST()));
  connect(qpb_remove,SIGNAL(clicked()),this,SLOT(slotRemoveST()));
  connect(qpb_replace,SIGNAL(clicked()),this,SLOT(slotReplaceST()));
}

void Management_Statua::slotInsertST(){
  emit signalInsertStatua();
}

void Management_Statua::slotRemoveST(){
  emit signalRemoveStatua();
}

void Management_Statua::slotReplaceST(){
  ql_title_r = new QLabel("Titolo");
  ql_artist_r = new QLabel("Artista");
  ql_location_r = new QLabel("Ubicazione");
  ql_yearOfCreation_r = new QLabel("Anno");
  ql_material_r = new QLabel("Materiale");
  ql_height_r = new QLabel("Altezza(cm)");

  qle_title_r = new QLineEdit;
  qle_artist_r = new QLineEdit;
  qle_location_r = new QLineEdit;
  qsb_yearOfCreation_r = new QSpinBox;
  qle_material_r = new QLineEdit;
  qsb_height_r = new QSpinBox;

  qsb_yearOfCreation_r -> setMinimum(0);
  qsb_yearOfCreation_r -> setMaximum(2100);
  qsb_yearOfCreation_r -> setValue(2014);
  qsb_height_r -> setMinimum(0);
  qsb_height_r->setMaximum(10000);
  qsb_height_r -> setValue(1);

  gLayout->addWidget(ql_title_r, 7, 0);
  gLayout->addWidget(qle_title_r, 7, 1);
  gLayout->addWidget(ql_artist_r, 8, 0);
  gLayout->addWidget(qle_artist_r, 8, 1);
  gLayout->addWidget(ql_location_r, 9, 0);
  gLayout->addWidget(qle_location_r, 9, 1);
  gLayout->addWidget(ql_yearOfCreation_r, 10, 0);
  gLayout->addWidget(qsb_yearOfCreation_r, 10, 1);
  gLayout->addWidget(ql_material_r, 11, 0);
  gLayout->addWidget(qle_material_r, 11, 1);
  gLayout->addWidget(ql_height_r, 12, 0);
  gLayout->addWidget(qsb_height_r, 12, 1);

  qpb_replace_confirm = new QPushButton("Confirm Replace");

  qpb_replace_confirm->setStyleSheet("text-align: left; padding-left: 5px; width: 70px; height: 25px;");
  qpb_close = new QPushButton("Close");

  qpb_close->setStyleSheet("text-align: left; padding-left: 5px; width: 70px; height: 25px;");

  QHBoxLayout* buttonLayout_control = new QHBoxLayout;
  buttonLayout_control->addWidget(qpb_replace_confirm);
  buttonLayout_control->addWidget(qpb_close);
  gLayout->addLayout(buttonLayout_control, 13, 1, Qt::AlignRight);
  qpb_insert->setEnabled(false);
  qpb_remove->setEnabled(false);
  qpb_replace->setEnabled(false);
  connect(qpb_replace_confirm,SIGNAL(clicked()),this,SLOT(slotReplaceST_c()));
  connect(qpb_close,SIGNAL(clicked()),this,SLOT(close()));
}

void Management_Statua::slotReplaceST_c(){
  emit signalReplaceStatua();
}

Statua* Management_Statua::slotNewStatua(){
  string t = (qle_title->text()).toStdString();
  string a = (qle_artist->text()).toStdString();
  string l = (qle_location->text()).toStdString();
  int y = qsb_yearOfCreation->value();
  string m = (qle_material->text()).toStdString();
  int h = qsb_height->value();

  Statua* st_new = new Statua(t, a, l, y, m, h);
  return st_new;
}

Statua* Management_Statua::slotReplaceStatua(){
  string t_r = (qle_title_r->text()).toStdString();
  string a_r = (qle_artist_r->text()).toStdString();
  string l_r = (qle_location_r->text()).toStdString();
  int y_r = qsb_yearOfCreation_r->value();
  string m_r = (qle_material_r->text()).toStdString();
  int h_r = qsb_height_r->value();

  Statua* st_new_r = new Statua(t_r, a_r, l_r, y_r, m_r, h_r);
  return st_new_r;
}
