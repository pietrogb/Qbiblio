#ifndef GESTIONE_LIBRO_H
#define GESTIONE_LIBRO_H

#include "../Model/libraryitem.h"
#include "../Model/libro.h"

#include <QCheckBox>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QWidget>

class Gestione_Libro : public QDialog {
  Q_OBJECT
public:
    Gestione_Libro(QWidget*);
    ~Gestione_Libro() {}
private:
    QPushButton* qpb_insert;
    QPushButton* qpb_remove;
    QPushButton* qpb_replace;
    QPushButton* qpb_replace_confirm;
    QPushButton* qpb_close;
    //"Titolo"<<"Genere"<<"Autore"<<"Anno d'Uscita"<<"Editore";
    QLabel* ql_titolo;
    QLabel* ql_titolo_r;
    QLabel* ql_genere;
    QLabel* ql_genere_r;
    QLabel* ql_autore;
    QLabel* ql_autore_r;
    QLabel* ql_annoUscita;
    QLabel* ql_annoUscita_r;
    QLabel* ql_editore;
    QLabel* ql_editore_r;

    QLineEdit* qle_titolo;
    QLineEdit* qle_titolo_r;
    QLineEdit* qle_genere;
    QLineEdit* qle_genere_r;
    QLineEdit* qle_autore;
    QLineEdit* qle_autore_r;
    QSpinBox* qsb_annoUscita;
    QSpinBox* qsb_annoUscita_r;
    QLineEdit* qle_editore;
    QLineEdit* qle_editore_r;


  Libro* l_new;
  QGridLayout* gLayout;
public slots:
  void slotInsertCD();
  void slotRemoveCD();
  void slotReplaceCD();
  void slotReplaceCD_c();
  Libro* slotNewLibro();
  Libro* slotReplaceLibro();
signals:
  void signalInsertLibro();
  void signalRemoveLibro();
  void signalReplaceLibro();
};


#endif // GESTIONE_LIBRO_H
