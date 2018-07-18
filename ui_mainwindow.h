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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "realtableview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHello;
    QWidget *centralWidget;
    QPushButton *prev;
    QPushButton *next;
    RealTableView *tableView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rb1;
    QRadioButton *rb2;
    QRadioButton *rb3;
    QRadioButton *rb4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *start;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QButtonGroup *rbgp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(420, 623);
        MainWindow->setMinimumSize(QSize(420, 600));
        MainWindow->setMaximumSize(QSize(420, 623));
        actionHello = new QAction(MainWindow);
        actionHello->setObjectName(QStringLiteral("actionHello"));
        actionHello->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(420, 600));
        centralWidget->setMaximumSize(QSize(420, 600));
        prev = new QPushButton(centralWidget);
        prev->setObjectName(QStringLiteral("prev"));
        prev->setGeometry(QRect(90, 450, 75, 23));
        next = new QPushButton(centralWidget);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(250, 450, 75, 23));
        tableView = new RealTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEnabled(true);
        tableView->setGeometry(QRect(10, 22, 395, 420));
        tableView->setMinimumSize(QSize(395, 420));
        tableView->setMaximumSize(QSize(395, 420));
        tableView->setStyleSheet(QStringLiteral(""));
        tableView->setMidLineWidth(2);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setTextElideMode(Qt::ElideMiddle);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 580, 232, 18));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rb1 = new QRadioButton(layoutWidget);
        rbgp = new QButtonGroup(MainWindow);
        rbgp->setObjectName(QStringLiteral("rbgp"));
        rbgp->addButton(rb1);
        rb1->setObjectName(QStringLiteral("rb1"));

        horizontalLayout->addWidget(rb1);

        rb2 = new QRadioButton(layoutWidget);
        rbgp->addButton(rb2);
        rb2->setObjectName(QStringLiteral("rb2"));

        horizontalLayout->addWidget(rb2);

        rb3 = new QRadioButton(layoutWidget);
        rbgp->addButton(rb3);
        rb3->setObjectName(QStringLiteral("rb3"));

        horizontalLayout->addWidget(rb3);

        rb4 = new QRadioButton(layoutWidget);
        rbgp->addButton(rb4);
        rb4->setObjectName(QStringLiteral("rb4"));

        horizontalLayout->addWidget(rb4);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(160, 480, 82, 54));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton, 0, Qt::AlignTop);

        start = new QPushButton(layoutWidget1);
        start->setObjectName(QStringLiteral("start"));
        sizePolicy.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(start);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(110, 550, 180, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        spinBox = new QSpinBox(layoutWidget2);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_2->addWidget(spinBox);

        progressBar = new QProgressBar(layoutWidget2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_2->addWidget(progressBar);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 420, 23));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionHello->setText(QApplication::translate("MainWindow", "Hello", nullptr));
        prev->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        next->setText(QApplication::translate("MainWindow", "\345\205\201\350\256\270RU", nullptr));
        rb1->setText(QApplication::translate("MainWindow", "\344\270\252", nullptr));
        rb2->setText(QApplication::translate("MainWindow", "\345\215\201", nullptr));
        rb3->setText(QApplication::translate("MainWindow", "\347\231\276", nullptr));
        rb4->setText(QApplication::translate("MainWindow", "\345\215\203", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213", nullptr));
        start->setText(QApplication::translate("MainWindow", "\345\257\273\357\274\210\346\205\216\347\224\250\357\274\211", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
