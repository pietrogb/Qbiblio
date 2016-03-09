#include "gestione_cd.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
Gestione_CD::Gestione_CD(QWidget* parent) : QDialog(parent) {
  setWindowTitle(tr("Gestione CD"));

  qpb_insert = new QPushButton("Inserisci");
  qpb_remove = new QPushButton("Rimuovi");
  qpb_replace = new QPushButton("Sostituisci");

  qpb_insert->setStyleSheet("text-align: center;");
  qpb_remove->setStyleSheet("text-align: center;");
  qpb_replace->setStyleSheet("text-align: center;");

  ql_titolo = new QLabel("Titolo");
  ql_genere = new QLabel("Genere");
  ql_artista = new QLabel("Artista");
  ql_annoUscita = new QLabel("Anno d'uscita");
  ql_nDischi = new QLabel("Numero Dischi");

  qle_titolo = new QLineEdit;
  qle_genere = new QLineEdit;
  qle_artista = new QLineEdit;
  qsb_annoUscita = new QSpinBox;
  qsb_nDischi = new QSpinBox;

  qsb_annoUscita->setMinimum(0);
  qsb_annoUscita->setMaximum(2100);
  qsb_annoUscita->setValue(2016);

  qsb_nDischi->setMinimum(0);
  qsb_nDischi->setValue(1);

  gLayout = new QGridLayout;
  gLayout->setColumnStretch(1, 2);
  gLayout->addWidget(ql_titolo, 0, 0);
  gLayout->addWidget(qle_titolo, 0, 1);
  gLayout->addWidget(ql_genere, 1, 0);
  gLayout->addWidget(qle_genere, 1, 1);
  gLayout->addWidget(ql_artista, 2, 0);
  gLayout->addWidget(qle_artista, 2, 1);
  gLayout->addWidget(ql_annoUscita, 3, 0);
  gLayout->addWidget(qsb_annoUscita, 3, 1);
  gLayout->addWidget(ql_nDischi, 4, 0);
  gLayout->addWidget(qsb_nDischi, 4, 1);

  QHBoxLayout* buttonLayout = new QHBoxLayout;
  buttonLayout->addWidget(qpb_insert);
  buttonLayout->addWidget(qpb_remove);
  buttonLayout->addWidget(qpb_replace);

  gLayout->addLayout(buttonLayout, 6, 1, Qt::AlignCenter);

  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->addLayout(gLayout);

  setLayout(mainLayout);

  connect(qpb_insert,SIGNAL(clicked()),this,SLOT(slotInsertCD()));
  connect(qpb_remove,SIGNAL(clicked()),this,SLOT(slotRemoveCD()));
  connect(qpb_replace,SIGNAL(clicked()),this,SLOT(slotReplaceCD()));
}

void Gestione_CD::slotInsertCD(){
  emit signalInsertCD();
}

void Gestione_CD::slotRemoveCD(){
  emit signalRemoveCD();
}

void Gestione_CD::slotReplaceCD(){
  ql_titolo_r = new QLabel("Titolo");
  ql_genere_r = new QLabel("Genere");
  ql_artista_r = new QLabel("Artista");
  ql_annoUscita_r = new QLabel("Anno d'uscita");
  ql_nDischi_r = new QLabel("Numero Dischi");

  qle_titolo_r = new QLineEdit;
  qle_genere_r = new QLineEdit;
  qle_artista_r = new QLineEdit;
  qsb_annoUscita_r = new QSpinBox;
  qsb_nDischi_r = new QSpinBox;

  qsb_annoUscita_r->setMinimum(0);
  qsb_annoUscita_r->setMaximum(2100);
  qsb_annoUscita_r->setValue(2016);
  qsb_nDischi_r->setMinimum(1);
  qsb_nDischi_r->setValue(1);

  gLayout->addWidget(ql_titolo_r, 5, 0);
  gLayout->addWidget(qle_titolo_r, 5, 1);
  gLayout->addWidget(ql_genere_r, 6, 0);
  gLayout->addWidget(qle_genere_r, 6, 1);
  gLayout->addWidget(ql_artista_r, 7, 0);
  gLayout->addWidget(qle_artista_r, 7, 1);
  gLayout->addWidget(ql_annoUscita_r, 8, 0);
  gLayout->addWidget(qsb_annoUscita_r, 8, 1);
  gLayout->addWidget(ql_nDischi_r, 9, 0);
  gLayout->addWidget(qsb_nDischi_r, 9, 1);


  qpb_replace_confirm = new QPushButton("Conferma");
  qpb_replace_confirm->setStyleSheet("text-align: center;");

  qpb_close = new QPushButton("Chiudi");
  qpb_close->setStyleSheet("text-align: center;");

  QHBoxLayout* buttonLayout_control = new QHBoxLayout;
  buttonLayout_control->addWidget(qpb_replace_confirm);
  buttonLayout_control->addWidget(qpb_close);
  gLayout->addLayout(buttonLayout_control, 10, 1, Qt::AlignRight);
  qpb_insert->setEnabled(false);
  qpb_remove->setEnabled(false);
  qpb_replace->setEnabled(false);
  connect(qpb_replace_confirm,SIGNAL(clicked()),this,SLOT(slotReplaceCD_c()));
  connect(qpb_close,SIGNAL(clicked()),this,SLOT(close()));
}

void Gestione_CD::slotReplaceCD_c(){
  emit signalReplaceCD();
}


CD* Gestione_CD::slotNewCD(){
  string t = (qle_titolo->text()).toStdString();
  string g = (qle_genere->text()).toStdString();
  string a = (qle_artista->text()).toStdString();
  int u = qsb_annoUscita->value();
  int d = qsb_nDischi->value();

  CD* cd_new = new CD(t, g, a, u, d);
  return cd_new;
}

CD* Gestione_CD::slotReplaceCompactDisk(){
  string t_r = (qle_titolo_r->text()).toStdString();
  string g_r = (qle_genere_r->text()).toStdString();
  string a_r = (qle_artista_r->text()).toStdString();
  int u_r = qsb_annoUscita_r->value();
  int d_r = qsb_nDischi_r->value();

  CD* cd_new_r = new CD(t_r, g_r, a_r, u_r, d_r);
  return cd_new_r;
}
