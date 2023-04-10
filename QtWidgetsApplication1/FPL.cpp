#include "FPL.h"

// Cr�er une structure de donn�es pour stocker des images
std::vector<QPixmap> images;

FPL::FPL(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //creation des actions
    actionOuvrir = new QAction(tr("&Ouvrir"), this);
    actionFermer = new QAction(tr("&Fermer"), this);
    actionTrouver = new QAction(tr("&Trouver"), this);

    //creation du menu Fichier
    menuFichier = menuBar()->addMenu(tr("&Fichier"));
    menuFichier->addAction(actionOuvrir);
    menuFichier->addAction(actionFermer);

    //creation du menu Edition
    menuEditer = menuBar()->addMenu(tr("&Edition"));
    menuEditer->addAction(actionTrouver);

    QWidget* centralWidget = new QWidget(this);
    bouton1 = new QPushButton(tr("New game"), this);
    bouton2 = new QPushButton(tr("Load"), this);
    bouton3 = new QPushButton(tr("Quit"), this);


    // Add the button to the layout
    QVBoxLayout* buttonLayout = new QVBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(bouton1);
    buttonLayout->addWidget(bouton2);
    buttonLayout->addWidget(bouton3);
    buttonLayout->addStretch();
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addStretch();
    layout->addLayout(buttonLayout);
    layout->addStretch();
    // Cr�er un widget QLabel pour afficher les images
    QLabel* label = new QLabel;
    QPixmap defaultPixmap; // Pixmap par d�faut, si aucune image n'est charg�e

    // Cr�er un bouton pour afficher la premi�re image de la structure de donn�es
    connect(bouton1, &QPushButton::clicked, [=]() {
        int randomIndex = rand() % images.size();
        if (!images.empty()) { // Si la structure de donn�es n'est pas vide
            label->setPixmap(images[randomIndex]); // Afficher la premi�re image de la structure de donn�es
        }
        else {
            label->setPixmap(defaultPixmap); // Afficher le Pixmap par d�faut si la structure de donn�es est vide
        }
        });

    // Ajouter le QLabel et le QPushButton au layout
    layout->addWidget(label);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    QDir dir("D:/Qt/Projet/Images");
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.bmp";
    QFileInfoList files = dir.entryInfoList(filters);
    foreach(QFileInfo file, files)
    {
        QPixmap image(file.absoluteFilePath());
        if (!image.isNull())
        {
            images.push_back(image);
        }
    }

    // Cr�er un widget QLabel pour afficher les images
    /*QLabel* label1 = new QLabel;

    // Afficher les images dans le QLabel
    label1->setPixmap(images[2]);
    label1->show();*/

    connect(bouton1, SIGNAL(clicked()), this, SLOT(changeImage()));
}

FPL::~FPL()
{}
