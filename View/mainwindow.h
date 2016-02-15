#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QVBoxLayout>
#include<QGroupBox>
#include<QPushButton>
#include<QLineEdit>
#include<QMenuBar>
#include<QToolBar>
#include<QStatusBar>
#include "../Model/container.h"
#include "../Model/smartptr.h"
/*
    #include "../Model/libraryitem.h"
    #include "../Model/cd.h"
    #include "../Model/dvd.h"
    #include "../Model/film.h"
    #include "../Model/libro.h"
    #include "../Model/vhs.h"
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupView();
    Container<SmartPtr>* getLib() const;
private:
    Container<SmartPtr>* lib;
    QWidget* widget;
    QWidget* centralWidget;
    QVBoxLayout *groupLayout;
    QPushButton *nuovoLibro;
    QPushButton *nuovoCD;
    QPushButton *nuovoDVD;
    QPushButton *nuovaVHS;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolbar;
    QStatusBar *statusBar;

signals:




public slots:
    void slotAddItem();
    void slotMostraCatalogoQDialog();
    void slotTrovaQDialog();
    void slotReplaceDVD();
    void slotReplaceVHS();
    void slotReplaceCD();
    void slotReplaceLibro();
    void slotAggiornaRisultati();

};

#endif // MAINWINDOW_H
