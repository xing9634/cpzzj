/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "realtableview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHello;
    QAction *actionClose;
    QAction *actionAbout_Us;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QLabel *label_14;
    RealTableView *tableView;
    QLabel *label_4;
    QGridLayout *gridLayout;
    QPushButton *start;
    QPushButton *next;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QLabel *label_12;
    QTimeEdit *timeEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QComboBox *cb_bits;
    QLabel *label_5;
    QComboBox *cb_times;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QComboBox *cb_nums;
    QLabel *label_6;
    QComboBox *cb_kinds;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_2;
    QComboBox *cb_no;
    QLabel *label_3;
    QProgressBar *progressBar;
    QLabel *label_16;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *qxc;
    QCheckBox *pl3;
    QCheckBox *pl5;
    QCheckBox *fc3d;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *ThreeTime;
    QCheckBox *FourTime;
    QCheckBox *FiveTime;
    QCheckBox *SixMoreTime;
    QLabel *label_10;
    QGridLayout *gridLayout_3;
    QCheckBox *Bit_One;
    QCheckBox *Bit_Two;
    QCheckBox *Bit_Three;
    QCheckBox *Bit_Four;
    QCheckBox *Bit_Five;
    QCheckBox *Bit_Six;
    QCheckBox *Bit_Seven;
    QLabel *label_11;
    QGridLayout *gridLayout_2;
    QCheckBox *Num_Zero;
    QCheckBox *Num_One;
    QCheckBox *Num_Two;
    QCheckBox *Num_Three;
    QCheckBox *Num_Four;
    QCheckBox *Num_Five;
    QCheckBox *Num_Six;
    QCheckBox *Num_Seven;
    QCheckBox *Num_Eight;
    QCheckBox *Num_Nine;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QLineEdit *seq;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_13;
    QProgressBar *progressBar_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(720, 853);
        MainWindow->setMinimumSize(QSize(720, 853));
        MainWindow->setMaximumSize(QSize(720, 853));
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(225, 247, 255);"));
        actionHello = new QAction(MainWindow);
        actionHello->setObjectName(QStringLiteral("actionHello"));
        actionHello->setCheckable(true);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionAbout_Us = new QAction(MainWindow);
        actionAbout_Us->setObjectName(QStringLiteral("actionAbout_Us"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(720, 830));
        centralWidget->setMaximumSize(QSize(720, 830));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(255, 0, 0);"));

        gridLayout_4->addWidget(label_14, 0, 0, 1, 1);

        tableView = new RealTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEnabled(true);
        tableView->setMinimumSize(QSize(303, 733));
        tableView->setMaximumSize(QSize(303, 733));
        tableView->setStyleSheet(QStringLiteral(""));
        tableView->setMidLineWidth(2);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setTextElideMode(Qt::ElideMiddle);

        gridLayout_4->addWidget(tableView, 1, 0, 18, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";\n"
"color: rgb(85, 0, 255);"));

        gridLayout_4->addWidget(label_4, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        start = new QPushButton(centralWidget);
        start->setObjectName(QStringLiteral("start"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy);
        start->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(0, 255, 255);"));

        gridLayout->addWidget(start, 0, 0, 1, 1);

        next = new QPushButton(centralWidget);
        next->setObjectName(QStringLiteral("next"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(next->sizePolicy().hasHeightForWidth());
        next->setSizePolicy(sizePolicy1);
        next->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(255, 85, 0);"));

        gridLayout->addWidget(next, 0, 1, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(0, 255, 0);"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(0, 0, 255);"));

        gridLayout->addWidget(pushButton_2, 0, 3, 1, 1);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(255, 0, 0);"));

        gridLayout->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(255, 0, 0);"));

        gridLayout->addWidget(pushButton_3, 1, 1, 1, 1);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(255, 0, 0);"));
        pushButton_8->setIconSize(QSize(16, 16));

        gridLayout->addWidget(pushButton_8, 1, 2, 1, 1);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(255, 0, 0);"));

        gridLayout->addWidget(pushButton_7, 1, 3, 1, 1);


        gridLayout_4->addLayout(gridLayout, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 0, 127);"));

        horizontalLayout->addWidget(checkBox);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(170, 0, 255);"));

        horizontalLayout->addWidget(label_12);

        timeEdit = new QTimeEdit(centralWidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 85, 255);"));

        horizontalLayout->addWidget(timeEdit);


        gridLayout_4->addLayout(horizontalLayout, 3, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 255, 0);"));

        horizontalLayout_9->addWidget(label_7);

        cb_bits = new QComboBox(centralWidget);
        cb_bits->setObjectName(QStringLiteral("cb_bits"));
        cb_bits->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);\n"
" border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px;   "));

        horizontalLayout_9->addWidget(cb_bits);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 0, 127);"));

        horizontalLayout_9->addWidget(label_5);

        cb_times = new QComboBox(centralWidget);
        cb_times->setObjectName(QStringLiteral("cb_times"));
        cb_times->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);\n"
