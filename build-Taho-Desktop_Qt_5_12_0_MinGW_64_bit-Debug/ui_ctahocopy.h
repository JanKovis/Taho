/********************************************************************************
** Form generated from reading UI file 'ctahocopy.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTAHOCOPY_H
#define UI_CTAHOCOPY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CTahoCopy
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *la_vers;
    QLabel *label_3;
    QPushButton *pb_gpl;
    QLabel *label_4;
    QPushButton *pb_dyj;
    QLabel *label_7;
    QPushButton *pb_osm;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QPushButton *pushButton;

    void setupUi(QDialog *CTahoCopy)
    {
        if (CTahoCopy->objectName().isEmpty())
            CTahoCopy->setObjectName(QString::fromUtf8("CTahoCopy"));
        CTahoCopy->resize(337, 160);
        gridLayout = new QGridLayout(CTahoCopy);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(CTahoCopy);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(CTahoCopy);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setText(QString::fromUtf8("Dimitri Junker"));

        gridLayout->addWidget(label_5, 0, 1, 1, 1);

        label_2 = new QLabel(CTahoCopy);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        la_vers = new QLabel(CTahoCopy);
        la_vers->setObjectName(QString::fromUtf8("la_vers"));
        la_vers->setText(QString::fromUtf8("TextLabel"));

        gridLayout->addWidget(la_vers, 1, 1, 1, 3);

        label_3 = new QLabel(CTahoCopy);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        pb_gpl = new QPushButton(CTahoCopy);
        pb_gpl->setObjectName(QString::fromUtf8("pb_gpl"));

        gridLayout->addWidget(pb_gpl, 2, 1, 1, 1);

        label_4 = new QLabel(CTahoCopy);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        pb_dyj = new QPushButton(CTahoCopy);
        pb_dyj->setObjectName(QString::fromUtf8("pb_dyj"));

        gridLayout->addWidget(pb_dyj, 3, 1, 1, 1);

        label_7 = new QLabel(CTahoCopy);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 3, 2, 1, 1);

        pb_osm = new QPushButton(CTahoCopy);
        pb_osm->setObjectName(QString::fromUtf8("pb_osm"));
        pb_osm->setText(QString::fromUtf8("OSM"));

        gridLayout->addWidget(pb_osm, 3, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(CTahoCopy);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_8 = new QLabel(CTahoCopy);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(CTahoCopy);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_10 = new QLabel(CTahoCopy);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout->addWidget(label_10);

        pushButton = new QPushButton(CTahoCopy);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setText(QString::fromUtf8("\302\251 OSM "));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 4, 0, 1, 4);


        retranslateUi(CTahoCopy);
        QObject::connect(pb_gpl, SIGNAL(clicked()), CTahoCopy, SLOT(OnGpl()));
        QObject::connect(pb_dyj, SIGNAL(clicked()), CTahoCopy, SLOT(OnDyj()));
        QObject::connect(pb_osm, SIGNAL(clicked()), CTahoCopy, SLOT(OnOsmTaho()));
        QObject::connect(pushButton, SIGNAL(clicked()), CTahoCopy, SLOT(OnOSMc()));

        QMetaObject::connectSlotsByName(CTahoCopy);
    } // setupUi

    void retranslateUi(QDialog *CTahoCopy)
    {
        CTahoCopy->setWindowTitle(QApplication::translate("CTahoCopy", "\303\274ber Taho", nullptr));
        label->setText(QApplication::translate("CTahoCopy", "Autor:", nullptr));
        label_2->setText(QApplication::translate("CTahoCopy", "Version:", nullptr));
        label_3->setText(QApplication::translate("CTahoCopy", "Lizenz:", nullptr));
        pb_gpl->setText(QApplication::translate("CTahoCopy", "GPL V.3", nullptr));
        label_4->setText(QApplication::translate("CTahoCopy", "WWW:", nullptr));
        pb_dyj->setText(QApplication::translate("CTahoCopy", "Autor", nullptr));
        label_7->setText(QApplication::translate("CTahoCopy", "oder", nullptr));
        label_6->setText(QApplication::translate("CTahoCopy", "Dieses Programm wurde mit QT Creator entwickelt.", nullptr));
        label_8->setText(QApplication::translate("CTahoCopy", "Es verwendet die dynamisch dazu gelinkten QT-Bibliotheken.", nullptr));
        label_9->setText(QApplication::translate("CTahoCopy", "Die erzeugten Karten unterstehen meist der Lizens von", nullptr));
        label_10->setText(QApplication::translate("CTahoCopy", "Openstreetmap, weiteres s.:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CTahoCopy: public Ui_CTahoCopy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTAHOCOPY_H
