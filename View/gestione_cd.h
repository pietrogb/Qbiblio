#ifndef GESTIONE_CD_H
#define GESTIONE_CD_H

#include "../Model/libraryitem.h"
#include "../Model/cd.h"

#include <QCheckBox>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QWidget>

class Gestione_CD : public QDialog {
  Q_OBJECT
public:
    Gestione_CD(QWidget*);
    ~Gestione_CD() {}
private:
	//CD::CD(QString t ="", QString g="", QString a="", int u =0, int n =0): LibraryItem(t,g), artista(a), annoUscita(u), nDischi(n){}
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
    QSpinBox* qsb_nDischi;
    QSpinBox* qsb_nDischi_r;

  //CD* cd_new;
  QGridLayout* gLayout;
public slots:
  void slotInsertCD();
  void slotRemoveCD();
  void slotReplaceCD();
  void slotReplaceCD_c();
  CD* slotNewCD();
  CD* slotReplaceCD();
signals:
  void signalInsertCD();
  void signalRemoveCD();
  void signalReplaceCD();
};


#endif // GESTIONE_CD_H
