#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>
#include"QtSql"
#include"qmysqlquerymodel.h"
#include"sqlconnector.h"
#include "realqthread.h"
#include"QStackedLayout"
#include "filethread.h"
#define ADDS 1
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
    bool mainth;
    void timerEvent(QTimerEvent *event);
    bool ok;
    QStackedLayout qstack;
    QPointF line1[18][3],line2[18][3];
    int len1,len2;
    int pos1;
    SQLConnector *sqlcon;
    void initializeModel(QMySQlQueryModel *model,QString table);
    void changeModel(QMySQlQueryModel *model,QString table);
    const QString string_table[7] = {"one","two","three","four","five","six","seven"};
    void mainthing();
    void clear_blank(QString &str);
    void make_clear();
    void mainthing2();
    void mainthing3();
    void mainthing4();
    void mainthing5();
    void mainthing6();
    void mainthing7();
    void mainthing8();
    void mainthing9();
    bool on_off;
    bool timers;
    void mainthing10();
    void mainthing11();
    void mainthing12();
    void mainthing14();
    void mainthing15();
    void mainthing16();
    void mainthing17();
    void mainthing18();
    void mainthing19();
    void mainthing20();
    void setstyle(QPushButton *btn);
    void disp(QString kind);
    RealQThread *rt;
    QEventLoop loop;
    QEventLoop loop2;
    FileThread *ft;
    int used;
    int index1;
    int p_index;
    int q_index;
    int s_index;
    QMySQlQueryModel *DataModel;
    bool isDirExist(QString fullPath);
    void FindBestWay(QMySQlQueryModel *model);
    QMySQlQueryModel *DataModel2;
    QString index_chr;
    int Pointof(QPointF *line,int n);
    int a1;
    QMySQlQueryModel *DataModel3;
    bool selected(QSqlDatabase db,int index,int no,QString kind,int times,int num);
    int getXfromMap(int data);
    void selector(int index,int cmp,int mode);
    //bool eventFilter(QObject *target, QEvent *event);
    int getYfromMap(int data);
    void magicTime(QPainter &painter,QPointF *line,QColor color);
    int mapper[5][5];
    void actiona();
    bool taskbegin;
    QString m_kind;
    int m_cmp[11];
    int m_num[36];
    QString m_no;
    int m_bit[9];
    bool taskend;
    void task_reload();
    QString timestring;
    matrix matA[6];
    bool isvalid[6];
    bool isgo = false;
    void exchangeMode(int mode);
    void is_right(int a);
    void set_data(QMySQlQueryModel *DataModel);
    void executeSql(QPointF &line,int x,int y,int add);
    void savepic(int id,int no,int num,int gap,int start,int cmp,QString kind,int pos);
    int baseline;
    QString Enum_type[11] = {"期数","个位","十位","百位","千位","万位","十万","百万"," "," "," " };
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
        int mode;
        QString kind;
        int len;
    }rsq;
    typedef struct{
        int real_id;
        int id;
        int len;
    }rpq;
    rpq response[480];
    rsq pointer1[480];
    rsq pointer2[480];
    int colored;
    int sel_no;
    int sel_num;
    int sel_bit;
    int MAXSIZE;
    void viewer();
    int sel_time;
    QString sql_kind;
    QString sql_bit;
    QString sql_cmp;
    QString sql_num;
    void Func_view(QString table);
    QFile file;
    QString sel_kind;
    const QString list_table[5] = {"pl5_data","qxc_data","fc3d_data","ssq_data","dlt_data"};
    void Delay_MSec_Suspend(unsigned int msec);
    bool b1;
    bool b2;
    bool b3;
    void vieweraction();
    bool b4;
    rsq table_data1[480];
    rsq table_data2[480];
    rsq search_data2[480];
    rsq search_data1[480];
    bool b5;
    bool b6;
    void clearrsq(rsq *r);
    bool b7;
    int pos;
    bool cmp3;
    bool cmp4;
    bool cmp5;
    bool cmp6;
    bool cmp7;
    bool cmp9;
    bool cmp8;
    bool is_ok1;
    bool is_ok2;
    bool is_ok3;
    bool is_ok4;
    bool is_ok5;
    bool is_ok6;
    bool is_ok7;
    bool is_ok8;
    bool is_ok9;
    bool is_ok10;
    bool is_ok11;
    bool is_ok12;
    bool is_ok13;
    bool is_ok14;
    bool is_ok15;
    bool is_ok16;
    bool is_ok17;
    bool is_ok18;
    bool is_ok19;
    bool is_ok20;
    bool is_ok21;
    bool is_ok22;
    bool is_ok23;
    bool is_ok24;
    bool is_ok25;
    bool is_ok26;
    bool is_ok27;
    bool is_ok28;
    bool is_ok29;
    bool is_ok30;
    bool is_ok31;
    bool is_ok32;
    bool is_ok33;
    bool is_ok34;
    bool is_ok35;
    bool is_ok36;
    bool is_ok37;
    bool is_ok38;
    bool is_ok39;
    bool is_ok40;
    bool is_ok41;
    bool is_ok42;
    bool is_ok43;
    bool is_ok44;
    bool is_ok45;
    bool is_ok46;
    bool is_ok47;
    bool is_ok48;
    bool is_ok49;
    bool is_ok50;
    bool is_ok51;
    bool conf1;
    bool conf2;
    int pos2;
    int real_id[400];
    Drawabler *dw1;
    void analyze_prep();
    void analyze();
