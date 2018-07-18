#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"QtSql"
#include"qmysqlquerymodel.h"
#include"sqlconnector.h"
#include"QStackedLayout"
#define MAXCMP 9
#define ADDS 2
#define MAXNO 18000
#include"realtableview.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int reindex;
    bool ok;
    QStackedLayout qstack;
    QPointF line1[8][3],line2[8][3];
    int len1,len2;
    int pos1;
    SQLConnector *sqlcon;
    void initializeModel(QMySQlQueryModel *model);
    void changeModel(QMySQlQueryModel *model);
    void mainthing();
    void mainthing2();
    void mainthing3();
    void mainthing4();
    void mainthing5();
    void mainthing6();
    void mainthing7();
    void mainthing8();
    void mainthing9();
    int used;
    int index1;
    QMySQlQueryModel *DataModel;
    bool isDirExist(QString fullPath);
    void FindBestWay(QMySQlQueryModel *model);
    QMySQlQueryModel *DataModel2;
    QString index_chr;
    int Pointof(QPointF *line,int n);
    int a1;
    QMySQlQueryModel *DataModel3;
    bool selected(QSqlDatabase db,int index,int start);
    int getXfromMap(int data);
    void selector(int index);
    //bool eventFilter(QObject *target, QEvent *event);
    int getYfromMap(int data);
    void magicTime(QPainter &painter,QPointF *line,QColor color);
    int mapper[5000][4];
    void executeSql(QPointF &line,int x,int y);
    void savepic(int id,int index);
    int baseline;
    typedef struct
    {
        int id;
        int num;
        int one;
        int two;
        int three;
        int start;
        int pos;
        int gap;
        int cmp;
        int len;
    }rsq;
    typedef struct{
        int real_id;
        int id;
        int len;
    }rpq;
    rpq response[8000];
    rsq pointer1[10000];
    rsq pointer2[10000];
    int colored;
    bool b1;
    bool b2;
    bool b3;
    bool b4;
    int real_id[400];
private slots:
    void fuckyou1();
    void fuckyou3();
    void fuckyou2();
    void fuckyou4();
    void fuckyou5();
    void fuckyou6();
    void fuckyou7();
    void fuckyou8();
    void fuckyou9();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
