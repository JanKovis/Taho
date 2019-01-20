/********************************************************************************
** Form generated from reading UI file 'ctahoopt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTAHOOPT_H
#define UI_CTAHOOPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CTahoOpt
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout;
    QComboBox *cb_lang;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout;
    QSpinBox *spinBox;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_update;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpinBox *sbCache;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *la_zip;
    QPushButton *pb_packer;
    QLabel *label_4;
    QLineEdit *le_parKMZ;
    QLabel *label_5;
    QLineEdit *le_parGZ;
    QLabel *label_6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CTahoOpt)
    {
        if (CTahoOpt->objectName().isEmpty())
            CTahoOpt->setObjectName(QString::fromUtf8("CTahoOpt"));
        CTahoOpt->resize(513, 298);
        horizontalLayout_4 = new QHBoxLayout(CTahoOpt);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_4 = new QGroupBox(CTahoOpt);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(200, 16777215));
        horizontalLayout = new QHBoxLayout(groupBox_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cb_lang = new QComboBox(groupBox_4);
        cb_lang->addItem(QString::fromUtf8("Deutsch"));
        cb_lang->addItem(QString::fromUtf8("English"));
        cb_lang->addItem(QString::fromUtf8("Fran\303\247ais"));
        cb_lang->setObjectName(QString::fromUtf8("cb_lang"));

        horizontalLayout->addWidget(cb_lang);


        verticalLayout_2->addWidget(groupBox_4);

        groupBox_7 = new QGroupBox(CTahoOpt);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        spinBox = new QSpinBox(groupBox_7);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(spinBox);


        verticalLayout_2->addWidget(groupBox_7);

        groupBox_2 = new QGroupBox(CTahoOpt);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pb_update = new QPushButton(groupBox_2);
        pb_update->setObjectName(QString::fromUtf8("pb_update"));

        horizontalLayout_2->addWidget(pb_update);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        sbCache = new QSpinBox(groupBox_2);
        sbCache->setObjectName(QString::fromUtf8("sbCache"));

        horizontalLayout_2->addWidget(sbCache);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_8 = new QGroupBox(CTahoOpt);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout = new QGridLayout(groupBox_8);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        la_zip = new QLabel(groupBox_8);
        la_zip->setObjectName(QString::fromUtf8("la_zip"));
        la_zip->setText(QString::fromUtf8("TextLabel"));

        horizontalLayout_3->addWidget(la_zip);

        pb_packer = new QPushButton(groupBox_8);
        pb_packer->setObjectName(QString::fromUtf8("pb_packer"));
        pb_packer->setMaximumSize(QSize(32, 16777215));
        pb_packer->setText(QString::fromUtf8("..."));

        horizontalLayout_3->addWidget(pb_packer);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 2);

        label_4 = new QLabel(groupBox_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        le_parKMZ = new QLineEdit(groupBox_8);
        le_parKMZ->setObjectName(QString::fromUtf8("le_parKMZ"));

        gridLayout->addWidget(le_parKMZ, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        le_parGZ = new QLineEdit(groupBox_8);
        le_parGZ->setObjectName(QString::fromUtf8("le_parGZ"));

        gridLayout->addWidget(le_parGZ, 2, 1, 1, 1);

        label_6 = new QLabel(groupBox_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 2);


        verticalLayout_2->addWidget(groupBox_8);


        horizontalLayout_4->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(CTahoOpt);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_4->addWidget(buttonBox);

        QWidget::setTabOrder(cb_lang, spinBox);
        QWidget::setTabOrder(spinBox, pb_update);
        QWidget::setTabOrder(pb_update, sbCache);
        QWidget::setTabOrder(sbCache, pb_packer);
        QWidget::setTabOrder(pb_packer, le_parKMZ);
        QWidget::setTabOrder(le_parKMZ, le_parGZ);

        retranslateUi(CTahoOpt);
        QObject::connect(buttonBox, SIGNAL(accepted()), CTahoOpt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CTahoOpt, SLOT(reject()));
        QObject::connect(pb_update, SIGNAL(clicked()), CTahoOpt, SLOT(OnUpdSrc()));
        QObject::connect(cb_lang, SIGNAL(currentIndexChanged(QString)), CTahoOpt, SLOT(change_lang(QString)));
        QObject::connect(pb_packer, SIGNAL(clicked()), CTahoOpt, SLOT(OnZip()));

        QMetaObject::connectSlotsByName(CTahoOpt);
    } // setupUi

    void retranslateUi(QDialog *CTahoOpt)
    {
        CTahoOpt->setWindowTitle(QApplication::translate("CTahoOpt", "Optionen", nullptr));
        groupBox_4->setTitle(QApplication::translate("CTahoOpt", "Sprache", nullptr));

        groupBox_7->setTitle(QApplication::translate("CTahoOpt", "maximale Anzahl Threads", nullptr));
        groupBox_2->setTitle(QApplication::translate("CTahoOpt", "Quelle", nullptr));
        pb_update->setText(QApplication::translate("CTahoOpt", "update Quell-URLs", nullptr));
        label->setText(QApplication::translate("CTahoOpt", "Cache g\303\274ltig f\303\274r:", nullptr));
        label_2->setText(QApplication::translate("CTahoOpt", "Tage", nullptr));
        groupBox_8->setTitle(QApplication::translate("CTahoOpt", "Packer (f\303\274r KMZ & GZ)", nullptr));
        label_4->setText(QApplication::translate("CTahoOpt", "Kommandozeile (KMZ):", nullptr));
        label_5->setText(QApplication::translate("CTahoOpt", "Kommandozeile (GZ):", nullptr));
        label_6->setText(QApplication::translate("CTahoOpt", "Platzhalter: $Q: Quelle; $Z: Zielfile; $L: Listfile; $ verdoppeln", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CTahoOpt: public Ui_CTahoOpt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTAHOOPT_H
