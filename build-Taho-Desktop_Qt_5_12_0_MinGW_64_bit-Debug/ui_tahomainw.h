/********************************************************************************
** Form generated from reading UI file 'tahomainw.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAHOMAINW_H
#define UI_TAHOMAINW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TahoMainW
{
public:
    QAction *actionEinstellungen_laden;
    QAction *actionEinstellungen_speichern;
    QAction *actionKarten_erstellen;
    QAction *actionOSMBugs_holen;
    QAction *actionKMZ_erstellen;
    QAction *actionOptionen;
    QAction *actionHilfe;
    QAction *actionInfo;
    QAction *actionBeenden;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    QRadioButton *rb_nbNr;
    QRadioButton *rb_nbKoord;
    QRadioButton *rb_nbDir;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *cb_auto;
    QLineEdit *le_out;
    QPushButton *pb_out;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pb_doTaho;
    QPushButton *pb_help;
    QPushButton *pb_quit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *le_lat1;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *le_lon1;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *le_lon2;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLineEdit *le_lat2;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QPushButton *pb_bbox;
    QTabWidget *tw_mapType;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QComboBox *cb_quelle;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_2;
    QLabel *label_12;
    QLabel *l_kal;
    QListWidget *lw_overl;
    QListWidget *lw_kal;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_9;
    QListWidget *lw_zoom;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pb_zAll;
    QPushButton *pb_z2;
    QPushButton *pb_z0;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLabel *l_bpp;
    QComboBox *cb_bpp;
    QLabel *label_15;
    QComboBox *cb_size;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QRadioButton *rb_png;
    QRadioButton *rb_jpg;
    QRadioButton *rb_pngt;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_16;
    QListWidget *lw_vect;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menuBar;
    QMenu *menuDatei;
    QMenu *menuBearbeiten;
    QMenu *menuHilfe;

    void setupUi(QMainWindow *TahoMainW)
    {
        if (TahoMainW->objectName().isEmpty())
            TahoMainW->setObjectName(QString::fromUtf8("TahoMainW"));
        TahoMainW->resize(761, 511);
        TahoMainW->setWindowTitle(QString::fromUtf8("Taho 4.07"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/taho.png"), QSize(), QIcon::Normal, QIcon::Off);
        TahoMainW->setWindowIcon(icon);
        actionEinstellungen_laden = new QAction(TahoMainW);
        actionEinstellungen_laden->setObjectName(QString::fromUtf8("actionEinstellungen_laden"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/document-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEinstellungen_laden->setIcon(icon1);
        actionEinstellungen_speichern = new QAction(TahoMainW);
        actionEinstellungen_speichern->setObjectName(QString::fromUtf8("actionEinstellungen_speichern"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/document-save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEinstellungen_speichern->setIcon(icon2);
        actionKarten_erstellen = new QAction(TahoMainW);
        actionKarten_erstellen->setObjectName(QString::fromUtf8("actionKarten_erstellen"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/gnome-app-install-star.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionKarten_erstellen->setIcon(icon3);
        actionOSMBugs_holen = new QAction(TahoMainW);
        actionOSMBugs_holen->setObjectName(QString::fromUtf8("actionOSMBugs_holen"));
        actionKMZ_erstellen = new QAction(TahoMainW);
        actionKMZ_erstellen->setObjectName(QString::fromUtf8("actionKMZ_erstellen"));
        actionOptionen = new QAction(TahoMainW);
        actionOptionen->setObjectName(QString::fromUtf8("actionOptionen"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/preferences-desktop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOptionen->setIcon(icon4);
        actionHilfe = new QAction(TahoMainW);
        actionHilfe->setObjectName(QString::fromUtf8("actionHilfe"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/help-contents.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHilfe->setIcon(icon5);
        actionInfo = new QAction(TahoMainW);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/help-about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfo->setIcon(icon6);
        actionBeenden = new QAction(TahoMainW);
        actionBeenden->setObjectName(QString::fromUtf8("actionBeenden"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBeenden->setIcon(icon7);
        centralWidget = new QWidget(TahoMainW);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_6->addWidget(label_10);

        rb_nbNr = new QRadioButton(groupBox_2);
        rb_nbNr->setObjectName(QString::fromUtf8("rb_nbNr"));

        horizontalLayout_6->addWidget(rb_nbNr);

        rb_nbKoord = new QRadioButton(groupBox_2);
        rb_nbKoord->setObjectName(QString::fromUtf8("rb_nbKoord"));

        horizontalLayout_6->addWidget(rb_nbKoord);

        rb_nbDir = new QRadioButton(groupBox_2);
        rb_nbDir->setObjectName(QString::fromUtf8("rb_nbDir"));

        horizontalLayout_6->addWidget(rb_nbDir);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        cb_auto = new QCheckBox(groupBox_2);
        cb_auto->setObjectName(QString::fromUtf8("cb_auto"));

        horizontalLayout_7->addWidget(cb_auto);

        le_out = new QLineEdit(groupBox_2);
        le_out->setObjectName(QString::fromUtf8("le_out"));

        horizontalLayout_7->addWidget(le_out);

        pb_out = new QPushButton(groupBox_2);
        pb_out->setObjectName(QString::fromUtf8("pb_out"));
        pb_out->setMaximumSize(QSize(32, 16777215));
        pb_out->setText(QString::fromUtf8("..."));

        horizontalLayout_7->addWidget(pb_out);


        verticalLayout->addLayout(horizontalLayout_7);


        gridLayout_4->addWidget(groupBox_2, 2, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(12);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        pb_doTaho = new QPushButton(centralWidget);
        pb_doTaho->setObjectName(QString::fromUtf8("pb_doTaho"));
        pb_doTaho->setIcon(icon3);
        pb_doTaho->setIconSize(QSize(32, 32));

        verticalLayout_5->addWidget(pb_doTaho);

        pb_help = new QPushButton(centralWidget);
        pb_help->setObjectName(QString::fromUtf8("pb_help"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb_help->sizePolicy().hasHeightForWidth());
        pb_help->setSizePolicy(sizePolicy);
        pb_help->setStyleSheet(QString::fromUtf8(""));
        pb_help->setIcon(icon5);
        pb_help->setIconSize(QSize(32, 32));

        verticalLayout_5->addWidget(pb_help);

        pb_quit = new QPushButton(centralWidget);
        pb_quit->setObjectName(QString::fromUtf8("pb_quit"));
        pb_quit->setIcon(icon7);
        pb_quit->setIconSize(QSize(32, 32));

        verticalLayout_5->addWidget(pb_quit);


        gridLayout_4->addLayout(verticalLayout_5, 0, 2, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        le_lat1 = new QLineEdit(groupBox);
        le_lat1->setObjectName(QString::fromUtf8("le_lat1"));

        horizontalLayout_4->addWidget(le_lat1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);


        gridLayout->addLayout(horizontalLayout_4, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        le_lon1 = new QLineEdit(groupBox);
        le_lon1->setObjectName(QString::fromUtf8("le_lon1"));

        horizontalLayout_2->addWidget(le_lon1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        le_lon2 = new QLineEdit(groupBox);
        le_lon2->setObjectName(QString::fromUtf8("le_lon2"));

        horizontalLayout_3->addWidget(le_lon2);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);


        gridLayout->addLayout(horizontalLayout_3, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        le_lat2 = new QLineEdit(groupBox);
        le_lat2->setObjectName(QString::fromUtf8("le_lat2"));

        horizontalLayout->addWidget(le_lat2);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_5->addWidget(label_9);

        pb_bbox = new QPushButton(groupBox);
        pb_bbox->setObjectName(QString::fromUtf8("pb_bbox"));

        horizontalLayout_5->addWidget(pb_bbox);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 2);


        gridLayout_4->addWidget(groupBox, 0, 0, 2, 1);

        tw_mapType = new QTabWidget(centralWidget);
        tw_mapType->setObjectName(QString::fromUtf8("tw_mapType"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_10 = new QHBoxLayout(tab);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_8->addWidget(label_11);

        cb_quelle = new QComboBox(tab);
        cb_quelle->setObjectName(QString::fromUtf8("cb_quelle"));

        horizontalLayout_8->addWidget(cb_quelle);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_8);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 0, 0, 1, 1);

        l_kal = new QLabel(tab);
        l_kal->setObjectName(QString::fromUtf8("l_kal"));

        gridLayout_2->addWidget(l_kal, 0, 1, 1, 1);

        lw_overl = new QListWidget(tab);
        lw_overl->setObjectName(QString::fromUtf8("lw_overl"));

        gridLayout_2->addWidget(lw_overl, 1, 0, 1, 1);

        lw_kal = new QListWidget(tab);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(lw_kal);
        __qlistwidgetitem->setText(QString::fromUtf8("Fugawi"));
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(lw_kal);
        __qlistwidgetitem1->setText(QString::fromUtf8("Glopus"));
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(lw_kal);
        __qlistwidgetitem2->setText(QString::fromUtf8("GMI"));
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(lw_kal);
        __qlistwidgetitem3->setText(QString::fromUtf8("kml"));
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(lw_kal);
        __qlistwidgetitem4->setText(QString::fromUtf8("OZI"));
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(lw_kal);
        __qlistwidgetitem5->setText(QString::fromUtf8("Pathway"));
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(lw_kal);
        __qlistwidgetitem6->setText(QString::fromUtf8("TTQV"));
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(lw_kal);
        __qlistwidgetitem7->setText(QString::fromUtf8("UI-View"));
        QListWidgetItem *__qlistwidgetitem8 = new QListWidgetItem(lw_kal);
        __qlistwidgetitem8->setText(QString::fromUtf8("WorldFile"));
        lw_kal->setObjectName(QString::fromUtf8("lw_kal"));
        lw_kal->setMaximumSize(QSize(110, 16777215));

        gridLayout_2->addWidget(lw_kal, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);


        horizontalLayout_10->addLayout(verticalLayout_4);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_3);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lw_zoom = new QListWidget(groupBox_3);
        QListWidgetItem *__qlistwidgetitem9 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem9->setText(QString::fromUtf8("1"));
        __qlistwidgetitem9->setCheckState(Qt::Checked);
        QListWidgetItem *__qlistwidgetitem10 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem10->setText(QString::fromUtf8("2"));
        __qlistwidgetitem10->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem11 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem11->setText(QString::fromUtf8("3"));
        __qlistwidgetitem11->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem12 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem12->setText(QString::fromUtf8("4"));
        __qlistwidgetitem12->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem13 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem13->setText(QString::fromUtf8("5"));
        __qlistwidgetitem13->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem14 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem14->setText(QString::fromUtf8("6"));
        __qlistwidgetitem14->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem15 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem15->setText(QString::fromUtf8("7"));
        __qlistwidgetitem15->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem16 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem16->setText(QString::fromUtf8("8"));
        __qlistwidgetitem16->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem17 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem17->setText(QString::fromUtf8("9"));
        __qlistwidgetitem17->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem18 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem18->setText(QString::fromUtf8("10"));
        __qlistwidgetitem18->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem19 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem19->setText(QString::fromUtf8("11"));
        __qlistwidgetitem19->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem20 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem20->setText(QString::fromUtf8("12"));
        __qlistwidgetitem20->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem21 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem21->setText(QString::fromUtf8("13"));
        __qlistwidgetitem21->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem22 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem22->setText(QString::fromUtf8("14"));
        __qlistwidgetitem22->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem23 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem23->setText(QString::fromUtf8("15"));
        __qlistwidgetitem23->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem24 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem24->setText(QString::fromUtf8("16"));
        __qlistwidgetitem24->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem25 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem25->setText(QString::fromUtf8("17"));
        __qlistwidgetitem25->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem26 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem26->setText(QString::fromUtf8("18"));
        __qlistwidgetitem26->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem27 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem27->setText(QString::fromUtf8("19"));
        __qlistwidgetitem27->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem28 = new QListWidgetItem(lw_zoom);
        __qlistwidgetitem28->setText(QString::fromUtf8("20"));
        __qlistwidgetitem28->setCheckState(Qt::Unchecked);
        lw_zoom->setObjectName(QString::fromUtf8("lw_zoom"));
        lw_zoom->setMaximumSize(QSize(90, 16777215));
        lw_zoom->setSelectionMode(QAbstractItemView::MultiSelection);
        lw_zoom->setFlow(QListView::TopToBottom);
        lw_zoom->setModelColumn(0);

        horizontalLayout_9->addWidget(lw_zoom);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pb_zAll = new QPushButton(groupBox_3);
        pb_zAll->setObjectName(QString::fromUtf8("pb_zAll"));

        verticalLayout_2->addWidget(pb_zAll);

        pb_z2 = new QPushButton(groupBox_3);
        pb_z2->setObjectName(QString::fromUtf8("pb_z2"));

        verticalLayout_2->addWidget(pb_z2);

        pb_z0 = new QPushButton(groupBox_3);
        pb_z0->setObjectName(QString::fromUtf8("pb_z0"));

        verticalLayout_2->addWidget(pb_z0);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_9->addLayout(verticalLayout_2);


        horizontalLayout_10->addWidget(groupBox_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        l_bpp = new QLabel(tab);
        l_bpp->setObjectName(QString::fromUtf8("l_bpp"));

        verticalLayout_3->addWidget(l_bpp);

        cb_bpp = new QComboBox(tab);
        cb_bpp->addItem(QString::fromUtf8("8"));
        cb_bpp->addItem(QString::fromUtf8("24"));
        cb_bpp->addItem(QString::fromUtf8("32"));
        cb_bpp->setObjectName(QString::fromUtf8("cb_bpp"));

        verticalLayout_3->addWidget(cb_bpp);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_3->addWidget(label_15);

        cb_size = new QComboBox(tab);
        cb_size->addItem(QString());
        cb_size->addItem(QString());
        cb_size->addItem(QString::fromUtf8("256*256"));
        cb_size->addItem(QString::fromUtf8("512*512"));
        cb_size->addItem(QString::fromUtf8("1024*1024"));
        cb_size->addItem(QString::fromUtf8("2048*2048"));
        cb_size->addItem(QString::fromUtf8("4096*4096"));
        cb_size->addItem(QString::fromUtf8("8192*8192"));
        cb_size->addItem(QString::fromUtf8("16384*16384"));
        cb_size->setObjectName(QString::fromUtf8("cb_size"));

        verticalLayout_3->addWidget(cb_size);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        rb_png = new QRadioButton(groupBox_4);
        rb_png->setObjectName(QString::fromUtf8("rb_png"));
        rb_png->setText(QString::fromUtf8("png"));

        gridLayout_3->addWidget(rb_png, 0, 0, 1, 1);

        rb_jpg = new QRadioButton(groupBox_4);
        rb_jpg->setObjectName(QString::fromUtf8("rb_jpg"));
        rb_jpg->setText(QString::fromUtf8("jpg"));

        gridLayout_3->addWidget(rb_jpg, 0, 1, 1, 1);

        rb_pngt = new QRadioButton(groupBox_4);
        rb_pngt->setObjectName(QString::fromUtf8("rb_pngt"));
        rb_pngt->setText(QString::fromUtf8("png.tile"));

        gridLayout_3->addWidget(rb_pngt, 1, 0, 1, 2);


        verticalLayout_3->addWidget(groupBox_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_10->addLayout(verticalLayout_3);

        tw_mapType->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_11 = new QHBoxLayout(tab_2);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_11->addWidget(label_16);

        lw_vect = new QListWidget(tab_2);
        lw_vect->setObjectName(QString::fromUtf8("lw_vect"));

        horizontalLayout_11->addWidget(lw_vect);

        horizontalSpacer_3 = new QSpacerItem(347, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);

        tw_mapType->addTab(tab_2, QString());

        gridLayout_4->addWidget(tw_mapType, 3, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 137, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 1, 2, 2, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 1, 1, 1, 1);

        TahoMainW->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TahoMainW);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 761, 17));
        menuDatei = new QMenu(menuBar);
        menuDatei->setObjectName(QString::fromUtf8("menuDatei"));
        menuBearbeiten = new QMenu(menuBar);
        menuBearbeiten->setObjectName(QString::fromUtf8("menuBearbeiten"));
        menuHilfe = new QMenu(menuBar);
        menuHilfe->setObjectName(QString::fromUtf8("menuHilfe"));
        TahoMainW->setMenuBar(menuBar);

        menuBar->addAction(menuDatei->menuAction());
        menuBar->addAction(menuBearbeiten->menuAction());
        menuBar->addAction(menuHilfe->menuAction());
        menuDatei->addAction(actionEinstellungen_laden);
        menuDatei->addAction(actionEinstellungen_speichern);
        menuDatei->addSeparator();
        menuDatei->addAction(actionBeenden);
        menuBearbeiten->addAction(actionKarten_erstellen);
        menuBearbeiten->addAction(actionOSMBugs_holen);
        menuBearbeiten->addAction(actionKMZ_erstellen);
        menuBearbeiten->addSeparator();
        menuBearbeiten->addAction(actionOptionen);
        menuHilfe->addAction(actionHilfe);
        menuHilfe->addSeparator();
        menuHilfe->addAction(actionInfo);

        retranslateUi(TahoMainW);
        QObject::connect(pb_doTaho, SIGNAL(clicked()), TahoMainW, SLOT(OnDoTaho()));
        QObject::connect(pb_z0, SIGNAL(clicked()), TahoMainW, SLOT(OnZ0()));
        QObject::connect(pb_z2, SIGNAL(clicked()), TahoMainW, SLOT(OnZ2()));
        QObject::connect(pb_zAll, SIGNAL(clicked()), TahoMainW, SLOT(OnZAll()));
        QObject::connect(cb_auto, SIGNAL(clicked()), TahoMainW, SLOT(OnAutoOut()));
        QObject::connect(pb_out, SIGNAL(clicked()), TahoMainW, SLOT(OnGetOut()));
        QObject::connect(pb_help, SIGNAL(clicked()), TahoMainW, SLOT(OnHelpB()));
        QObject::connect(pb_quit, SIGNAL(clicked()), TahoMainW, SLOT(OnCancel()));
        QObject::connect(pb_bbox, SIGNAL(clicked()), TahoMainW, SLOT(OnBnClickedBbox()));
        QObject::connect(cb_size, SIGNAL(currentIndexChanged(int)), TahoMainW, SLOT(OnSelchangeSizec(int)));
        QObject::connect(cb_quelle, SIGNAL(currentIndexChanged(int)), TahoMainW, SLOT(OnSelchangeSourceP()));
        QObject::connect(tw_mapType, SIGNAL(currentChanged(int)), TahoMainW, SLOT(OnSelchangedMapType(int)));
        QObject::connect(lw_vect, SIGNAL(itemChanged(QListWidgetItem*)), TahoMainW, SLOT(OnMapChanged(QListWidgetItem*)));
        QObject::connect(lw_overl, SIGNAL(itemChanged(QListWidgetItem*)), TahoMainW, SLOT(OnMapChanged(QListWidgetItem*)));

        tw_mapType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TahoMainW);
    } // setupUi

    void retranslateUi(QMainWindow *TahoMainW)
    {
        actionEinstellungen_laden->setText(QApplication::translate("TahoMainW", "Einstellungen laden", nullptr));
        actionEinstellungen_speichern->setText(QApplication::translate("TahoMainW", "Einstellungen speichern", nullptr));
        actionKarten_erstellen->setText(QApplication::translate("TahoMainW", "Karten erstellen", nullptr));
        actionOSMBugs_holen->setText(QApplication::translate("TahoMainW", "OSMBugs holen", nullptr));
        actionKMZ_erstellen->setText(QApplication::translate("TahoMainW", "KMZ erstellen", nullptr));
        actionOptionen->setText(QApplication::translate("TahoMainW", "Optionen", nullptr));
        actionHilfe->setText(QApplication::translate("TahoMainW", "Hilfe", nullptr));
        actionInfo->setText(QApplication::translate("TahoMainW", "Info", nullptr));
        actionBeenden->setText(QApplication::translate("TahoMainW", "Beenden", nullptr));
        groupBox_2->setTitle(QApplication::translate("TahoMainW", "Ausgabe", nullptr));
        label_10->setText(QApplication::translate("TahoMainW", "Benenne Files mit:", nullptr));
        rb_nbNr->setText(QApplication::translate("TahoMainW", "Nr.", nullptr));
        rb_nbKoord->setText(QApplication::translate("TahoMainW", "Koord.", nullptr));
        rb_nbDir->setText(QApplication::translate("TahoMainW", "Ordner", nullptr));
        cb_auto->setText(QApplication::translate("TahoMainW", "Auto", nullptr));
        pb_doTaho->setText(QApplication::translate("TahoMainW", "Erstelle Karten", nullptr));
        pb_help->setText(QApplication::translate("TahoMainW", "Hilfe", nullptr));
        pb_quit->setText(QApplication::translate("TahoMainW", "Beenden", nullptr));
        groupBox->setTitle(QApplication::translate("TahoMainW", "Kartenbereich", nullptr));
        label_2->setText(QApplication::translate("TahoMainW", "Breite 1:", nullptr));
        label_3->setText(QApplication::translate("TahoMainW", "Grad", nullptr));
        label->setText(QApplication::translate("TahoMainW", "L\303\244nge1:", nullptr));
        label_4->setText(QApplication::translate("TahoMainW", "Grad", nullptr));
        label_5->setText(QApplication::translate("TahoMainW", "L\303\244nge2:", nullptr));
        label_6->setText(QApplication::translate("TahoMainW", "Grad", nullptr));
        label_7->setText(QApplication::translate("TahoMainW", "Breite2:", nullptr));
        label_8->setText(QApplication::translate("TahoMainW", "Grad", nullptr));
        label_9->setText(QApplication::translate("TahoMainW", "Bereich grafisch aus Karte w\303\244hlen", nullptr));
        pb_bbox->setText(QApplication::translate("TahoMainW", "BBox Tool", nullptr));
        label_11->setText(QApplication::translate("TahoMainW", "Quelle:", nullptr));
        label_12->setText(QApplication::translate("TahoMainW", "Overlays:", nullptr));
        l_kal->setText(QApplication::translate("TahoMainW", "Kal.Files:", nullptr));

        const bool __sortingEnabled = lw_kal->isSortingEnabled();
        lw_kal->setSortingEnabled(false);
        lw_kal->setSortingEnabled(__sortingEnabled);

        groupBox_3->setTitle(QApplication::translate("TahoMainW", "Zoomstufen", nullptr));

        const bool __sortingEnabled1 = lw_zoom->isSortingEnabled();
        lw_zoom->setSortingEnabled(false);
        lw_zoom->setSortingEnabled(__sortingEnabled1);

        pb_zAll->setText(QApplication::translate("TahoMainW", "alle ausw\303\244hlen", nullptr));
        pb_z2->setText(QApplication::translate("TahoMainW", "jedes 2. ausw.", nullptr));
        pb_z0->setText(QApplication::translate("TahoMainW", "alle l\303\266schen", nullptr));
        l_bpp->setText(QApplication::translate("TahoMainW", "Bits/Pixel:", nullptr));

        label_15->setText(QApplication::translate("TahoMainW", "Gr\303\266\303\237e:", nullptr));
        cb_size->setItemText(0, QApplication::translate("TahoMainW", "frei (ganzer Bereich in 1 File)", nullptr));
        cb_size->setItemText(1, QApplication::translate("TahoMainW", "keine (nur Kacheln 256*256)", nullptr));

        groupBox_4->setTitle(QApplication::translate("TahoMainW", "Filetyp", nullptr));
        tw_mapType->setTabText(tw_mapType->indexOf(tab), QApplication::translate("TahoMainW", "Pixelkarten", nullptr));
        label_16->setText(QApplication::translate("TahoMainW", "Quelle:", nullptr));
        tw_mapType->setTabText(tw_mapType->indexOf(tab_2), QApplication::translate("TahoMainW", "Vektorkarten", nullptr));
        menuDatei->setTitle(QApplication::translate("TahoMainW", "Datei", nullptr));
        menuBearbeiten->setTitle(QApplication::translate("TahoMainW", "Bearbeiten", nullptr));
        menuHilfe->setTitle(QApplication::translate("TahoMainW", "Hilfe", nullptr));
        Q_UNUSED(TahoMainW);
    } // retranslateUi

};

namespace Ui {
    class TahoMainW: public Ui_TahoMainW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAHOMAINW_H
