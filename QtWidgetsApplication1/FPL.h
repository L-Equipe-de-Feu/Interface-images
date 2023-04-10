#pragma once

#include <QtWidgets>
#include <qapplication.h>
#include <QWidget>
#include <qmenu.h>
#include <qaction.h>
#include <vector>
#include <QPixmap>
#include <QDir>
#include <QLabel>
#include <QVector>
#include <qpushbutton.h>
#include <QVBoxLayout>
#include <QAction>
#include <QApplication>
#include <QPushButton>
#include "ui_FPL.h"

class FPL : public QMainWindow
{
    Q_OBJECT

public:
    FPL(QWidget* parent = nullptr);
    ~FPL();

private slots:
    /*void siOuvert();
    void siFermer();
    void siTrouver();
    void siBoutonCliquer();*/

private:
    Ui::FPLClass ui;
    QAction* actionOuvrir;
    QAction* actionFermer;
    QAction* actionTrouver;
    QMenu* menuFichier;
    QMenu* menuEditer;
    QPushButton* bouton1;
    QPushButton* bouton2;
    QPushButton* bouton3;
};
