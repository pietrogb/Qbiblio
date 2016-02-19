#include "gestione_VHS.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
Gestione_VHS::Gestione_VHS(QWidget* parent) : QDialog(parent) {
  setWindowTitle(tr("Gestione VHS"));

  qpb_insert = new QPushButton("Insert");
  qpb_remove = new QPushButton("Remove");
  qpb_replace = new QPushButton("Replace");

  qpb_insert->setStyleSheet("text-align: left; padding-left: 5px; width: 80px; height: 25px;");
  qpb_remove->setStyleSheet("text-align: left; padding-left: 5px; width: 80px; height: 25px;");
  qpb_replace->setStyleSheet("text-align: left; padding-left: 5px; width: 80px; height: 25px;");


  ql_titolo = new QLabel("Titolo");
  ql_genere = new QLabel("Genere");
  ql_regista = new QLabel("Regista");
  ql_durata = new QLabel("Durata");
  ql_dataUscita = new QLabel("Data Uscita");

  qle_titolo = new QLineEdit;
  qle_genere = new QLineEdit;
  qle_regista = new QLineEdit;
  qsb_durata = new QSpinBox;
  qde_dataUscita = new QDateEdit(QDate::currentDate());

  gLayout = new QGridLayout;
  gLayout->setColumnStretch(1, 2);
  gLayout->addWidget(ql_titolo, 0, 0);
  gLayout->addWidget(qle_titolo, 0, 1);
  gLayout->addWidget(ql_genere, 1, 0);
  gLayout->addWidget(qle_genere, 1, 1);
  gLayout->addWidget(ql_regista, 2, 0);
  gLayout->addWidget(qle_regista, 2, 1);
  gLayout->addWidget(ql_durata, 3, 0);
  gLayout->addWidget(qsb_durata, 3, 1);
  gLayout->addWidget(ql_dataUscita, 4, 0);
  gLayout->addWidget(qde_dataUscita, 4, 1);

  QHBoxLayout* buttonLayout = new QHBoxLayout;
  buttonLayout->addWidget(qpb_insert);
  buttonLayout->addWidget(qpb_remove);
  buttonLayout->addWidget(qpb_replace);

  gLayout->addLayout(buttonLayout, 6, 1, Qt::AlignCenter);

  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->addLayout(gLayout);

  setLayout(mainLayout);

  connect(qpb_insert,SIGNAL(clicked()),this,SLOT(slotInsertVHS()));
  connect(qpb_remove,SIGNAL(clicked()),this,SLOT(slotRemoveVHS()));
  connect(qpb_replace,SIGNAL(clicked()),this,SLOT(slotReplaceVHS()));
}

void Gestione_VHS::slotInsertVHS(){
  emit signalInsertVHS();
}

void Gestione_VHS::slotRemoveVHS(){
  emit signalRemoveStatua();
}

void Gestione_VHS::slotReplaceVHS()){
  ql_titolo_r = new QLabel("Titolo");
  ql_genere_r = new QLabel("Genere");
  ql_regista_r = new QLabel("Regista");
  ql_durata_r = new QLabel("Durata");
  ql_dataUscita_r = new QLabel("Data Uscita");

  qle_titolo_r = new QLineEdit;
  qle_genere_r = new QLineEdit;
  qle_regista_r = new QLineEdit;
  qsb_durata_r = new QSpinBox;
  qde_dataUscita_r = new QDateEdit(QDate::currentDate());

  gLayout->addWidget(ql_titolo_r, 5, 0);
  gLayout->addWidget(qle_titolo_r, 5, 1);
  gLayout->addWidget(ql_genere_r, 6, 0);
  gLayout->addWidget(qle_genere_r, 6, 1);
  gLayout->addWidget(ql_regista_r, 7, 0);
  gLayout->addWidget(qle_regista_r, 7, 1);
  gLayout->addWidget(ql_durata_r, 8, 0);
  gLayout->addWidget(qsb_durata_r, 8, 1);
  gLayout->addWidget(ql_dataUscita_r, 9, 0);
  gLayout->addWidget(qde_dataUscita_r, 9, 1);

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
  connect(qpb_replace_confirm,SIGNAL(clicked()),this,SLOT(slotReplaceVHS_c()));
  connect(qpb_close,SIGNAL(clicked()),this,SLOT(close()));
}

void Gestione_VHS::slotReplaceVHS_c(){
  emit signalReplaceVHS();
}

VHS* Gestione_VHS::slotNewVHS(){
  QString t = qle_titolo->text();
  QString g = qle_genere->text();
  QString r = qle_regista->text();
  int d = qsb_durata->value();
  QDate u = qde_dataUscita->text();

  VHS* v_new = new VHS(t, g, r, d, u);
  return v_new;
}

VHS* Gestione_VHS::slotReplaceVHS(){
  QString t_r = qle_titolo_r->text();
  QString g_r = qle_genere_r->text();
  QString r_r = qle_regista_r->text();
  int d_r = qsb_durata_r->value();
  QDate u_r = qde_dataUscita_r->text();

  VHS* v_new_r = new VHS(t_r, g_r, r_r, d_r, u_r);
  return v_new_r;
}