" border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px;   "));

        horizontalLayout_9->addWidget(cb_times);


        gridLayout_4->addLayout(horizontalLayout_9, 4, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 0, 0);"));

        horizontalLayout_8->addWidget(label);

        cb_nums = new QComboBox(centralWidget);
        cb_nums->setObjectName(QStringLiteral("cb_nums"));
        cb_nums->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);\n"
" border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px;   "));

        horizontalLayout_8->addWidget(cb_nums);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 85, 0);"));

        horizontalLayout_8->addWidget(label_6);

        cb_kinds = new QComboBox(centralWidget);
        cb_kinds->setObjectName(QStringLiteral("cb_kinds"));
        cb_kinds->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);\n"
" border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px;   "));

        horizontalLayout_8->addWidget(cb_kinds);


        gridLayout_4->addLayout(horizontalLayout_8, 5, 1, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        horizontalLayout_10->addWidget(label_2);

        cb_no = new QComboBox(centralWidget);
        cb_no->setObjectName(QStringLiteral("cb_no"));
        cb_no->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);\n"
" border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 2px 1px 2px;   "));

        horizontalLayout_10->addWidget(cb_no);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 0, 0);"));

        horizontalLayout_10->addWidget(label_3);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 85, 255);\n"
"border: 2px solid grey;\n"
"   border-radius: 5px;\n"
"   text-align: center;\n"
"   background-color: #FFFFFF;\n"
"chunk{\n"
"background-color: #05B8CC;\n"
"   width: 20px;\n"
"}"));
        progressBar->setValue(24);

        horizontalLayout_10->addWidget(progressBar);


        gridLayout_4->addLayout(horizontalLayout_10, 6, 1, 1, 1);

        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\232\266\344\271\246\";\n"
