#include "mainwindow.h"
#include <QApplication>
#include "qpainter.h"
#include"qtableview.h"
#include "QHBoxLayout"
#include"QPushButton"
#include <QTextCodec>
#include "sqlconnector.h"


int main(int argc, char *argv[])
{
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QString sPath = a.applicationDirPath();//获取程序当前目录，下两句我就不再注释了 地球人都知道
    sPath += QString("/plugins");
    a.addLibraryPath(sPath);
    MainWindow w;
    w.show();
    return a.exec();
}
