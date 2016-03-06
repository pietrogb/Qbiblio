#include "gestione_libro.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
Gestione_Libro::Gestione_Libro(QWidget* parent) : QDialog(parent) {
  setWindowTitle(tr("Gestione Libri"));

  qpb_insert = new QPushButton("Insert");
  qpb_remove = new QPushButton("Remove");
  qpb_replace = new QPushButton("Replace");

  qpb_insert->setStyleSheet("text-align: left; padding-left: 5px; width: 80px; height: 25px;");
  qpb_remove->setStyleSheet("text-align: left; padding-left: 5px; width: 80px; height: 25px;");
  qpb_replace->setStyleSheet("text-align: left; padding-left: 5px; width: 80px; height: 25px;");

  ql_titolo = new QLabel("Titolo");
  ql_genere = new QLabel("Genere");
  ql_autore = new QLabel("Autore");
  ql_annoUscita = new QLabel("Anno d'uscita");
  ql_editore = new QLabel("Editore");

  qle_titolo = new QLineEdit;
  qle_genere = new QLineEdit;
  qle_autore = new QLineEdit;
  qsb_annoUscita = new QSpinBox;
  qle_editore = new QLineEdit;

  qsb_annoUscita->setMinimum(0);
  qsb_annoUscita->setMaximum(2100);
  qsb_annoUscita->setValue(2016);

  gLayout = new QGridLayout;
  gLayout->setColumnStretch(1, 2);
  gLayout->addWidget(ql_titolo, 0, 0);
  gLayout->addWidget(qle_titolo, 0, 1);
  gLayout->addWidget(ql_genere, 1, 0);
  gLayout->addWidget(qle_genere, 1, 1);
  gLayout->addWidget(ql_autore, 2, 0);
  gLayout->addWidget(qle_autore, 2, 1);
  gLayout->addWidget(ql_annoUscita, 3, 0);
  gLayout->addWidget(qsb_annoUscita, 3, 1);
  gLayout->addWidget(ql_editore, 4, 0);
  gLayout->addWidget(qle_editore, 4, 1);

  QHBoxLayout* buttonLayout = new QHBoxLayout;
  buttonLayout->addWidget(qpb_insert);
  buttonLayout->addWidget(qpb_remove);
  buttonLayout->addWidget(qpb_replace);

  gLayout->addLayout(buttonLayout, 6, 1, Qt::AlignCenter);

  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->addLayout(gLayout);

  setLayout(mainLayout);

  connect(qpb_insert,SIGNAL(clicked()),this,SLOT(slotInsertLib()));
  connect(qpb_remove,SIGNAL(clicked()),this,SLOT(slotRemoveLib()));
  connect(qpb_replace,SIGNAL(clicked()),this,SLOT(slotReplaceLib()));
}

void Gestione_Libro::slotInsertLib(){
  emit signalInsertLibro();
}

void Gestione_Libro::slotRemoveLib(){
  emit signalRemoveLibro();
}

void Gestione_Libro::slotReplaceLib(){
  ql_titolo_r = new QLabel("Titolo");
  ql_genere_r = new QLabel("Genere");
  ql_autore_r = new QLabel("Autore");
  ql_annoUscita_r = new QLabel("Anno d'uscita");
  ql_editore_r = new QLabel("Editore");

  qle_titolo_r = new QLineEdit;
  qle_genere_r = new QLineEdit;
  qle_autore_r = new QLineEdit;
  qsb_annoUscita_r = new QSpinBox;
  qle_editore_r = new QLineEdit;

  qsb_annoUscita_r->setMinimum(0);
  qsb_annoUscita_r->setMaximum(2100);
  qsb_annoUscita_r->setValue(2016);

  gLayout->addWidget(ql_titolo_r, 5, 0);
  gLayout->addWidget(qle_titolo_r, 5, 1);
  gLayout->addWidget(ql_genere_r, 6, 0);
  gLayout->addWidget(qle_genere_r, 6, 1);
  gLayout->addWidget(ql_autore_r, 7, 0);
  gLayout->addWidget(qle_autore_r, 7, 1);
  gLayout->addWidget(ql_annoUscita_r, 8, 0);
  gLayout->addWidget(qsb_annoUscita_r, 8, 1);
  gLayout->addWidget(ql_editore_r, 9, 0);
  gLayout->addWidget(qle_editore_r, 9, 1);


  qpb_replace_confirm = new QPushButton("Confirm Replace");

  qpb_replace_confirm->setStyleSheet("text-align: left; padding-left: 5px; width: 70px; height: 25px;");
  qpb_close = new QPushButton("Close");

  qpb_close->setStyleSheet("text-align: left; padding-left: 5px; width: 70px; height: 25px;");

  QHBoxLayout* buttonLayout_control = new QHBoxLayout;
  buttonLayout_control->addWidget(qpb_replace_confirm);
  buttonLayout_control->addWidget(qpb_close);
  gLayout->addLayout(buttonLayout_control, 10, 1, Qt::AlignRight);
  qpb_insert->setEnabled(false);
  qpb_remove->setEnabled(false);
  qpb_replace->setEnabled(false);
  connect(qpb_replace_confirm,SIGNAL(clicked()),this,SLOT(slotReplaceLib_c()));
  connect(qpb_close,SIGNAL(clicked()),this,SLOT(close()));
}

void Gestione_Libro::slotReplaceLib_c(){
  emit signalReplaceLibro();
}


Libro* Gestione_Libro::slotNewLibro(){
  string t = (qle_titolo->text()).toStdString();
  string g = (qle_genere->text()).toStdString();
  string a = (qle_autore->text()).toStdString();
  int u = qsb_annoUscita->value();
  string e = (qle_editore->text()).toStdString();

  Libro* l_new = new Libro(t, g, a, u, e);
  return l_new;
}

Libro* Gestione_Libro::slotReplaceLibro(){
  string t_r = (qle_titolo->text()).toStdString();
  string g_r = (qle_genere->text()).toStdString();
  string a_r = (qle_autore->text()).toStdString();
  int u_r = qsb_annoUscita->value();
  string e_r = (qle_editore->text()).toStdString();

  Libro* l_new_r = new Libro(t_r, g_r, a_r, u_r, e_r);
  return l_new_r;
}
