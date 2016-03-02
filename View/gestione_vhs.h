#ifndef GESTIONE_VHS_H
#define GESTIONE_VHS_H

#include "../Model/libraryitem.h"
#include "../Model/vhs.h"

#include <QCheckBox>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QWidget>
#include <QDateEdit>
#include <string>
using std::string;

class Gestione_VHS : public QDialog {
  Q_OBJECT
public:
    Gestione_VHS(QWidget*);
    ~Gestione_VHS() {}
private:
    QPushButton* qpb_insert;
    QPushButton* qpb_remove;
    QPushButton* qpb_replace;
    QPushButton* qpb_replace_confirm;
    QPushButton* qpb_close;
// Film::Film(QString t ="", QString g ="", QString r ="", int d =0, QDate u =QDate::currentDate()): LibraryItem(t, g), regista(r), durata(d), dataUscita(u){}
    QLabel* ql_titolo;
    QLabel* ql_titolo_r;
    QLabel* ql_genere;
    QLabel* ql_genere_r;
    QLabel* ql_regista;
    QLabel* ql_regista_r;
    QLabel* ql_durata;
    QLabel* ql_durata_r;
    QLabel* ql_dataUscita;
    QLabel* ql_dataUscita_r;

    QLineEdit* qle_titolo;
    QLineEdit* qle_titolo_r;
    QLineEdit* qle_genere;
    QLineEdit* qle_genere_r;
    QLineEdit* qle_regista;
    QLineEdit* qle_regista_r;
    QSpinBox* qsb_durata;
    QSpinBox* qsb_durata_r;
    QDateEdit* qde_dataUscita;
    QDateEdit* qde_dataUscita_r;

  // VHS* v_new;
  QGridLayout* gLayout;
public slots:
  void slotInsertVHS();
  void slotRemoveVHS();
  void slotReplaceVHS();
  void slotReplaceVHS_c();
  VHS* slotNewVHS();
  VHS* slotReplaceVideoCassetta();
signals:
  void signalInsertVHS();
  void signalRemoveVHS();
  void signalReplaceVHS();
};


#endif // GESTIONE_VHS_H
