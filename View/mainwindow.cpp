#include "mainwindow.h"
#include <QDesktopWidget>
#include <QFont>
#include <QHeaderView>
#include <QMessageBox>
#include <QPointer>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    lib=new Container<SmartPtr>;
    centralWidget = new QWidget(this);
    widget = new QWidget(centralWidget);
    groupLayout = new QVBoxLayout(widget);

    setupView();
    //connect
}

MainWindow::~MainWindow() {}

void MainWindow::setupView() {
    int monitorWidth = QApplication::desktop()->width();
    int monitorHeight = QApplication::desktop()->height();
    resize(monitorWidth*0.95, monitorHeight*0.95);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    widget->setObjectName(QStringLiteral("widget"));
    groupLayout->setObjectName(QStringLiteral("groupLayout"));
    setWindowTitle("Programmazione ad oggetti - QBiblio - 2016");

}

 Container<SmartPtr>* MainWindow::getLib()() const {
     return lib;
 }

