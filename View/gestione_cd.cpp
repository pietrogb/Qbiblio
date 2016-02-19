#include "gestione_CD.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
Gestione_CD::Gestione_CD(QWidget* parent) : QDialog(parent) {
  setWindowTitle(tr("Gestione CD"));

  qpb_insert = new QPushButton("Insert");
  qpb_remove = new QPushButton("Remove");
  qpb_replace = new QPushButton("Replace");

  qpb_insert->setStyleSheet("text-align: left; padding-left: 5px; width: 80px; height: 25px;");
  qpb_remove->setStyleSheet("text-align: left; padding-left: 5px; width: 80px; height: 25px;");
  qpb_replace->setStyleSheet("text-align: left; padding-left: 5px; width: 80px; height: 25px;");

/*
    QPushButton* qpb_insert;
    QPushButton* qpb_remove;
    QPushButton* qpb_replace;
    QPushButton* qpb_replace_confirm;
    QPushButton* qpb_close;

    QLabel* ql_titolo;
    QLabel* ql_titolo_r;
    QLabel* ql_genere;
    QLabel* ql_genere_r;
    QLabel* ql_artista;
    QLabel* ql_artista_r;
    QLabel* ql_annoUscita;
    QLabel* ql_annoUscita_r;
    QLabel* ql_nDischi;
    QLabel* ql_nDischi_r;

    QLineEdit* qle_titolo;
    QLineEdit* qle_titolo_r;
    QLineEdit* qle_genere;
    QLineEdit* qle_genere_r;
    QLineEdit* qle_artista;
    QLineEdit* qle_artista_r;
    QSpinBox* qsb_annoUscita;
    QSpinBox* qsb_annoUscita_r;
    QLineEdit* qle_nDischi;
    QLineEdit* qle_nDischi_r;
*/


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
  qsb_nDischi->setValue(2016);

  gLayout = new QGridLayout;
  gLayout->setColumnStretch(1, 2);
  gLayout->addWidget(ql_titolo, 0, 0);
  gLayout->addWidget(qle_titolo, 0, 1);
  gLayout->addWidget(ql_genere, 1, 0);
  gLayout->addWidget(qle_genere, 1, 1);
  gLayout->addWidget(qle_autore, 2, 0);
  gLayout->addWidget(qle_autore, 2, 1);
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

void Gestione_CD::slotReplaceCD()){
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

  qsb_nDischi_r->setMinimum(0);
  qsb_nDischi_r->setValue(2016);

  gLayout->addWidget(ql_titolo_r, 5, 0);
  gLayout->addWidget(qle_titolo_r, 5, 1);
  gLayout->addWidget(ql_genere_r, 6, 0);
  gLayout->addWidget(qle_genere_r, 6, 1);
  gLayout->addWidget(qle_autore_r, 7, 0);
  gLayout->addWidget(qle_autore_r, 7, 1);
  gLayout->addWidget(ql_annoUscita_r_r, 8, 0);
  gLayout->addWidget(qsb_annoUscita_r, 8, 1);
  gLayout->addWidget(ql_nDischi_r, 9, 0);
  gLayout->addWidget(qsb_nDischi_r, 9, 1);


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
  connect(qpb_replace_confirm,SIGNAL(clicked()),this,SLOT(slotReplaceCD_c()));
  connect(qpb_close,SIGNAL(clicked()),this,SLOT(close()));
}

void Gestione_CD::slotReplaceCD_c(){
  emit signalReplaceCD();
}


CD* Gestione_CD::slotNewCD(){
  QString t = qle_titolo->text();
  QString g = qle_genere->text();
  QString a = qle_artista->text();
  int u = qsb_annoUscita->value();
  int d = qsb_nDischi->value();

  CD* cd_new = new CD(t, g, a, u, d);
  return cd_new;
}

CD* Gestione_CD::slotReplaceCD(){
  QString t_r = qle_titolo->text();
  QString g_r = qle_genere->text();
  QString a_r = qle_autore->text();
  int u_r = qsb_annoUscita->value();
  int d_r = qsb_nDischi->value();


  CD* cd_new_r = new CD(t_r, g_r, a_r, u_r, d_r);
  return cd_new_r;
}
