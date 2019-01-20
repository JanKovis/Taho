/********************************************************************************
** Form generated from reading UI file 'cdokmz.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDOKMZ_H
#define UI_CDOKMZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CDoKmz
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *lw_kml;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_addKML;
    QPushButton *pb_del;
    QPushButton *pb_delAll;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rb_proKml;
    QRadioButton *rb_proZoom;
    QRadioButton *rb_proAll;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *la_out;
    QPushButton *pb_out;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CDoKmz)
    {
        if (CDoKmz->objectName().isEmpty())
            CDoKmz->setObjectName(QString::fromUtf8("CDoKmz"));
        CDoKmz->resize(559, 418);
        horizontalLayout_4 = new QHBoxLayout(CDoKmz);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(CDoKmz);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lw_kml = new QListWidget(groupBox);
        lw_kml->setObjectName(QString::fromUtf8("lw_kml"));

        verticalLayout->addWidget(lw_kml);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pb_addKML = new QPushButton(groupBox);
        pb_addKML->setObjectName(QString::fromUtf8("pb_addKML"));

        horizontalLayout->addWidget(pb_addKML);

        pb_del = new QPushButton(groupBox);
        pb_del->setObjectName(QString::fromUtf8("pb_del"));

        horizontalLayout->addWidget(pb_del);

        pb_delAll = new QPushButton(groupBox);
        pb_delAll->setObjectName(QString::fromUtf8("pb_delAll"));

        horizontalLayout->addWidget(pb_delAll);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(CDoKmz);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rb_proKml = new QRadioButton(groupBox_2);
        rb_proKml->setObjectName(QString::fromUtf8("rb_proKml"));

        horizontalLayout_2->addWidget(rb_proKml);

        rb_proZoom = new QRadioButton(groupBox_2);
        rb_proZoom->setObjectName(QString::fromUtf8("rb_proZoom"));

        horizontalLayout_2->addWidget(rb_proZoom);

        rb_proAll = new QRadioButton(groupBox_2);
        rb_proAll->setObjectName(QString::fromUtf8("rb_proAll"));

        horizontalLayout_2->addWidget(rb_proAll);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(CDoKmz);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        la_out = new QLabel(groupBox_3);
        la_out->setObjectName(QString::fromUtf8("la_out"));
        la_out->setText(QString::fromUtf8("TextLabel"));

        horizontalLayout_3->addWidget(la_out);

        pb_out = new QPushButton(groupBox_3);
        pb_out->setObjectName(QString::fromUtf8("pb_out"));
        pb_out->setMaximumSize(QSize(50, 16777215));
        pb_out->setText(QString::fromUtf8("..."));

        horizontalLayout_3->addWidget(pb_out);


        verticalLayout_2->addWidget(groupBox_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(CDoKmz);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_4->addWidget(buttonBox);


        retranslateUi(CDoKmz);
        QObject::connect(buttonBox, SIGNAL(accepted()), CDoKmz, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CDoKmz, SLOT(reject()));
        QObject::connect(pb_addKML, SIGNAL(clicked()), CDoKmz, SLOT(OnAddKml()));
        QObject::connect(pb_del, SIGNAL(clicked()), CDoKmz, SLOT(OnDel()));
        QObject::connect(pb_delAll, SIGNAL(clicked()), CDoKmz, SLOT(OnDelall()));
        QObject::connect(pb_out, SIGNAL(clicked()), CDoKmz, SLOT(OnFsKmz()));
        QObject::connect(buttonBox, SIGNAL(accepted()), CDoKmz, SLOT(OnOk()));
        QObject::connect(rb_proKml, SIGNAL(clicked()), CDoKmz, SLOT(OnChgNumber()));
        QObject::connect(rb_proZoom, SIGNAL(clicked()), CDoKmz, SLOT(OnChgNumber()));
        QObject::connect(rb_proAll, SIGNAL(clicked()), CDoKmz, SLOT(OnChgNumber()));

        QMetaObject::connectSlotsByName(CDoKmz);
    } // setupUi

    void retranslateUi(QDialog *CDoKmz)
    {
        CDoKmz->setWindowTitle(QApplication::translate("CDoKmz", "KMZ erstellen", nullptr));
        groupBox->setTitle(QApplication::translate("CDoKmz", "KML-Files", nullptr));
        pb_addKML->setText(QApplication::translate("CDoKmz", "KML hinzuf\303\274gen", nullptr));
        pb_del->setText(QApplication::translate("CDoKmz", "l\303\266schen", nullptr));
        pb_delAll->setText(QApplication::translate("CDoKmz", "alle l\303\266schen", nullptr));
        groupBox_2->setTitle(QApplication::translate("CDoKmz", "Ein KMZ-File pro", nullptr));
        rb_proKml->setText(QApplication::translate("CDoKmz", "KML-File", nullptr));
        rb_proZoom->setText(QApplication::translate("CDoKmz", "Zoom-Level", nullptr));
        rb_proAll->setText(QApplication::translate("CDoKmz", "gesamt", nullptr));
        groupBox_3->setTitle(QApplication::translate("CDoKmz", "Ausgabe File(s) (ggf. wird der Zoom-level angeh\303\244ngt)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDoKmz: public Ui_CDoKmz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDOKMZ_H
