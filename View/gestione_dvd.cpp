#include "gestione_dvd.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
Gestione_DVD::Gestione_DVD(QWidget* parent) : QDialog(parent) {
  setWindowTitle(tr("Gestione DVD"));

  qpb_insert = new QPushButton("Inserisci");
  qpb_remove = new QPushButton("Rimuovi");
  qpb_replace = new QPushButton("Sostituisci");

  qpb_insert->setStyleSheet("text-align: center;");
  qpb_remove->setStyleSheet("text-align: center;");
  qpb_replace->setStyleSheet("text-align: center;");


  ql_titolo = new QLabel("Titolo");
  ql_genere = new QLabel("Genere");
  ql_regista = new QLabel("Regista");
  ql_durata = new QLabel("Durata(minuti)");
  ql_dataUscita = new QLabel("Data Uscita");

  qle_titolo = new QLineEdit;
  qle_genere = new QLineEdit;
  qle_regista = new QLineEdit;
  qsb_durata = new QSpinBox;
  qsb_durata->setRange(0,10000);
  qsb_durata->setValue(100);
  qde_dataUscita = new QDateEdit(QDate::currentDate());
  qde_dataUscita->setDisplayFormat( "dd/MM/yyyy");

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

  connect(qpb_insert,SIGNAL(clicked()),this,SLOT(slotInsertDVD()));
  connect(qpb_remove,SIGNAL(clicked()),this,SLOT(slotRemoveDVD()));
  connect(qpb_replace,SIGNAL(clicked()),this,SLOT(slotReplaceDVD()));
}

void Gestione_DVD::slotInsertDVD(){
  emit signalInsertDVD();
}

void Gestione_DVD::slotRemoveDVD(){
  emit signalRemoveDVD();
}

void Gestione_DVD::slotReplaceDVD(){
  ql_titolo_r = new QLabel("Titolo");
  ql_genere_r = new QLabel("Genere");
  ql_regista_r = new QLabel("Regista");
  ql_durata_r = new QLabel("Durata(minuti)");
  ql_dataUscita_r = new QLabel("Data Uscita");

  qle_titolo_r = new QLineEdit;
  qle_genere_r = new QLineEdit;
  qle_regista_r = new QLineEdit;
  qsb_durata_r = new QSpinBox;
  qsb_durata_r->setRange(0,10000);
  qsb_durata_r->setValue(100);
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
  connect(qpb_replace_confirm,SIGNAL(clicked()),this,SLOT(slotReplaceDVD_c()));
  connect(qpb_close,SIGNAL(clicked()),this,SLOT(close()));
}

void Gestione_DVD::slotReplaceDVD_c(){
  emit signalReplaceDVD();
}

DVD* Gestione_DVD::slotNewDVD(){
  string t = (qle_titolo->text()).toStdString();
  string g = (qle_genere->text()).toStdString();
  string r = (qle_regista->text()).toStdString();
  int d = qsb_durata->value();
  QDate u = qde_dataUscita->date();

  DVD* d_new = new DVD(t, g, r, d, u);
  return d_new;
}

DVD* Gestione_DVD::slotReplaceDigitalVersatileDisk(){
  string t_r = (qle_titolo_r->text()).toStdString();
  string g_r = (qle_genere_r->text()).toStdString();
  string r_r = (qle_regista_r->text()).toStdString();
  int d_r = qsb_durata_r->value();
  QDate u_r = qde_dataUscita_r->date();
  DVD* d_new_r = new DVD(t_r, g_r, r_r, d_r, u_r);
  return d_new_r;
}
