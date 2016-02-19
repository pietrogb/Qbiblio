#ifndef GESTIONE_DVD_H
#define GESTIONE_DVD_H

#include "../Model/libraryitem.h"
#include "../Model/dvd.h"

#include <QCheckBox>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QWidget>

class Gestione_DVD : public QDialog {
  Q_OBJECT
public:
    Gestione_DVD(QWidget*);
    ~Gestione_DVD() {}
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

  DVD* d_new;
  QGridLayout* gLayout;
public slots:
  void slotInsertDVD();
  void slotRemoveDVD();
  void slotReplaceDVD();
  void slotReplaceDVD_c();
  DVD* slotNewDVD();
  DVD* slotReplaceDVD();
signals:
  void signalInsertDVD();
  void signalRemoveDVD();
  void signalReplaceDVD();
};


#endif // GESTIONE_DVD_H