"text-decoration: underline;\n"
"color: rgb(255, 0, 0);"));

        gridLayout_4->addWidget(label_16, 7, 1, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(0, 0, 255);"));

        gridLayout_4->addWidget(label_8, 8, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        qxc = new QCheckBox(centralWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(qxc);
        qxc->setObjectName(QStringLiteral("qxc"));
        qxc->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 0, 127);"));

        horizontalLayout_7->addWidget(qxc);

        pl3 = new QCheckBox(centralWidget);
        buttonGroup->addButton(pl3);
        pl3->setObjectName(QStringLiteral("pl3"));
        pl3->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 0, 0);"));

        horizontalLayout_7->addWidget(pl3);

        pl5 = new QCheckBox(centralWidget);
        buttonGroup->addButton(pl5);
        pl5->setObjectName(QStringLiteral("pl5"));
        pl5->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 170, 0);"));

        horizontalLayout_7->addWidget(pl5);

        fc3d = new QCheckBox(centralWidget);
        buttonGroup->addButton(fc3d);
        fc3d->setObjectName(QStringLiteral("fc3d"));
        fc3d->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        horizontalLayout_7->addWidget(fc3d);


        gridLayout_4->addLayout(horizontalLayout_7, 9, 1, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(255, 85, 127);"));

        gridLayout_4->addWidget(label_9, 10, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        ThreeTime = new QCheckBox(centralWidget);
        ThreeTime->setObjectName(QStringLiteral("ThreeTime"));
        ThreeTime->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        horizontalLayout_6->addWidget(ThreeTime);

        FourTime = new QCheckBox(centralWidget);
        FourTime->setObjectName(QStringLiteral("FourTime"));
        FourTime->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        horizontalLayout_6->addWidget(FourTime);

        FiveTime = new QCheckBox(centralWidget);
        FiveTime->setObjectName(QStringLiteral("FiveTime"));
        FiveTime->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        horizontalLayout_6->addWidget(FiveTime);

        SixMoreTime = new QCheckBox(centralWidget);
        SixMoreTime->setObjectName(QStringLiteral("SixMoreTime"));
        SixMoreTime->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        horizontalLayout_6->addWidget(SixMoreTime);


        gridLayout_4->addLayout(horizontalLayout_6, 11, 1, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(255, 85, 0);"));

        gridLayout_4->addWidget(label_10, 12, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        Bit_One = new QCheckBox(centralWidget);
        Bit_One->setObjectName(QStringLiteral("Bit_One"));
        Bit_One->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 255, 0);"));

        gridLayout_3->addWidget(Bit_One, 0, 0, 1, 1);

        Bit_Two = new QCheckBox(centralWidget);
        Bit_Two->setObjectName(QStringLiteral("Bit_Two"));
        Bit_Two->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 85, 255);"));

        gridLayout_3->addWidget(Bit_Two, 0, 1, 1, 1);

        Bit_Three = new QCheckBox(centralWidget);
        Bit_Three->setObjectName(QStringLiteral("Bit_Three"));
        Bit_Three->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 0, 0);"));

        gridLayout_3->addWidget(Bit_Three, 0, 2, 1, 1);

        Bit_Four = new QCheckBox(centralWidget);
        Bit_Four->setObjectName(QStringLiteral("Bit_Four"));
        Bit_Four->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 85, 127);"));

        gridLayout_3->addWidget(Bit_Four, 0, 3, 1, 1);

        Bit_Five = new QCheckBox(centralWidget);
        Bit_Five->setObjectName(QStringLiteral("Bit_Five"));
        Bit_Five->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 0, 255);"));

        gridLayout_3->addWidget(Bit_Five, 1, 0, 1, 1);

        Bit_Six = new QCheckBox(centralWidget);
        Bit_Six->setObjectName(QStringLiteral("Bit_Six"));
        Bit_Six->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 85, 255);"));

        gridLayout_3->addWidget(Bit_Six, 1, 1, 1, 1);

        Bit_Seven = new QCheckBox(centralWidget);
        Bit_Seven->setObjectName(QStringLiteral("Bit_Seven"));
        Bit_Seven->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 85, 0);"));

        gridLayout_3->addWidget(Bit_Seven, 1, 2, 1, 2);


        gridLayout_4->addLayout(gridLayout_3, 13, 1, 1, 1);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(170, 0, 255);"));

        gridLayout_4->addWidget(label_11, 14, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        Num_Zero = new QCheckBox(centralWidget);
        Num_Zero->setObjectName(QStringLiteral("Num_Zero"));
        Num_Zero->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        gridLayout_2->addWidget(Num_Zero, 0, 0, 1, 1);

        Num_One = new QCheckBox(centralWidget);
        Num_One->setObjectName(QStringLiteral("Num_One"));
        Num_One->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        gridLayout_2->addWidget(Num_One, 0, 1, 1, 1);

        Num_Two = new QCheckBox(centralWidget);
        Num_Two->setObjectName(QStringLiteral("Num_Two"));
        Num_Two->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        gridLayout_2->addWidget(Num_Two, 0, 2, 1, 1);

        Num_Three = new QCheckBox(centralWidget);
        Num_Three->setObjectName(QStringLiteral("Num_Three"));
        Num_Three->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        gridLayout_2->addWidget(Num_Three, 0, 3, 1, 1);

        Num_Four = new QCheckBox(centralWidget);
        Num_Four->setObjectName(QStringLiteral("Num_Four"));
        Num_Four->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        gridLayout_2->addWidget(Num_Four, 0, 4, 1, 1);

        Num_Five = new QCheckBox(centralWidget);
        Num_Five->setObjectName(QStringLiteral("Num_Five"));
        Num_Five->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        gridLayout_2->addWidget(Num_Five, 1, 0, 1, 1);

        Num_Six = new QCheckBox(centralWidget);
        Num_Six->setObjectName(QStringLiteral("Num_Six"));
        Num_Six->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        gridLayout_2->addWidget(Num_Six, 1, 1, 1, 1);

        Num_Seven = new QCheckBox(centralWidget);
        Num_Seven->setObjectName(QStringLiteral("Num_Seven"));
        Num_Seven->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        gridLayout_2->addWidget(Num_Seven, 1, 2, 1, 1);

        Num_Eight = new QCheckBox(centralWidget);
        Num_Eight->setObjectName(QStringLiteral("Num_Eight"));
        Num_Eight->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        gridLayout_2->addWidget(Num_Eight, 1, 3, 1, 1);

        Num_Nine = new QCheckBox(centralWidget);
        Num_Nine->setObjectName(QStringLiteral("Num_Nine"));
        Num_Nine->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        gridLayout_2->addWidget(Num_Nine, 1, 4, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 15, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        horizontalLayout_3->addWidget(label_15);

        seq = new QLineEdit(centralWidget);
        seq->setObjectName(QStringLiteral("seq"));
        seq->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 255);"));

        horizontalLayout_3->addWidget(seq);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 17pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(85, 0, 255);"));

        horizontalLayout_4->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setStyleSheet(QString::fromUtf8("font: 17pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";\n"
"color: rgb(85, 0, 255);"));

        horizontalLayout_4->addWidget(pushButton_5);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout_4->addLayout(verticalLayout, 16, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(85, 170, 255);"));

        horizontalLayout_2->addWidget(label_13);

        progressBar_2 = new QProgressBar(centralWidget);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 85, 255);\n"
"border: 2px solid grey;\n"
"   border-radius: 5px;\n"
"   text-align: center;\n"
"   background-color: #FFFFFF;"));
        progressBar_2->setValue(24);

        horizontalLayout_2->addWidget(progressBar_2);


        gridLayout_4->addLayout(horizontalLayout_2, 17, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 720, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionClose);
        menu_2->addAction(actionAbout_Us);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\275\251\347\245\250\350\247\204\345\276\213\347\250\213\345\272\217", nullptr));
        actionHello->setText(QApplication::translate("MainWindow", "Hello", nullptr));
        actionClose->setText(QApplication::translate("MainWindow", "Close", nullptr));
        actionAbout_Us->setText(QApplication::translate("MainWindow", "About Us", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\233\276\350\241\250 \357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\275\251\347\245\250\344\270\255\344\270\255\345\245\226&\350\247\204\345\276\213\346\237\245\346\211\276\347\250\213\345\272\217\n"
"Copyright2019 David Peng", nullptr));
        start->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\350\247\204\345\276\213", nullptr));
        next->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\346\225\260\346\215\256", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\347\262\276\347\241\256\346\237\245\347\234\213", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\351\200\220\344\270\200\346\237\245\347\234\213", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\347\224\273\347\272\277", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\225\260\346\215\256", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\350\247\204\345\276\213", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\351\200\211\346\213\251", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\346\230\257\345\220\246\345\220\257\347\224\250\350\207\252\345\212\250\344\277\235\345\255\230", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\344\277\235\345\255\230\346\227\266\351\227\264", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\346\214\211\344\275\215\345\257\273\346\211\276", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\346\254\241\346\225\260\345\257\273\346\211\276", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\214\211\346\225\260\345\257\273\346\211\276", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\345\275\251\347\245\250\347\247\215\347\261\273", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\350\246\201\346\237\245\346\211\276\347\232\204\346\234\237\346\225\260", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\350\277\233\345\272\246", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "------------------\345\210\206\345\211\262\347\272\277------------------", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\345\275\251\347\245\250\347\247\215\347\261\273", nullptr));
        qxc->setText(QApplication::translate("MainWindow", "\344\270\203\346\230\237\345\275\251", nullptr));
        pl3->setText(QApplication::translate("MainWindow", "\346\216\222\345\210\2273", nullptr));
        pl5->setText(QApplication::translate("MainWindow", "\346\216\222\345\210\2275", nullptr));
        fc3d->setText(QApplication::translate("MainWindow", "\347\246\217\345\275\2513D", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\351\207\215\345\244\215\346\254\241\346\225\260", nullptr));
        ThreeTime->setText(QApplication::translate("MainWindow", "3\346\254\241", nullptr));
        FourTime->setText(QApplication::translate("MainWindow", "4\346\254\241", nullptr));
        FiveTime->setText(QApplication::translate("MainWindow", "5\346\254\241", nullptr));
        SixMoreTime->setText(QApplication::translate("MainWindow", "6\346\254\241\345\217\212\344\273\245\344\270\212", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\344\275\215\346\225\260\351\200\211\346\213\251", nullptr));
        Bit_One->setText(QApplication::translate("MainWindow", "\344\270\200\344\275\215", nullptr));
        Bit_Two->setText(QApplication::translate("MainWindow", "\344\270\244\344\275\215", nullptr));
        Bit_Three->setText(QApplication::translate("MainWindow", "\344\270\211\344\275\215", nullptr));
        Bit_Four->setText(QApplication::translate("MainWindow", "\345\233\233\344\275\215", nullptr));
        Bit_Five->setText(QApplication::translate("MainWindow", "\344\272\224\344\275\215", nullptr));
        Bit_Six->setText(QApplication::translate("MainWindow", "\345\205\255\344\275\215", nullptr));
        Bit_Seven->setText(QApplication::translate("MainWindow", "\344\270\203\344\275\215", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\350\247\204\345\276\213\346\225\260\345\255\227", nullptr));
        Num_Zero->setText(QApplication::translate("MainWindow", "0", nullptr));
        Num_One->setText(QApplication::translate("MainWindow", "1", nullptr));
        Num_Two->setText(QApplication::translate("MainWindow", "2", nullptr));
        Num_Three->setText(QApplication::translate("MainWindow", "3", nullptr));
        Num_Four->setText(QApplication::translate("MainWindow", "4", nullptr));
        Num_Five->setText(QApplication::translate("MainWindow", "5", nullptr));
        Num_Six->setText(QApplication::translate("MainWindow", "6", nullptr));
        Num_Seven->setText(QApplication::translate("MainWindow", "7", nullptr));
        Num_Eight->setText(QApplication::translate("MainWindow", "8", nullptr));
        Num_Nine->setText(QApplication::translate("MainWindow", "9", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\346\214\207\345\256\232\350\214\203\345\233\264\346\237\245\346\211\276\346\234\237\346\225\260", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\345\210\206\346\236\220", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\345\233\276\347\211\207", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\237\245\346\211\276\350\277\233\345\272\246", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
