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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "realtableview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHello;
    QWidget *centralWidget;
    RealTableView *tableView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *prev;
    QPushButton *start;
    QPushButton *next;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QComboBox *cb_bits;
    QLabel *label_5;
    QComboBox *cb_times;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *cb_nums;
    QLabel *label_6;
    QComboBox *cb_kinds;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QComboBox *cb_no;
    QLabel *label_3;
    QProgressBar *progressBar;
    QGridLayout *gridLayout_5;
    QLabel *label_8;
    QCheckBox *qxc;
    QCheckBox *pl3;
    QCheckBox *pl5;
    QCheckBox *fc3d;
    QGridLayout *gridLayout_4;
    QLabel *label_9;
    QCheckBox *ThreeTime;
    QCheckBox *FourTime;
    QCheckBox *FiveTime;
    QCheckBox *SixMoreTime;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QCheckBox *Bit_One;
    QCheckBox *Bit_Two;
    QCheckBox *Bit_Three;
    QCheckBox *Bit_Four;
    QCheckBox *Bit_Five;
    QCheckBox *Bit_Six;
    QCheckBox *Bit_Seven;
    QGridLayout *gridLayout_2;
    QLabel *label_11;
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
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_4;
    QLineEdit *seq;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(900, 1880);
        MainWindow->setMinimumSize(QSize(900, 1880));
        MainWindow->setMaximumSize(QSize(900, 1903));
        actionHello = new QAction(MainWindow);
        actionHello->setObjectName(QStringLiteral("actionHello"));
        actionHello->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(900, 1880));
        centralWidget->setMaximumSize(QSize(900, 1880));
        tableView = new RealTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEnabled(true);
        tableView->setGeometry(QRect(0, 0, 395, 1550));
        tableView->setMinimumSize(QSize(395, 1550));
        tableView->setMaximumSize(QSize(395, 1550));
        tableView->setStyleSheet(QStringLiteral(""));
        tableView->setMidLineWidth(2);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setTextElideMode(Qt::ElideMiddle);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(410, 13, 409, 461));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        prev = new QPushButton(layoutWidget);
        prev->setObjectName(QStringLiteral("prev"));

        horizontalLayout->addWidget(prev);

        start = new QPushButton(layoutWidget);
        start->setObjectName(QStringLiteral("start"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(start);

        next = new QPushButton(layoutWidget);
        next->setObjectName(QStringLiteral("next"));

        horizontalLayout->addWidget(next);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        cb_bits = new QComboBox(layoutWidget);
        cb_bits->setObjectName(QStringLiteral("cb_bits"));

        horizontalLayout_2->addWidget(cb_bits);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        cb_times = new QComboBox(layoutWidget);
        cb_times->setObjectName(QStringLiteral("cb_times"));

        horizontalLayout_2->addWidget(cb_times);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        cb_nums = new QComboBox(layoutWidget);
        cb_nums->setObjectName(QStringLiteral("cb_nums"));

        horizontalLayout_3->addWidget(cb_nums);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        cb_kinds = new QComboBox(layoutWidget);
        cb_kinds->setObjectName(QStringLiteral("cb_kinds"));

        horizontalLayout_3->addWidget(cb_kinds);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        cb_no = new QComboBox(layoutWidget);
        cb_no->setObjectName(QStringLiteral("cb_no"));

        horizontalLayout_4->addWidget(cb_no);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_4->addWidget(progressBar);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_5->addWidget(label_8, 0, 0, 1, 1);

        qxc = new QCheckBox(layoutWidget);
        qxc->setObjectName(QStringLiteral("qxc"));

        gridLayout_5->addWidget(qxc, 1, 0, 1, 1);

        pl3 = new QCheckBox(layoutWidget);
        pl3->setObjectName(QStringLiteral("pl3"));

        gridLayout_5->addWidget(pl3, 1, 1, 1, 1);

        pl5 = new QCheckBox(layoutWidget);
        pl5->setObjectName(QStringLiteral("pl5"));

        gridLayout_5->addWidget(pl5, 1, 2, 1, 1);

        fc3d = new QCheckBox(layoutWidget);
        fc3d->setObjectName(QStringLiteral("fc3d"));

        gridLayout_5->addWidget(fc3d, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_4->addWidget(label_9, 0, 0, 1, 1);

        ThreeTime = new QCheckBox(layoutWidget);
        ThreeTime->setObjectName(QStringLiteral("ThreeTime"));

        gridLayout_4->addWidget(ThreeTime, 1, 0, 1, 1);

        FourTime = new QCheckBox(layoutWidget);
        FourTime->setObjectName(QStringLiteral("FourTime"));

        gridLayout_4->addWidget(FourTime, 1, 1, 1, 1);

        FiveTime = new QCheckBox(layoutWidget);
        FiveTime->setObjectName(QStringLiteral("FiveTime"));

        gridLayout_4->addWidget(FiveTime, 1, 2, 1, 1);

        SixMoreTime = new QCheckBox(layoutWidget);
        SixMoreTime->setObjectName(QStringLiteral("SixMoreTime"));

        gridLayout_4->addWidget(SixMoreTime, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        Bit_One = new QCheckBox(layoutWidget);
        Bit_One->setObjectName(QStringLiteral("Bit_One"));

        gridLayout_3->addWidget(Bit_One, 1, 0, 1, 1);

        Bit_Two = new QCheckBox(layoutWidget);
        Bit_Two->setObjectName(QStringLiteral("Bit_Two"));

        gridLayout_3->addWidget(Bit_Two, 1, 1, 1, 1);

        Bit_Three = new QCheckBox(layoutWidget);
        Bit_Three->setObjectName(QStringLiteral("Bit_Three"));

        gridLayout_3->addWidget(Bit_Three, 1, 2, 1, 1);

        Bit_Four = new QCheckBox(layoutWidget);
        Bit_Four->setObjectName(QStringLiteral("Bit_Four"));

        gridLayout_3->addWidget(Bit_Four, 1, 3, 1, 1);

        Bit_Five = new QCheckBox(layoutWidget);
        Bit_Five->setObjectName(QStringLiteral("Bit_Five"));

        gridLayout_3->addWidget(Bit_Five, 2, 0, 1, 1);

        Bit_Six = new QCheckBox(layoutWidget);
        Bit_Six->setObjectName(QStringLiteral("Bit_Six"));

        gridLayout_3->addWidget(Bit_Six, 2, 1, 1, 1);

        Bit_Seven = new QCheckBox(layoutWidget);
        Bit_Seven->setObjectName(QStringLiteral("Bit_Seven"));

        gridLayout_3->addWidget(Bit_Seven, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        Num_Zero = new QCheckBox(layoutWidget);
        Num_Zero->setObjectName(QStringLiteral("Num_Zero"));

        gridLayout_2->addWidget(Num_Zero, 1, 0, 1, 1);

        Num_One = new QCheckBox(layoutWidget);
        Num_One->setObjectName(QStringLiteral("Num_One"));

        gridLayout_2->addWidget(Num_One, 1, 1, 1, 1);

        Num_Two = new QCheckBox(layoutWidget);
        Num_Two->setObjectName(QStringLiteral("Num_Two"));

        gridLayout_2->addWidget(Num_Two, 1, 2, 1, 1);

        Num_Three = new QCheckBox(layoutWidget);
        Num_Three->setObjectName(QStringLiteral("Num_Three"));

        gridLayout_2->addWidget(Num_Three, 1, 3, 1, 1);

        Num_Four = new QCheckBox(layoutWidget);
        Num_Four->setObjectName(QStringLiteral("Num_Four"));

        gridLayout_2->addWidget(Num_Four, 2, 0, 1, 1);

        Num_Five = new QCheckBox(layoutWidget);
        Num_Five->setObjectName(QStringLiteral("Num_Five"));

        gridLayout_2->addWidget(Num_Five, 2, 1, 1, 1);

        Num_Six = new QCheckBox(layoutWidget);
        Num_Six->setObjectName(QStringLiteral("Num_Six"));

        gridLayout_2->addWidget(Num_Six, 2, 2, 1, 1);

        Num_Seven = new QCheckBox(layoutWidget);
        Num_Seven->setObjectName(QStringLiteral("Num_Seven"));

        gridLayout_2->addWidget(Num_Seven, 2, 3, 1, 1);

        Num_Eight = new QCheckBox(layoutWidget);
        Num_Eight->setObjectName(QStringLiteral("Num_Eight"));

        gridLayout_2->addWidget(Num_Eight, 3, 0, 1, 1);

        Num_Nine = new QCheckBox(layoutWidget);
        Num_Nine->setObjectName(QStringLiteral("Num_Nine"));

        gridLayout_2->addWidget(Num_Nine, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_5->addWidget(pushButton_4);

        seq = new QLineEdit(layoutWidget);
        seq->setObjectName(QStringLiteral("seq"));

        horizontalLayout_5->addWidget(seq);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_5->addWidget(pushButton_5);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(verticalLayout_2);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout_3->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout_3->addWidget(pushButton_6);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\275\251\347\245\250\350\247\204\345\276\213\347\250\213\345\272\217", nullptr));
        actionHello->setText(QApplication::translate("MainWindow", "Hello", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\275\251\347\245\250\344\270\255\344\270\255\345\245\226&\350\247\204\345\276\213\346\237\245\346\211\276\347\250\213\345\272\217&Copyright2018 David Peng", nullptr));
        prev->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\350\247\204\345\276\213", nullptr));
        start->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\350\247\204\345\276\213", nullptr));
        next->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\346\225\260\346\215\256", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\346\237\245\347\234\213", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\351\232\217\346\234\272\346\237\245\347\234\213", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\346\214\211\344\275\215\345\257\273\346\211\276", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\346\254\241\346\225\260\345\257\273\346\211\276", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\214\211\346\225\260\345\257\273\346\211\276", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\345\275\251\347\245\250\347\247\215\347\261\273", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\225\260\346\215\256", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\350\246\201\346\237\245\346\211\276\347\232\204\346\234\237\346\225\260", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\350\277\233\345\272\246", nullptr));
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
        Bit_One->setText(QApplication::translate("MainWindow", "\344\270\252\344\275\215", nullptr));
        Bit_Two->setText(QApplication::translate("MainWindow", "\345\215\201\344\275\215", nullptr));
        Bit_Three->setText(QApplication::translate("MainWindow", "\347\231\276\344\275\215", nullptr));
        Bit_Four->setText(QApplication::translate("MainWindow", "\345\215\203\344\275\215", nullptr));
        Bit_Five->setText(QApplication::translate("MainWindow", "\344\270\207\344\275\215", nullptr));
        Bit_Six->setText(QApplication::translate("MainWindow", "\345\215\201\344\270\207\344\275\215", nullptr));
        Bit_Seven->setText(QApplication::translate("MainWindow", "\347\231\276\344\270\207\344\275\215", nullptr));
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
        pushButton_4->setText(QApplication::translate("MainWindow", "\345\210\206\346\236\220", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\345\274\240", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\351\200\211\346\213\251", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\350\247\204\345\276\213", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