private slots:
    void handleresult(int var);
    void datatransfer(int start);
    void bitLoadList(int type);
    void numLoadList(int type);
    void timeLoadList(int type);
    void noLoadList(int type);
    void kindLoadList(int type);
    void fuckyou1();
    void fuckyou3();
    void fuckyou2();
    void fuckyou4();
    void fuckyou5();
    void fuckyou6();
    void fuckyou7();
    void fuckyou8();
    void fuckyou9();
    void fuckyou10();
    void fuckyou11();
    void fuckyou12();
    void fuckyou14();
    void fuckyou15();
    void fuckyou16();
    void fuckyou17();
    void fuckyou18();
    void fuckyou19();
    void fuckyou20();
    void on_next_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_qxc_stateChanged(int arg1);

    void on_pl3_stateChanged(int arg1);

    void on_pl5_stateChanged(int arg1);

    void on_fc3d_stateChanged(int arg1);

    void on_ThreeTime_stateChanged(int arg1);

    void on_FourTime_stateChanged(int arg1);

    void on_FiveTime_stateChanged(int arg1);

    void on_SixMoreTime_stateChanged(int arg1);

    void on_Bit_One_stateChanged(int arg1);

    void on_Bit_Two_stateChanged(int arg1);

    void on_Bit_Three_stateChanged(int arg1);

    void on_Bit_Four_stateChanged(int arg1);

    void on_Bit_Five_stateChanged(int arg1);

    void on_Num_Six_stateChanged(int arg1);

    void on_Num_Seven_stateChanged(int arg1);

    void on_Num_Eight_stateChanged(int arg1);

    void on_Num_Nine_stateChanged(int arg1);

    void on_pushButton_4_clicked();

    void on_Num_Zero_stateChanged(int arg1);

    void on_Num_One_stateChanged(int arg1);

    void on_Num_Two_stateChanged(int arg1);

    void on_Num_Three_stateChanged(int arg1);

    void on_Num_Four_stateChanged(int arg1);

    void on_Num_Five_stateChanged(int arg1);


    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_start_clicked();

    void on_pushButton_7_clicked();

    void on_Bit_Six_stateChanged(int arg1);

    void on_Bit_Seven_stateChanged(int arg1);

    void on_pushButton_8_clicked();

    void on_timeEdit_userTimeChanged(const QTime &time);
    void usleep(unsigned int msec);
    void startThread();

    void on_checkBox_stateChanged(int arg1);

signals:
    void GetDBsig(QSqlDatabase db);
    void GetStart(int start);
    void GetCmp(int cmp);
    void GetGap(int gap);
    bool Datatrans(Drawabler *dw);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
