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

class gestione_DVD : public QDialog
{
    Q_OBJECT
public:
    explicit gestione_DVD(QObject *parent = 0);

signals:

public slots:

};

#endif // GESTIONE_DVD_H
