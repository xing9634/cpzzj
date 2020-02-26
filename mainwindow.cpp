#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include"qtableview.h"
#include"QMessageBox"
#include <QDateTime>
#include "QHBoxLayout"
#include <QFileDialog>




void MainWindow::initializeModel(QMySQlQueryModel *model,QString table)
  {
       memset(isvalid,false,sizeof(isvalid));
      //QString num = QString::number(pos,10);
     // QString num2 = QString::number(pos+8,10);
     // QString sel = "select one,two,three,four,five,six,seven from data where id_data>="+num+"and id_data<"+num2;
      model->setTable(table);
     // model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      model->removeColumn(0);
      model->removeColumn(9);
      model->select();
      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      for(int i  = 0;i < model->columnCount();i ++)
      {
          const char*  ch;
          ch = Enum_type[i].toStdString().c_str();
          model->setHeaderData(i, Qt::Horizontal, QObject::tr(ch));
      }
      Func_view(table);
      memset(ui->tableView->line1,0,sizeof(line1));
      memset(ui->tableView->line2,0,sizeof(line2));
      memset(line1,0,sizeof(line1));
      memset(line2,0,sizeof(line2));
  }



void MainWindow::changeModel(QMySQlQueryModel *model,QString table)
  {

      //QString num = QString::number(pos,10);
     // QString num2 = QString::number(pos+8,10);
     // QString sel = "select one,two,three,four,five,six,seven from data where id_data>="+num+"and id_data<"+num2;
      model->setTable("MyTable");
     // model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      model->select();
      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      for(int i  = 0;i < model->columnCount();i ++)
      {
          const char*  ch;
          ch = Enum_type[i].toStdString().c_str();
          model->setHeaderData(i, Qt::Horizontal, QObject::tr(ch));
      }
      memset(ui->tableView->line1,0,sizeof(line1));
      memset(ui->tableView->line2,0,sizeof(line2));
      memset(line1,0,sizeof(line1));
      memset(line2,0,sizeof(line2));
  }
void MainWindow::exchangeMode(int mode)
{
    switch(mode)
    {
    case 1 :{
        this->initializeModel(this->DataModel,"qxc_data");
        ui->tableView->setModel(DataModel);
        QFont font;
        font.setFamily("MS Shell Dlg 2"); // Tahoma 宋体
        font.setBold(true);
        ui->tableView->setFont(font);
        ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.25);");
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->setColumnWidth(0,60);actiona();MAXSIZE = 4;set_data(DataModel);break;
        }
    case 4 : {
        this->initializeModel(this->DataModel,"dlt_data");
        ui->tableView->setModel(DataModel);
        QFont font;
        font.setFamily("MS Shell Dlg 2"); // Tahoma 宋体
        font.setBold(true);
        ui->tableView->setFont(font);
        ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.25);");
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->setColumnWidth(0,55);
        actiona();MAXSIZE = 5;set_data(DataModel);break;
        }
    case 2 : {
        this->initializeModel(this->DataModel,"fc3d_data");
        ui->tableView->setModel(DataModel);
        QFont font;
        font.setFamily("MS Shell Dlg 2"); // Tahoma 宋体
        font.setBold(true);
        ui->tableView->setFont(font);
        ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.25);");
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->setColumnWidth(0,55);actiona();MAXSIZE = 3;set_data(DataModel);break;
        }
//    case 4 : {
//        this->initializeModel(this->DataModel,"pl3_data");
//        ui->tableView->setModel(DataModel);
//        QFont font;
//        font.setFamily("MS Shell Dlg 2"); // Tahoma 宋体
//        font.setBold(true);
//        ui->tableView->setFont(font);
//        ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.25);");
//        ui->tableView->setAlternatingRowColors(true);
//        ui->tableView->setColumnWidth(0,55);actiona();MAXSIZE = 3;set_data(DataModel);break;
//        }
    case 0 : {
        this->initializeModel(this->DataModel,"pl5_data");
        ui->tableView->setModel(DataModel);
        QFont font;
        font.setFamily("MS Shell Dlg 2"); // Tahoma 宋体
        font.setBold(true);
        ui->tableView->setFont(font);
        ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.25);");
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->setColumnWidth(0,55);actiona();MAXSIZE = 4;set_data(DataModel);break;
        }
    case 3 : {
        this->initializeModel(this->DataModel,"ssq_data");
        ui->tableView->setModel(DataModel);
        QFont font;
        font.setFamily("MS Shell Dlg 2"); // Tahoma 宋体
        font.setBold(true);
        ui->tableView->setFont(font);
        ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.25);");
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->setColumnWidth(0,55);actiona();MAXSIZE = 5;set_data(DataModel);break;
        }

    }
    int index = 0;
    mainth = true;
    QSqlQuery qsq;
    QSqlQuery qsq1;
    qsq.exec("select rowid from "+sel_kind+" where real_id="+QString::number(sel_no - 1,10) );
    if(qsq.first()) {
        index = qsq.value(0).toInt();
    }
    qsq1.exec("select rowid from "+sel_kind+" limit 0,1");
    if(qsq1.first()) {
        index -= qsq1.value(0).toInt();
        index ++;
    }
    index1 = index;
    emit ui->tableView->is_datachanged(sel_no);
}
void MainWindow::set_data(QMySQlQueryModel *DataModel) {
    int sizeone = 4;
    pos = 0;
    pos2 = 0;
    if(sel_kind == "fc3d_data" || sel_kind == "pl3_data") {
        sizeone = 3;
        int k = 1;
        for(int i = 0;i<4;i++)
        {
            for(int j = 0;j<3;j++)
            {
                mapper[i][j] = k;
                k++;
            }
        }
    } else if(sel_kind == "dlt_data" || sel_kind == "ssq_data") {
        sizeone = 5;
        int k = 1;
        for(int i = 0;i<4;i++)
        {
            for(int j = 0;j<5;j++)
            {
                mapper[i][j] = k;
                k++;
            }
        }
    }
    isvalid[0] = true;
    for(int i = 0;i<DataModel->rowCount();i++)
    {
        for(int j = 1;j<1+sizeone;j++)
        {
            QModelIndex index = DataModel->index(i,j);
            QVariant data = DataModel->data(index,Qt::EditRole);
            matA[0].array[i][j-1] = data.toInt();
            printf("%4d",matA[0].array[i][j - 1]);
        }
        printf("\n");
    }
    if(sel_kind == "qxc_data" || sel_kind == "ssq_data" || sel_kind == "pl5_data" ) {
        isvalid[1] = true;
        for(int i = 0;i<DataModel->rowCount();i++)
        {
            for(int j = 2;j<2 + sizeone;j++)
            {
                QModelIndex index = DataModel->index(i,j);
                QVariant data = DataModel->data(index,Qt::EditRole);
                matA[1].array[i][j-2] = data.toInt();
                printf("%4d",matA[1].array[i][j - 2]);
            }
            printf("\n");
        }
    } if(sel_kind == "qxc_data") {
        isvalid[2] = true;
        for(int i = 0;i<DataModel->rowCount();i++)
        {
            for(int j = 3;j<3 + sizeone;j++)
            {
                QModelIndex index = DataModel->index(i,j);
                QVariant data = DataModel->data(index,Qt::EditRole);
                matA[2].array[i][j-3] = data.toInt();
                printf("%4d",matA[2].array[i][j - 3]);
            }
            printf("\n");
        }
    } if(sel_kind == "qxc_data") {
        isvalid[3] = true;
        for(int i = 0;i<DataModel->rowCount();i++)
        {
            for(int j = 4;j<4 + sizeone;j++)
            {
                QModelIndex index = DataModel->index(i,j);
                QVariant data = DataModel->data(index,Qt::EditRole);
                matA[3].array[i][j-4] = data.toInt();
                printf("%4d",matA[3].array[i][j - 4]);
            }
            printf("\n");
        }
    }

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sqlcon = new SQLConnector();
    if(this->sqlcon->getDB().isOpenError()== true)
    {
        QMessageBox("数据库打开错误","请检查数据库",QMessageBox::Warning,QMessageBox::Abort,QMessageBox::Retry,QMessageBox::Ignore,this,NULL);
    }
    dw1 = new Drawabler();
    qDebug() <<this->sqlcon->getDB().isOpenError() ;
    DataModel = new QMySQlQueryModel(this,this->sqlcon->getDB());
    initializeModel(DataModel,"pl5_data");
    pos1 = -1;
    colored = 0;
    used = 0;
    memset(isvalid,false,sizeof(isvalid));
    ok = false;
    int k = 1;
    b1 = b2 = b3 = b4 = b5 = b6 = b7 = false;
    conf1 = conf2 = false;
    cmp3 = cmp4 = cmp5 = cmp6 = cmp7 = cmp8 = cmp9 = false;
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            mapper[i][j] = k;
            k++;
        }
    }
    mainth = false;
    timers = false;
    on_off = true;
    //qi->setModel(&DataModel);
    ui->tableView->setModel(DataModel);
    ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.5);");
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setColumnWidth(0,55);
    for(int i = 0;i<DataModel->rowCount();i++)
    {
        ui->tableView->setRowHeight(i,35);
    }
    for(int j = 1;j<DataModel->columnCount();j++)
    {
        ui->tableView->setColumnWidth(j,35);
    }
    ui->progressBar->setRange(0,40);
    sel_bit = 0;
    sel_kind = "pl5_data";
    sel_no = 0;
    sel_num = 0;
    sel_time = 3;
    setstyle(ui->pushButton);
    setstyle(ui->pushButton_2);
    setstyle(ui->pushButton_3);
    setstyle(ui->start);
    setstyle(ui->next);
    setstyle(ui->pushButton_6);
    setstyle(ui->pushButton_7);
    setstyle(ui->pushButton_8);
    setstyle(ui->pushButton_4);
    setstyle(ui->pushButton_5);
    //mtv->setModel(&DataModel2);
    //ui->tableView->viewport()->installEventFilter(this);
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(fuckyou2()));
    QObject::connect(ui->next,SIGNAL(clicked()),this,SLOT(fuckyou7()));
    QObject::connect(ui->cb_bits,SIGNAL(currentIndexChanged(int)),this, SLOT(bitLoadList(int)));
    QObject::connect(ui->cb_nums,SIGNAL(currentIndexChanged(int)),this, SLOT(numLoadList(int)));
    QObject::connect(ui->cb_kinds,SIGNAL(currentIndexChanged(int)),this, SLOT(kindLoadList(int)));
    QObject::connect(ui->cb_no,SIGNAL(currentIndexChanged(int)),this, SLOT(noLoadList(int)));
    QObject::connect(this,SIGNAL(GetStart(int)),this, SLOT(datatransfer(int)));
    QObject::connect(ui->actionClose,SIGNAL(triggered()),this,SLOT(fuckyou8()));
    QObject::connect(ui->actionAbout_Us,SIGNAL(triggered()),this,SLOT(fuckyou1()));
    QObject::connect(ui->cb_times,SIGNAL(currentIndexChanged(int)),this, SLOT(timeLoadList(int)));
    QObject::connect(ui->tableView,SIGNAL(is_datachanged(int)),this, SLOT(datatransfer(int)));
    rt = new RealQThread(this);
    QObject::connect(rt, SIGNAL(finished()), rt, SLOT(deleteLater()));
    QObject::connect(dw1, SIGNAL(givesig(int)), rt, SLOT(giveresult(int)));
    QObject::connect(rt, SIGNAL(resultReady(int)), ui->progressBar, SLOT(setValue(int)));
    QObject::connect(dw1, SIGNAL(givedec(int,int)), ui->progressBar, SLOT(setRange(int,int)));
    QObject::connect(rt, &RealQThread::signalRunOver, &loop, &QEventLoop::quit);
    QObject::connect(ui->start,SIGNAL(clicked(bool)),this, SLOT(startThread()));
    ui->tableView->columncount = DataModel->columnCount();
    ui->tableView->rowcount = DataModel->rowCount();
    QFont font;
    memset(m_cmp,0,sizeof(m_cmp));
    memset(m_num,0,sizeof(m_num));
    memset(m_bit,0,sizeof(m_bit));
    font.setFamily("MS Shell Dlg 2"); // Tahoma 宋体
    font.setBold(true);
    ui->tableView->setFont(font);
    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);
    QString num1 = "select real_id from qxc_data";
    QSqlQuery qsq1;
    qsq1.exec(num1);
    int c = 0;
    while(qsq1.next())
    {
        real_id[c] = qsq1.value(0).toInt();
        ui->cb_no->insertItem(c,QString::number(real_id[c] + 1,10),real_id[c]);
        c++;
    }
    //set_data(DataModel);
    MAXSIZE = 4;
    pos = 0;
    pos2 = 0;
    ui->cb_bits->insertItem(0,"个位",0);
    ui->cb_bits->insertItem(1,"十位",1);
    ui->cb_bits->insertItem(2,"百位",2);
    ui->cb_bits->insertItem(3,"千位",3);
    ui->cb_bits->insertItem(4,"万位",4);
    ui->cb_bits->insertItem(5,"十万位",5);
    ui->cb_bits->insertItem(6,"百万位",6);
    ui->cb_kinds->insertItem(0,"排列5","pl5_data");
    ui->cb_kinds->insertItem(1,"七星彩","qxc_data");
    ui->cb_kinds->insertItem(2,"福彩3D","fc3d_data");
    ui->cb_kinds->insertItem(3,"双色球","ssq_data");
    ui->cb_kinds->insertItem(4,"大乐透","dlt_data");
    ui->cb_times->insertItem(0,"3",3);
    ui->cb_times->insertItem(1,"4",4);
    ui->cb_times->insertItem(2,"5",5);
    ui->cb_times->insertItem(3,"6",6);
    ui->cb_times->insertItem(4,"7",7);
    ui->cb_times->insertItem(5,"8",8);
    ui->cb_times->insertItem(6,"9",9);
    ui->cb_no->setEditable(true);
    ui->cb_nums->insertItem(0,"0",0);
    ui->cb_nums->insertItem(1,"1",1);
    ui->cb_nums->insertItem(2,"2",2);
    ui->cb_nums->insertItem(3,"3",3);
    ui->cb_nums->insertItem(4,"4",4);
    ui->cb_nums->insertItem(5,"5",5);
    ui->cb_nums->insertItem(6,"6",6);
    ui->cb_nums->insertItem(7,"7",7);
    ui->cb_nums->insertItem(8,"8",8);
    ui->cb_nums->insertItem(9,"9",9);
    sql_bit = "";
    sql_cmp = "";
    sql_kind = "";
    sql_num = "";
    is_ok1 = is_ok2 = is_ok3 = is_ok4 = false;
    is_ok5 = is_ok6 = is_ok7 = is_ok8 = false;
    is_ok9 = is_ok10 = is_ok11 = is_ok12 = false;
    is_ok13 = is_ok14 = is_ok15 = is_ok16 = false;
    is_ok17 = is_ok18 = is_ok19 = is_ok20 = false;
    is_ok21 = is_ok22 = is_ok23 = is_ok24 = false;
    is_ok25 = is_ok26 = is_ok27 = is_ok28 = false;
    is_ok29 = is_ok30 = is_ok31 = is_ok32 = false;
    is_ok33 = is_ok34 = is_ok35 = is_ok36 = false;
    is_ok37 = is_ok38 = is_ok39 = is_ok40 = false;
    is_ok41 = is_ok42 = is_ok43 = is_ok44 = false;
    is_ok45 = is_ok46 = is_ok47 = is_ok48 =is_ok49 = is_ok50 = is_ok51 = false;
    p_index = q_index = s_index = 0;
    timestring ="0:00";
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setVisible(false);
    qDebug()<<DataModel->columnCount();
    qDebug()<<matA[0].array[0][0];
}

void MainWindow::Func_view(QString table) {
    QString num1 = "select real_id from "+ table;
    QSqlQuery qsq1;
    qsq1.exec(num1);
    int c = 0;
    ui->cb_no->clear();
    while(qsq1.next())
    {
        real_id[c] = qsq1.value(0).toInt();
        if(c >= 7)
            ui->cb_no->insertItem(c,QString::number(real_id[c] + 1,10),real_id[c]);
        c++;
    }
}

MainWindow::~MainWindow()
{
    if(rt) {
        rt->stop();
    }
    delete rt;
    delete ui;
}

void MainWindow::kindLoadList(int type)
{
    sel_kind = ui->cb_kinds->currentData().toString();
    exchangeMode(ui->cb_kinds->currentIndex());
    ui->tableView->columncount = DataModel->columnCount();
    ui->tableView->rowcount = DataModel->rowCount();
    ui->tableView->repaint();
}

void MainWindow::handleresult(int var) {
    ui->progressBar->setValue(var);
}

void MainWindow::noLoadList(int type)
{
    sel_no = ui->cb_no->currentData().toInt() + 1;
    emit GetStart(sel_no);
}

void MainWindow::numLoadList(int type)
{
    sel_num = ui->cb_nums->currentData().toInt();
}

void MainWindow::timeLoadList(int type)
{
    sel_time = ui->cb_times->currentData().toInt();
}

void MainWindow::bitLoadList(int type)
{
    sel_bit = ui->cb_bits->currentData().toInt();
}


void MainWindow::datatransfer(int start) {
    if(dw1 == NULL) {
        return ;
    }
    int a = 0,b = 19001;
    QSqlQuery qsq;
    qsq.exec("select rowid from "+sel_kind+" limit 0,1;");
    if(qsq.first()) {
        a = qsq.value(0).toInt();
    }
    QSqlQuery qsq1;
    qsq1.exec("select rowid from "+sel_kind+" where real_id="+QString::number(start - 1,10));
    if(qsq1.first()) {
        b = qsq1.value(0).toInt();
    }
    dw1->re_start = start;
    dw1->knt = 0;
    dw1->db = this->sqlcon->getDB();
    dw1->indexs = b - a;
    for(int i = 0;i < 6;i ++) {
        dw1->matA[i] = matA[i];
    }
    dw1->kind = sel_kind;
    if(sel_kind == "pl5_data" || sel_kind == "qxc_data") {
        dw1->MAXSIZE = 4;
    } else if(sel_kind == "ssq_data" || sel_kind == "dlt_data") {
        dw1->MAXSIZE = 5;
    } else if(sel_kind == "fc3d_data") {
        dw1->MAXSIZE = 3;
    }
}

void MainWindow::setstyle(QPushButton *btn) {
    btn->setStyleSheet(
                     //正常状态样式
                     "QPushButton{"
                     "background-color:rgba(100,225,100,30);"//背景色（也可以设置图片）
                     "border-style:outset;"                  //边框样式（inset/outset）
                     "border-width:4px;"                     //边框宽度像素
                     "border-radius:10px;"                   //边框圆角半径像素
                     "border-color:rgba(255,255,255,30);"    //边框颜色
                     "font:15px '华文隶书';"                       //字体，字体大小
                     "color:rgba(255,0,0,100);"                //字体颜色
                     "padding:6px;"                          //填衬
                     "}"
                     //鼠标按下样式
                     "QPushButton:pressed{"
                     "background-color:rgba(100,255,100,200);"
                     "border-color:rgba(255,255,255,30);"
                     "border-style:inset;"
                     "color:rgba(0,0,0,100);"
                     "}"
                     //鼠标悬停样式
                     "QPushButton:hover{"
                     "background-color:rgba(100,255,100,100);"
                     "border-color:rgba(255,255,255,200);"
                     "color:rgba(0,0,0,200);"
                     "}");

}

void MainWindow::FindBestWay(QMySQlQueryModel *model)
{

}

void MainWindow::make_clear() {
    for(int i = 0;i < 4;i ++) {
        for(int j = 0;j < DataModel->rowCount(); j ++) {
            for(int k = 0 ;k < 4;k ++) {
                matA[i].array[j][k] = -1;
            }
        }
    }
}

void MainWindow::fuckyou1()
{
    emit mainthing9();
}

void MainWindow::fuckyou2()
{
    emit mainthing2();
}

void MainWindow::fuckyou3()
{
    emit mainthing3();
}

void MainWindow::fuckyou4()
{
    emit mainthing4();
}

void MainWindow::fuckyou5()
{
    emit mainthing5();
}

void MainWindow::fuckyou6()
{
    emit mainthing6();
}
void MainWindow::fuckyou7()
{
    emit mainthing7();
}

void MainWindow::fuckyou8()
{
    emit mainthing8();
}
void MainWindow::fuckyou9()
{
    emit mainthing9();
}

void MainWindow::fuckyou11()
{
    emit mainthing11();
}

void MainWindow::fuckyou12()
{
    emit mainthing12();
}


void MainWindow::fuckyou14()
{
    emit mainthing14();
}

void MainWindow::fuckyou15()
{
    emit mainthing15();
}

void MainWindow::fuckyou16()
{
    emit mainthing16();
}

void MainWindow::fuckyou17()
{
    emit mainthing17();
}

void MainWindow::fuckyou18()
{
    emit mainthing18();
}

void MainWindow::fuckyou19()
{
    emit mainthing19();
}

void MainWindow::fuckyou20()
{
    emit mainthing20();
}

void MainWindow::mainthing4()
{
    if(b2 == false)
        b2 = true;
}


void MainWindow::mainthing14()
{
    //qDebug()<<cmp3;
    if(cmp3 == false)
        cmp3 = true;
}

void MainWindow::mainthing15()
{
    if(cmp4 == false)
        cmp4 = true;
}

void MainWindow::mainthing16()
{
    if(cmp5 == false)
        cmp5 = true;
}

void MainWindow::mainthing17()
{
    if(cmp6 == false)
        cmp6 = true;
}
void MainWindow::mainthing18()
{
    if(cmp7 == false)
        cmp7 = true;
}
void MainWindow::mainthing19()
{
    if(cmp8 == false)
        cmp8 = true;
}
void MainWindow::mainthing20()
{
    if(cmp9 == false)
        cmp9 = true;
}
//搜寻按钮
void MainWindow::mainthing()
{
    //qDebug()<<DataModel->data(index,Qt::TextAlignmentRole).toInt()<<"Hello ";
    //printf("%d\n",w.qc->rowViewportPosition(1))
}

void MainWindow::startThread() {
    if(is_ok50 == true && !timers) {
        QMessageBox msg(this);
        msg.setText("不能使用当前期数来查找规律！");
        msg.exec();
        is_ok50 = false;
        return ;
    }
     rt = new RealQThread;
        QObject::connect(rt, SIGNAL(finished()), rt, SLOT(deleteLater()));
        QObject::connect(dw1, SIGNAL(givesig(int)), rt, SLOT(giveresult(int)));
        QObject::connect(rt, &RealQThread::signalRunOver, &loop, &QEventLoop::quit);
        QObject::connect(dw1, SIGNAL(givedec(int,int)), ui->progressBar, SLOT(setRange(int,int)));
    QObject::connect(rt, SIGNAL(resultReady(int)), ui->progressBar, SLOT(setValue(int)));
   // rt->db = this->sqlcon->getDB();
    //rt->begin();
    QSqlQuery qsq2;
    qsq2.exec("update "+sel_kind+" set is_new=1 where real_id="+QString::number(sel_no - 1,10));
    emit Datatrans(dw1);
    rt->set_dw(dw1);
    rt->start();
    loop.exec();
    if(timers) {
        return ;
    }
    loop.quit();
    rt->quit();
    QMessageBox msg(this);
    msg.setText(sel_kind+"彩票的"+QString::number(sel_no,10)+"期规律查找完毕~！");
    msg.exec();
}
void MainWindow::fuckyou10()
{
    emit mainthing10();
}

bool MainWindow::isDirExist(QString fullPath)
{
    QDir dir(fullPath);
    if(dir.exists())
    {
      return true;
    }
    else
    {
       bool ok = dir.mkpath(fullPath);//只创建一级子目录，即必须保证上级目录存在
       return ok;
    }
}

int MainWindow::Pointof(QPointF *line,int n)
{
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        if(!line[i].isNull())
        {
            count++;
        }
    }
    return count;
}

void MainWindow::clearrsq(rsq *r) {
    r->len = 0;
}

void MainWindow::selector(int index,int cmp,int mode)
{
    if(conf2 = true)
    {
        used = 0;
        conf2 = false;
    }
    memset(pointer1,0,sizeof(pointer1));
    memset(pointer2,0,sizeof(pointer2));
    QSqlQuery qsq0;
    QSqlQuery qsq1;
    int k = 0;
    qDebug()<<"select id,num,data1,data2,data3,gap,cmp,pos,start from realdata1 where pos="+QString::number(sel_bit,10)+" and cmp="+QString::number(sel_time,10)+" and mode="+QString::number(mode,10)+" and kind="+sel_kind;
    qsq0.exec("select id,num,data1,data2,data3,gap,cmp,pos,start from realdata1 where pos="+QString::number(sel_bit,10)+" and cmp="+QString::number(sel_time,10)+" and mode="+QString::number(mode,10)+" and kind="+sel_kind);
    if(qsq0.first()&&qsq0.size() == 1)
    {
        pointer1[k].id = qsq0.value(0).toInt();
        pointer1[k].num = qsq0.value(1).toInt();
        pointer1[k].one = qsq0.value(2).toInt();
        pointer1[k].two = qsq0.value(3).toInt();
        pointer1[k].three = qsq0.value(4).toInt();
        pointer1[k].gap = qsq0.value(5).toInt();
        pointer1[k].cmp = qsq0.value(6).toInt();
        pointer1[k].pos = qsq0.value(7).toInt();
        pointer1[k].start = qsq0.value(8).toInt();
        k++;
    }
    while(qsq0.next())
    {
        qDebug()<<"1212121212121212121";
        pointer1[k].id = qsq0.value(0).toInt();
        pointer1[k].num = qsq0.value(1).toInt();
        pointer1[k].one = qsq0.value(2).toInt();
        pointer1[k].two = qsq0.value(3).toInt();
        pointer1[k].three = qsq0.value(4).toInt();
        pointer1[k].gap = qsq0.value(5).toInt();
        pointer1[k].cmp = qsq0.value(6).toInt();
        pointer1[k].pos = qsq0.value(7).toInt();
        pointer1[k].start = qsq0.value(8).toInt();
        k++;
    }
    pointer1->len = k;
    k = 0;
    qsq1.exec("select id,num,data1,data2,data3,gap,cmp,pos,start from realdata2 where pos ="+QString::number(sel_bit,10)+" and cmp="+QString::number(sel_time,10)+" and mode="+QString::number(mode)+" and kind="+sel_kind);
    qDebug()<<qsq1.lastError()<<"China No 1";
    if(qsq1.first()&&qsq1.size() == 1)
    {
        pointer2[k].id = qsq1.value(0).toInt();
        pointer2[k].num = qsq1.value(1).toInt();
        pointer2[k].one = qsq1.value(2).toInt();
        pointer2[k].two = qsq1.value(3).toInt();
        pointer2[k].three = qsq1.value(4).toInt();
        pointer2[k].gap = qsq1.value(5).toInt();
        pointer2[k].cmp = qsq1.value(6).toInt();
        pointer2[k].pos = qsq1.value(7).toInt();
        pointer2[k].start = qsq1.value(8).toInt();
        k++;
    }
    while(qsq1.next())
    {
        pointer2[k].id = qsq1.value(0).toInt();
        pointer2[k].num = qsq1.value(1).toInt();
        pointer2[k].one = qsq1.value(2).toInt();
        pointer2[k].two = qsq1.value(3).toInt();
        pointer2[k].three = qsq1.value(4).toInt();
        pointer2[k].gap = qsq1.value(5).toInt();
        pointer2[k].cmp = qsq1.value(6).toInt();
        pointer2[k].pos = qsq1.value(7).toInt();
        pointer2[k].start = qsq1.value(8).toInt();
        k++;
    }
    pointer2->len = k;
    //qDebug() << this->DataModel3.lastError();
}

void MainWindow::savepic(int id,int no,int num,int gap,int start,int cmp,QString kind,int pos)
{
    QString runPath;
    QString hglpName;
    QString hglpPath;
    QString cd = kind;
    QString num2 = QString::number(start, 10);
    QString num3 = QString::number(pos + 1);
    QString num4 = QString::number(num);
    QString num5 = QString::number(start);
    QString num6 = QString::number(pos + 1);
    QString num7 = QString::number(num % 2 + 1);
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy-MM-dd");
    QString num1 = QString::number(no, 10);
    QString as1 = num5+"-"+num4+"-"+num3+"-"+num2+"-"+num1+".png";
    runPath = QCoreApplication::applicationDirPath();       //获取exe路径
    hglpName = "photo";
    hglpPath = QString("%1/%2/").arg(runPath).arg(hglpName);
    QPixmap pix = ui->tableView->grab(ui->tableView->viewport()->rect());
    qDebug()<<ui->tableView->rect().x()<<ui->tableView->rect().size()<<"x";
    QString astr = QString("%1/%2/%3/%4/%5/").arg(hglpPath).arg(cd).arg(num5).arg(num6).arg(num7);
    QString Filename = QString("%6-%7-%8-%9").arg(num3).arg(num4).arg(num1).arg(num2);
    isDirExist(astr);
    pix.save(astr+Filename+".png","PNG");
    QSqlQuery qsq;
    qsq.prepare("insert into imgpath(picname,start,gap,no,cmp,date) values (?,?,?,?,?,?)");
    qsq.addBindValue(Filename);
    qsq.addBindValue(start);
    qsq.addBindValue(gap);
    qsq.addBindValue(id);
    qsq.addBindValue(cmp);
    qsq.addBindValue(current_date);
    qsq.exec();
    qDebug()<<qsq.lastError();
}

int MainWindow::getXfromMap(int data)
{
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<MAXSIZE;j++)
        {
            //qDebug()<<data<<mapper[i][j];
            if(data == mapper[i][j])
                return i;
        }
    }
    return -1;
}

int MainWindow::getYfromMap(int data)
{
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<MAXSIZE;j++)
        {
            //qDebug()<<data<<mapper[i][j];
            if(data == mapper[i][j])
                return j;
        }
    }
    return -1;
}

void MainWindow::timerEvent(QTimerEvent *event)
{

}


void MainWindow::executeSql(QPointF &line,int x,int y,int posadd)//核心函数之一，必须保留
{
    qDebug() <<x<<y<<posadd<<"adddddd";
    if(x==-1||y==-1)
    {
        return ;
    }
    else{
        line.setX(ui->tableView->columnViewportPosition(y+ADDS+posadd)+ui->tableView->columnWidth(y+ADDS+posadd)/2.0);
        line.setY(ui->tableView->rowViewportPosition(x)+ui->tableView->rowHeight(x)/2.0);
    }
}

void MainWindow::actiona()
{
    for(int i = 0;i<DataModel->rowCount();i++)
    {
        ui->tableView->setRowHeight(i,35);
    }
    for(int j = 1;j<DataModel->columnCount();j++)
    {
        ui->tableView->setColumnWidth(j,35);
    }
}

bool MainWindow::selected(QSqlDatabase db,int index,int no,QString kind,int times,int num) //核心函数之一，必须保留
{
    selector(sel_no,sel_time,1);
    memset(ui->tableView->line1,0,sizeof(line1));
    memset(ui->tableView->line2,0,sizeof(line2));
    memset(line1,0,sizeof(line1));
    memset(line2,0,sizeof(line2));
    if(!db.isOpen())
           return false;
    QString pos;
    QString start;
    QString id;
    QSqlQuery qsq1;
    QSqlQuery qsq2;
    QSqlQuery qsq3;
    QString end;
    qDebug()<<sel_kind<<"123456789";
    int position = 0;
    pos = QString::number(sel_bit,10);
    QString time = QString::number(sel_time,10);
    QString nums = QString::number(sel_num,10);
    QString table = kind;
    QString pos1 = QString::number(sel_bit,10);
    QSqlQuery qsq22;
    int started = sel_no;
    db.transaction();
    qsq22.exec("select rowid from "+sel_kind+" where real_id="+QString::number(sel_no - 1,10));
    QSqlQuery qsq33;
    if(qsq22.first()) {
        started = qsq22.value(0).toInt() + 1;
    }
    qsq33.exec("select rowid,data1,data2,data3,gap,cmp,pos from realdata1 where pos="+pos+"  and cmp="+time+" and num="+nums + " and kind='"+sel_kind+"'");
    if(qsq33.first()) {
        start = QString::number(started,10);
        end = QString::number(started - ( 4 + qsq33.value(4).toInt())*5,10);
        id = QString::number(qsq33.value(0).toInt(),10);
    }
    qDebug()<<start;
    position = used;
    qDebug()<<pos<<"used================================="<<pointer1[used].id;
    QString as1 = "select data1,data2,data3,gap,cmp,pos,mode,num,kind,start,id from realdata1 where pos="+pos+"  and cmp="+time+" and gap = 0 and num="+nums  + " and kind='"+sel_kind+"'";
    QString as2 = "select data1,data2,data3,gap,cmp,pos,mode,num,kind,start,id from realdata2 where pos="+pos+"  and cmp="+time+" and gap = 0 and num="+nums+ " and kind='"+sel_kind+"'";
    db.commit();
    QSqlQuery qsq7;
    qDebug()<<as1<<as2;
    QString create_table = "DROP TABLE `MyTable`;";
    QString createtable;
    QString querry_table;
    createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL,`four` INT NULL,`five` INT NULL,`six` INT NULL,`seven` INT NULL);";
    querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`,`four`,`five`,`six`,`seven`) SELECT `real_id`,`one`,`two`,`three`,`four`,`five`,`six`,`seven` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    QString tail_table[7];
    for(int i  = 0;i < 7;i ++) {
        tail_table[i] = "INSERT INTO `MyTable`(`real_id`,`"+string_table[i]+"`)VALUES("+QString::number(sel_no,10)+","+QString::number(sel_num,10)+");";
    }
    QSqlQuery qsqt;
    QSqlQuery qsq4;
    QSqlQuery qsq41;
    qsq4.exec("DELETE FROM MyTable;");
    qsq41.exec("DELETE FROM sqlite_sequence WHERE name = 'mytable';");
    qsq7.exec(createtable);
    qsq3.exec(querry_table);
    qsqt.exec(tail_table[sel_bit]);
    qDebug()<<real_id[0]<<querry_table<<endl;
    changeModel(DataModel,sel_kind);
    ui->tableView->setModel(DataModel);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setColumnWidth(0,55);
    for(int i = 0;i<DataModel->rowCount();i++)
    {
        ui->tableView->setRowHeight(i,35);
    }
    for(int j = 1;j<DataModel->columnCount();j++)
    {
        ui->tableView->setColumnWidth(j,35);
    }
  //  qDebug()<<colored<<"csacsacasa";
  //  qDebug()<<as1;
    qsq1.exec(as1);
    int ccmp1,ccmp2,cid;
    int cnum,cpos,cstart,cgap;
    QString ckind;
    qsq1.first();
    for(int i = 0;i<qsq1.value(4).toInt();i++)
    {
        if(getXfromMap(qsq1.value(0).toInt())!=-1&&getYfromMap(qsq1.value(0).toInt())!=-1)
         executeSql(line1[i][0],getXfromMap(qsq1.value(0).toInt()) + DataModel->rowCount() - (i)*(qsq1.value(3).toInt() + 4) - 4,getYfromMap(qsq1.value(0).toInt()) , qsq1.value(6).toInt());
        if(getXfromMap(qsq1.value(1).toInt())!=-1&&getYfromMap(qsq1.value(1).toInt())!=-1)
            executeSql(line1[i][1],getXfromMap(qsq1.value(1).toInt()) + DataModel->rowCount() - (i)*(qsq1.value(3).toInt() + 4) - 4,getYfromMap(qsq1.value(1).toInt()) , qsq1.value(6).toInt());
        if(getXfromMap(qsq1.value(2).toInt())!=-1&&getYfromMap(qsq1.value(2).toInt())!=-1)
            executeSql(line1[i][2],getXfromMap(qsq1.value(2).toInt()) + DataModel->rowCount() - (i)*(qsq1.value(3).toInt() + 4) - 4,getYfromMap(qsq1.value(2).toInt()) , qsq1.value(6).toInt());
    }
    cpos = qsq1.value(5).toInt();
    cgap = qsq1.value(3).toInt();
    ccmp1 = qsq1.value(4).toInt();
    cnum = qsq1.value(7).toInt();
    ckind = qsq1.value(8).toString();
    cstart = qsq1.value(9).toInt();
    cid = qsq1.value(10).toInt();
    qsq2.exec(as2);
    qsq2.first();
    qDebug()<<as2<<as1<<qsq2.lastError();
    for(int i = 0;i<qsq2.value(4).toInt();i++)
    {
        qDebug()<<qsq2.lastError()<<"csacjabuicaqavbcuyavbuvauh";
        if(getXfromMap(qsq2.value(0).toInt())!=-1&&getYfromMap(qsq2.value(0).toInt())!=-1)
            executeSql(line2[i][0],getXfromMap(qsq2.value(0).toInt()) + DataModel->rowCount() - (i)*(qsq2.value(3).toInt() + 4) - 4,getYfromMap(qsq2.value(0).toInt()) , qsq2.value(6).toInt());
        if(getXfromMap(qsq2.value(1).toInt())!=-1&&getYfromMap(qsq2.value(1).toInt())!=-1)
            executeSql(line2[i][1],getXfromMap(qsq2.value(1).toInt()) + DataModel->rowCount() - (i)*(qsq2.value(3).toInt() + 4) - 4,getYfromMap(qsq2.value(1).toInt()) , qsq2.value(6).toInt());
        if(getXfromMap(qsq2.value(2).toInt())!=-1&&getYfromMap(qsq2.value(2).toInt())!=-1)
            executeSql(line2[i][2],getXfromMap(qsq2.value(2).toInt()) + DataModel->rowCount() - (i)*(qsq2.value(3).toInt() + 4) - 4,getYfromMap(qsq2.value(2).toInt()) , qsq2.value(6).toInt());
    }
    ccmp2 = qsq2.value(5).toInt();
    used = used+1;
    for(int i = 0;i<ccmp1;i++)
    {
        for(int j = 0;j<3;j++)
        {
            qDebug()<<line1[i][j]<<"endl";
            ui->tableView->line1[i][j] = line1[i][j];
            ui->tableView->line2[i][j] = line2[i][j];
        }
    }
    ui->tableView->columncount = DataModel->columnCount();
    ui->tableView->rowcount = DataModel->rowCount();
    ui->tableView->repaint();
    savepic(cid,q_index,cnum,cgap,cstart,ccmp1,ckind,cpos);
    return true;
}


void MainWindow::mainthing2()
{
    memset(line1,0,sizeof(line1));
    memset(line2,0,sizeof(line2));
    memset(ui->tableView->line1,0,sizeof(ui->tableView->line1));
    memset(ui->tableView->line2,0,sizeof(ui->tableView->line2));
    for(int i = 0;i<6;i++)
    {
        for(int j = 0;j<3;j++)
        {
            qDebug()<<line1[i][j]<<"endl";
            ui->tableView->line1[i][j] = line1[i][j];
            ui->tableView->line2[i][j] = line2[i][j];
        }
    }
    selected(this->sqlcon->getDB(),sel_bit,sel_no,sel_kind,sel_time,sel_num);
    p_index ++;
}
//工程问题：1.画图部分不太好 2.查询最佳方案部分没写 3 人机交互性不强，应该添加一个按钮控制最高的gap数
//今天解决的问题：最佳方案找出来了。即算法已经合格。

//bool MainWindow::eventFilter(QObject *target, QEvent *event)
//{
//    if(target == ui->tableView->viewport()&&event->type() == QEvent::Paint)
//    {
//        QColor color[] = {Qt::red,Qt::green,Qt::blue,Qt::yellow};
//        QColor color1[] = {Qt::yellow,Qt::blue,Qt::green,Qt::red};
//        QPainter painter(ui->tableView->viewport());
//        for(int j = 0;j<4;j++)
//         {

//                magicTime(painter,line1[j],color[ (colored + 4 ) % 4 ]);
//                magicTime(painter,line2[j],color1[ (colored + 4 ) % 4 ]);
//         }
//    }
//    return QWidget::eventFilter(target,event);

//}

void MainWindow::mainthing3()
{
    if(b1 == false)
        b1 = true;
}

void MainWindow::mainthing5()
{
    if(b3 == false)
        b3 = true;
}

void MainWindow::mainthing6()
{
    if(b4 == false)
    b4 = true;
}

void MainWindow::mainthing7()
{
   QSqlQuery qsq;
   QString as;
   as = "insert into updatestatus(status) values('TRUE')";
   qsq.exec(as);
}

void MainWindow::mainthing8()
{
    this->destroy();
}

void MainWindow::mainthing9()
{
    QMessageBox msg;
    msg.setText("彩票中中奖&规律查找程序&Copyright2019 David Peng\nVisit http://www.david-peng.cn");
    msg.exec();
}

void MainWindow::mainthing10()
{
    if(b5 == false)
    b5 = true;
}

void MainWindow::mainthing11()
{
    if(b6 == false)
    b6 = true;
}

void MainWindow::mainthing12()
{
    if(b7 == false)
    b7 = true;
}

//void MainWindow::magicTime(QPainter &painter,QPointF *line,QColor color)
//{
//    if(line[0].rx()==0.0&&line[0].ry()==0.0)
//        return ;
//    if(ui->tableView->indexAt(line[0].toPoint()).row()==-1||ui->tableView->indexAt(line[0].toPoint()).column()==-1)
//        return ;
//    // 创建QPainter一个对象
//    QPen pen;
//    pen.setWidth(2);
//    pen.setColor(color);
//    painter.setPen(pen);
//    QPainterPath qpp;
//    qpp.moveTo(line[0]);
//    //qDebug()<<pos<<ui->tableView->indexAt(line[pos].toPoint());
//    //qDebug()<<pos<<line[pos].rx()<<line[pos].ry();
//    for(int i = 0;i<3;i++)
//    {
//        if(line[i].rx()==0.0&&line[i].ry()==0.0)
//            continue;
//        if(ui->tableView->indexAt(line[i].toPoint()).row()==-1||ui->tableView->indexAt(line[i].toPoint()).column()==-1)
//            continue;
//        qpp.lineTo(line[i]);
//        painter.drawEllipse(line[i],10,10);
//        qDebug()<<ui->tableView->indexAt(line[i].toPoint()).row()<<ui->tableView->indexAt(line[i].toPoint()).column()<<DataModel.index(ui->tableView->indexAt(line[i].toPoint()).row(),ui->tableView->indexAt(line[i].toPoint()).column()).data();
//    }
//    painter.drawPath(qpp);
//}
void MainWindow::clear_blank(QString &str) {
    str.replace(" ","/t");
}

void MainWindow::disp(QString kind) {
    ft = new FileThread;
    QObject::connect(ft, &FileThread::signalRunOver, &loop2, &QEventLoop::quit);
    ft->set_file(&file);
    ft->set_kind(kind);
    ft->set_no(QString::number(sel_no,10));
    ft->start();
    loop2.exec();
    for(int i = 0;i < 5;i ++) {
        if(kind == list_table[i]) {
            exchangeMode(i);
            break;
        }
    }
    ft->quit();
    ui->tableView->columncount = DataModel->columnCount();
    ui->tableView->rowcount = DataModel->rowCount();
    ui->tableView->repaint();
    loop2.quit();
    if(pos == table_data1->len && !timers) {
        QMessageBox msg(this);
        msg.setText("导入完毕！");
        msg.exec();
    }
}

void MainWindow::on_next_clicked()
{
    emit disp(sel_kind);
}

void MainWindow::vieweraction() {
    if(pos == table_data1->len && !timers) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "提示", "已经查找到最后一个规律了，是否重头开始查找规律？", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            pos = 0;
        }
        else
        {
            pos = -1;
            return ;
        }
    }else if(pos == table_data1->len && timers) {
        on_off = false;
    }
    QSqlQuery qsq7;
    QSqlQuery qsq3;
    QSqlQuery qsq22;
    qsq22.exec("select rowid from "+sel_kind+" where real_id="+QString::number(table_data1[pos].start - 1,10));
    QString start,end;
    int started = 0;
    qDebug()<<"select rowid from "+sel_kind+" where real_id="+QString::number(table_data1[pos].start - 1,10);
    if(qsq22.first()) {
        started = qsq22.value(0).toInt() + 1;
    }
    start = QString::number(started,10);
    end = QString::number(started - ( 4 + table_data1[pos].gap)*5,10);
    QString create_table = "DROP TABLE `MyTable`;";
    QString createtable;
    QString querry_table;
    QString tail_table[7];
    createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL,`four` INT NULL,`five` INT NULL,`six` INT NULL,`seven` INT NULL);";
    querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`,`four`,`five`,`six`,`seven`) SELECT `real_id`,`one`,`two`,`three`,`four`,`five`,`six`,`seven` FROM '"+sel_kind+"' WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    QSqlQuery qsqt;
    QSqlQuery qsq4;
    QSqlQuery qsq41;
    qsq4.exec("DELETE FROM MyTable;");
    qsq41.exec("DELETE FROM sqlite_sequence WHERE name = 'mytable';");
    qsq7.exec(createtable);
    qsq3.exec(querry_table);
    for(int i  = 0;i < 7;i ++) {
        tail_table[i] = "INSERT INTO `Mytable`(`real_id`,`" + string_table[i]+"`)VALUES("+QString::number(table_data1[pos].start,10)+","+QString::number(table_data1[pos].num,10)+");";
    }
    qsqt.exec(tail_table[table_data1[pos].pos]);
    qDebug()<<real_id[0]<<querry_table<<endl;
    changeModel(DataModel,sel_kind);
    ui->tableView->setModel(DataModel);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setColumnWidth(0,55);
    for(int i = 0;i<DataModel->rowCount();i++)
    {
        ui->tableView->setRowHeight(i,35);
    }
    for(int j = 1;j<DataModel->columnCount();j++)
    {
        ui->tableView->setColumnWidth(j,35);
    }
    for(int j = 0;j < table_data1[pos].cmp; j ++) {
        if(getXfromMap(table_data1[pos].one)!=-1&&getYfromMap(table_data1[pos].one)!=-1)
         executeSql(line1[j][0],getXfromMap(table_data1[pos].one) + DataModel->rowCount() - (j)*(table_data1[pos].gap + 4) - 4,getYfromMap(table_data1[pos].one) , table_data1[pos].mode);
        if(getXfromMap(table_data1[pos].two)!=-1&&getYfromMap(table_data1[pos].two)!=-1)
            executeSql(line1[j][1],getXfromMap(table_data1[pos].two) + DataModel->rowCount() - (j)*(table_data1[pos].gap + 4) - 4,getYfromMap(table_data1[pos].two) , table_data1[pos].mode);
        if(getXfromMap(table_data1[pos].three)!=-1&&getYfromMap(table_data1[pos].three)!=-1)
            executeSql(line1[j][2],getXfromMap(table_data1[pos].three) + DataModel->rowCount() - (j)*(table_data1[pos].gap + 4) - 4,getYfromMap(table_data1[pos].three) , table_data1[pos].mode);
    }
    for(int j = 0;j < table_data2[pos].cmp; j ++) {
        if(getXfromMap(table_data2[pos].one)!=-1&&getYfromMap(table_data2[pos].one)!=-1)
         executeSql(line2[j][0],getXfromMap(table_data2[pos].one) + DataModel->rowCount() - (j)*(table_data2[pos].gap + 4) - 4,getYfromMap(table_data2[pos].one) , table_data2[pos].mode);
        if(getXfromMap(table_data2[pos].two)!=-1&&getYfromMap(table_data2[pos].two)!=-1)
            executeSql(line2[j][1],getXfromMap(table_data2[pos].two) + DataModel->rowCount() - (j)*(table_data2[pos].gap + 4) - 4,getYfromMap(table_data2[pos].two) ,table_data2[pos].mode);
        if(getXfromMap(table_data2[pos].three)!=-1&&getYfromMap(table_data2[pos].three)!=-1)
            executeSql(line2[j][2],getXfromMap(table_data2[pos].three) + DataModel->rowCount() - (j)*(table_data2[pos].gap + 4) - 4,getYfromMap(table_data2[pos].three) , table_data2[pos].mode);
    }
    for(int i = 0;i<table_data1[pos].cmp;i++)
    {
        for(int j = 0;j<3;j++)
        {
            qDebug()<<line1[i][j]<<"endl";
            ui->tableView->line1[i][j] = line1[i][j];
            ui->tableView->line2[i][j] = line2[i][j];
        }
    }
    ui->tableView->columncount = DataModel->columnCount();
    ui->tableView->rowcount = DataModel->rowCount();
    ui->tableView->repaint();
    savepic(table_data1[pos].id,pos,table_data1[pos].num,table_data1[pos].gap,table_data1[pos].start,table_data1[pos].cmp,table_data1[pos].kind,table_data1[pos].pos);
}

void MainWindow::viewer() {
    int i = 0;
    QSqlQuery qsq1;
    qsq1.exec("select id,num,data1,data2,data3,gap,cmp,pos,start,mode,kind from realdata1 where kind='"+sel_kind+"' and gap = 0 limit 0,600");
    qDebug()<<qsq1.lastError()<<"select id,num,data1,data2,data3,gap,cmp,pos,start,mode,kind from realdata1 where kind='"+sel_kind+"' and gap =0 limit 0,600";
    while(qsq1.next()) {
        qDebug()<<sel_kind<<"++++++++++++++++++";
        table_data1[i].id = qsq1.value(0).toInt();
        table_data1[i].num = qsq1.value(1).toInt();
        table_data1[i].one = qsq1.value(2).toInt();
        table_data1[i].two = qsq1.value(3).toInt();
        table_data1[i].three = qsq1.value(4).toInt();
        table_data1[i].gap = qsq1.value(5).toInt();
        table_data1[i].cmp = qsq1.value(6).toInt();
        table_data1[i].pos = qsq1.value(7).toInt();
        table_data1[i].start = qsq1.value(8).toInt();
        table_data1[i].mode = qsq1.value(9).toInt();
        table_data1[i].kind = qsq1.value(10).toString();
        i ++;
    }
    table_data1->len = i;
    i = 0;
    QSqlQuery qsq2;
    qsq2.exec("select id,num,data1,data2,data3,gap,cmp,pos,start,mode,kind from realdata2 where kind='"+sel_kind+"' and gap = 0 limit 0,600");
    qDebug()<<qsq2.lastError();
    while(qsq2.next()) {
        table_data2[i].id = qsq2.value(0).toInt();
        table_data2[i].num = qsq2.value(1).toInt();
        table_data2[i].one = qsq2.value(2).toInt();
        table_data2[i].two = qsq2.value(3).toInt();
        table_data2[i].three = qsq2.value(4).toInt();
        table_data2[i].gap = qsq2.value(5).toInt();
        table_data2[i].cmp = qsq2.value(6).toInt();
        table_data2[i].pos = qsq2.value(7).toInt();
        table_data2[i].start = qsq2.value(8).toInt();
        table_data2[i].mode = qsq2.value(9).toInt();
        table_data2[i].kind = qsq2.value(10).toString();
        i ++;
    }
    table_data2->len = i;
}


void MainWindow::on_pushButton_2_clicked()
{
    memset(line1,0,sizeof(line1));
    memset(line2,0,sizeof(line2));
    memset(ui->tableView->line1,0,sizeof(ui->tableView->line1));
    memset(ui->tableView->line2,0,sizeof(ui->tableView->line2));
    for(int i = 0;i<6;i++)
    {
        for(int j = 0;j<3;j++)
        {
            qDebug()<<line1[i][j]<<"endl";
            ui->tableView->line1[i][j] = line1[i][j];
            ui->tableView->line2[i][j] = line2[i][j];
        }
    }
    emit viewer();
    emit vieweraction();
    pos ++;

}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery qsq4;
    QSqlQuery qsq41;
    qsq4.exec("DELETE FROM `"+sel_kind+"`;");
    qsq41.exec("DELETE FROM `sqlite_sequence` WHERE name=`"+sel_kind+"`;");
    if(timers)
        return ;
    QMessageBox msg(this);
    msg.setText("本类别数据已经清空干净~！");
    msg.exec();
}

void MainWindow::on_qxc_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        sql_kind = "and kind=`qxc_data`";
        is_ok1 = true;
        m_kind = "qxc_data";
    }
    else {
        is_ok1 = false;
    }
}

void MainWindow::on_pl3_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        sql_kind = "and kind=`pl3_data` ";
        is_ok2 = true;
        m_kind = "pl3_data";
    }
    else {
        is_ok2 = false;
    }
}

void MainWindow::on_pl5_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        sql_kind = "and kind=`pl5_data` ";
        is_ok3 = true;
        m_kind = "pl5_data";
    }
    else {
        is_ok3 = false;
    }
}

void MainWindow::on_fc3d_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        sql_kind = "and kind=`fc3d_data` ";
        m_kind = "fc3d_data";
        is_ok4 = true;
    }
    else {
        is_ok4 = false;
    }
}

void MainWindow::on_ThreeTime_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->ThreeTime->setDisabled(true);
        sql_cmp.append("3, ");
        m_cmp[3] = 1;
        is_ok5 = true;
    }
    else {
        is_ok5 = false;
    }
}

void MainWindow::on_FourTime_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->FourTime->setDisabled(true);
        sql_cmp.append("4, ");
        m_cmp[4] = 1;
        is_ok6 = true;
    }
    else {
        is_ok6 = false;
    }
}

void MainWindow::on_FiveTime_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->FiveTime->setDisabled(true);
        sql_cmp.append("5, ");
        m_cmp[5] = 1;
        is_ok7 = true;
    }
    else {
        is_ok7 = false;
    }
}

void MainWindow::on_SixMoreTime_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->SixMoreTime->setDisabled(true);
        sql_cmp.append("6, 7, 8, 9, 10, ");
        m_cmp[6] = m_cmp[7] = m_cmp[8] = m_cmp[9] = m_cmp[10] = 1;
        is_ok8 = true;
    }
    else {
        is_ok8 = false;
    }
}

void MainWindow::on_Bit_One_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Bit_One->setDisabled(true);
        sql_bit.append("0, ");
        m_bit[1] = 1;
        is_ok9 = true;
    }
    else {
        is_ok9 = false;
    }
}

void MainWindow::on_Bit_Two_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Bit_Two->setDisabled(true);
        sql_bit.append("1, ");
        m_bit[2] = 1;
        is_ok10 = true;
    }
    else {
        is_ok10 = false;
    }
}

void MainWindow::on_Bit_Three_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Bit_Three->setDisabled(true);
        sql_bit.append("2, ");
        m_bit[3] = 1;
        is_ok11 = true;
    }
    else {
        is_ok11 = false;
    }
}

void MainWindow::on_Bit_Four_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Bit_Four->setDisabled(true);
        sql_bit.append("3, ");
        m_bit[4] = 1;
        is_ok12 = true;
    }
    else {
        is_ok12 = false;
    }
}

void MainWindow::on_Bit_Five_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Bit_Five->setDisabled(true);
        sql_bit.append("4, ");
        m_bit[5] = 1;
        is_ok13 = true;
    }
    else {
        is_ok13 = false;
    }
}

void MainWindow::on_Num_Six_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Num_Six->setDisabled(true);
        sql_num.append("6, ");
        m_num[6] = 1;
        is_ok14 = true;
    }
    else {
        is_ok14 = false;
    }
}

void MainWindow::on_Num_Seven_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Num_Seven->setDisabled(true);
        sql_num.append("7, ");
        m_num[7] = 1;
        is_ok15 = true;
    }
    else {
        is_ok15 = false;
    }
}

void MainWindow::on_Num_Eight_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Num_Eight->setDisabled(true);
        sql_num.append("8, ");
        m_num[8] = 1;
        is_ok16 = true;
    }
    else {
        is_ok16 = false;
    }
}

void MainWindow::on_Num_Nine_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Num_Nine->setDisabled(true);
        sql_num.append("9, ");
        m_num[9] = 1;
        is_ok17 = true;
    }
    else {
        is_ok17 = false;
    }
}

void MainWindow::analyze() {
    if(pos2 == search_data1->len) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "提示", "已经查找到最后一个规律了，是否重头开始查找规律？", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            pos2 = 0;
        }
        else
        {
            pos2 = -1;
            return ;
        }
    }
    QSqlQuery qsq7;
    QSqlQuery qsq3;
    QSqlQuery qsq22;
    qsq22.exec("select rowid from "+sel_kind+" where real_id="+QString::number(search_data1[pos2].start - 1,10));
    qDebug()<<search_data1[pos2].kind<<"select rowid from "+sel_kind+" where real_id="+QString::number(search_data1[pos2].start - 1,10);
    QString start,end;
    int started = 0;
    if(qsq22.first()) {
        started = qsq22.value(0).toInt() + 1;
    }
    start = QString::number(started);
    end = QString::number(started - ( 4 + search_data1[pos2].gap)*5,10);
    QString create_search = "DROP table `Mytable`;";
    QString createsearch;
    QString querry_search;
    createsearch = "CREATE table `Mytable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL,`four` INT NULL,`five` INT NULL,`six` INT NULL,`seven` INT NULL);";
    querry_search = "INSERT INTO `Mytable` (`real_id`,`one`,`two`,`three`,`four`,`five`,`six`,`seven`) SELECT `real_id`,`one`,`two`,`three`,`four`,`five`,`six`,`seven` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    QString tail_search[7];
    for(int i  = 0;i < 7;i ++) {
        tail_search[i] = "INSERT INTO `Mytable`(`real_id`,`"+string_table[i]+"`)VALUES("+QString::number(search_data1[pos2].start,10)+","+QString::number(search_data1[pos2].num,10)+");";
    }
    QSqlQuery qsqt;
    QSqlQuery qsq4;
    QSqlQuery qsq41;
    qsq4.exec("DELETE FROM Mytable");
    qsq41.exec("DELETE FROM sqlite_sequence WHERE name = 'mytable'");
    qsq7.exec(createsearch);
    qsq3.exec(querry_search);
    qsqt.exec(tail_search[search_data1[pos2].pos]);
    qDebug()<<real_id[0]<<querry_search<<endl;
    changeModel(DataModel,search_data1[pos2].kind);
    ui->tableView->setModel(DataModel);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setColumnWidth(0,55);
    for(int i = 0;i<DataModel->rowCount();i++)
    {
        ui->tableView->setRowHeight(i,35);
    }
    for(int j = 1;j<DataModel->columnCount();j++)
    {
        ui->tableView->setColumnWidth(j,35);
    }
    for(int j = 0;j < search_data1[pos2].cmp; j ++) {
        if(getXfromMap(search_data1[pos2].one)!=-1&&getYfromMap(search_data1[pos2].one)!=-1)
            executeSql(line1[j][0],getXfromMap(search_data1[pos2].one) + DataModel->rowCount() - (j)*(search_data1[pos2].gap + 4) - 4,getYfromMap(search_data1[pos2].one),search_data1[pos2].mode);
        if(getXfromMap(search_data1[pos2].two)!=-1&&getYfromMap(search_data1[pos2].two)!=-1)
            executeSql(line1[j][1],getXfromMap(search_data1[pos2].two) + DataModel->rowCount() - (j)*(search_data1[pos2].gap + 4) - 4,getYfromMap(search_data1[pos2].two) ,search_data1[pos2].mode);
        if(getXfromMap(search_data1[pos2].three)!=-1&&getYfromMap(search_data1[pos2].three)!=-1)
            executeSql(line1[j][2],getXfromMap(search_data1[pos2].three) + DataModel->rowCount() - (j)*(search_data1[pos2].gap + 4) - 4,getYfromMap(search_data1[pos2].three),search_data1[pos2].mode);
    }
    for(int j = 0;j < search_data2[pos2].cmp; j ++) {
        if(getXfromMap(search_data2[pos2].one)!=-1&&getYfromMap(search_data2[pos2].one)!=-1)
            executeSql(line2[j][0],getXfromMap(search_data2[pos2].one) + DataModel->rowCount() - (j)*(search_data2[pos2].gap + 4) - 4,getYfromMap(search_data2[pos2].one),search_data2[pos2].mode);
        if(getXfromMap(search_data2[pos2].two)!=-1&&getYfromMap(search_data2[pos2].two)!=-1)
            executeSql(line2[j][1],getXfromMap(search_data2[pos2].two) + DataModel->rowCount() - (j)*(search_data2[pos2].gap + 4) - 4,getYfromMap(search_data2[pos2].two),search_data2[pos2].mode);
        if(getXfromMap(search_data2[pos2].three)!=-1&&getYfromMap(search_data2[pos2].three)!=-1)
            executeSql(line2[j][2],getXfromMap(search_data2[pos2].three) + DataModel->rowCount() - (j)*(search_data2[pos2].gap + 4) - 4,getYfromMap(search_data2[pos2].three),search_data2[pos2].mode);
    }
    for(int i = 0;i<search_data1[pos2].cmp;i++)
    {
        for(int j = 0;j<3;j++)
        {
            qDebug()<<line1[i][j]<<"endl";
            ui->tableView->line1[i][j] = line1[i][j];
            ui->tableView->line2[i][j] = line2[i][j];
        }
    }
    ui->tableView->columncount = DataModel->columnCount();
    ui->tableView->rowcount = DataModel->rowCount();
    ui->tableView->repaint();
    savepic(search_data1[pos2].id,pos2,search_data1[pos2].num,search_data1[pos2].gap,search_data1[pos2].start,search_data1[pos2].cmp,search_data1[pos2].kind,search_data1[pos2].pos);
}

void MainWindow::analyze_prep() {
    QString sql_main1;
    QString sql_main2;
    for(int i  = sql_bit.length() - 1;i >= 0;i --) {
        if(sql_bit[i] == ',') {
            sql_bit[i] = ' ';
            break;
        }
    }
    for(int i  = sql_num.length() - 1;i >= 0;i --) {
        if(sql_num[i] == ',') {
            sql_num[i] = ' ';
            break;
        }
    }
    for(int i  = sql_cmp.length() - 1;i >= 0;i --) {
        if(sql_cmp[i] == ',') {
            sql_cmp[i] = ' ';
            break;
        }
    }
    sql_main1 = "select id,num,data1,data2,data3,gap,cmp,pos,start,mode,kind from realdata1 where start=" + ui->seq->text() + " and gap = 0 ";
    sql_main2 = "select id,num,data1,data2,data3,gap,cmp,pos,start,mode,kind from realdata2 where start="+ ui->seq->text()+ " and gap = 0 ";
    sql_main1.append(sql_kind  + "and cmp IN("+sql_cmp+")"+"and pos IN("+sql_bit+")" +"and num IN("+sql_num+")");
    sql_main2.append(sql_kind  + "and cmp IN("+sql_cmp+")"+"and pos IN("+sql_bit+")" +"and num IN("+sql_num+")");
    int i = 0;
    QSqlQuery qsq1;
    qsq1.exec(sql_main1);
    qDebug()<<sql_main2<<" "<<sql_main1;
    while(qsq1.next()) {
        search_data1[i].id = qsq1.value(0).toInt();
        search_data1[i].num = qsq1.value(1).toInt();
        search_data1[i].one = qsq1.value(2).toInt();
        search_data1[i].two = qsq1.value(3).toInt();
        search_data1[i].three = qsq1.value(4).toInt();
        search_data1[i].gap = qsq1.value(5).toInt();
        search_data1[i].cmp = qsq1.value(6).toInt();
        search_data1[i].pos = qsq1.value(7).toInt();
        search_data1[i].start = qsq1.value(8).toInt();
        search_data1[i].mode = qsq1.value(9).toInt();
        search_data1[i].kind = qsq1.value(10).toString();
        i ++;
    }
    search_data1->len = i;
    i = 0;
    QSqlQuery qsq2;
    qsq2.exec(sql_main2);
    while(qsq2.next()) {
        search_data2[i].id = qsq2.value(0).toInt();
        search_data2[i].num = qsq2.value(1).toInt();
        search_data2[i].one = qsq2.value(2).toInt();
        search_data2[i].two = qsq2.value(3).toInt();
        search_data2[i].three = qsq2.value(4).toInt();
        search_data2[i].gap = qsq2.value(5).toInt();
        search_data2[i].cmp = qsq2.value(6).toInt();
        search_data2[i].pos = qsq2.value(7).toInt();
        search_data2[i].start = qsq2.value(8).toInt();
        search_data2[i].mode = qsq2.value(9).toInt();
        search_data2[i].kind = qsq2.value(10).toString();
        i ++;
    }
    search_data2->len = i;
}

void MainWindow::on_pushButton_4_clicked()
{
    memset(line1,0,sizeof(line1));
    memset(line2,0,sizeof(line2));
    for(int i = 0;i<6;i++)
    {
        for(int j = 0;j<3;j++)
        {
            qDebug()<<line1[i][j]<<"endl";
            ui->tableView->line1[i][j] = line1[i][j];
            ui->tableView->line2[i][j] = line2[i][j];
        }
    }
    if(sql_bit == ""  && sql_kind == "" && sql_cmp == "" && sql_kind == "") {
        QMessageBox msg(this);
        msg.setText("你没有勾选任何选项！");
        msg.exec();
        return ;
    }
    pos2 ++;
}

void MainWindow::on_Num_Zero_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Num_Zero->setDisabled(true);
        sql_num.append("0, ");
        m_num[0] = 1;
        is_ok18 = true;
    }
    else {
        is_ok18 = false;
    }
}

void MainWindow::on_Num_One_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Num_One->setDisabled(true);
        sql_num.append("1, ");
        m_num[1] = 1;
        is_ok19 = true;
    }
    else {
        is_ok19 = false;
    }
}

void MainWindow::on_Num_Two_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Num_Two->setDisabled(true);
        sql_num.append("2, ");
        m_num[2] = 1;
        is_ok20 = true;
    }
    else {
        is_ok20 = false;
    }
}

void MainWindow::on_Num_Three_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Num_Three->setDisabled(true);
        sql_num.append("3, ");
        m_num[3]  = 1;
        is_ok21 = true;
    }
    else {
        is_ok21 = false;
    }
}

void MainWindow::on_Num_Four_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Num_Four->setDisabled(true);
        sql_num.append("4, ");
        m_num[4]  = 1;
        is_ok22 = true;
    }
    else {
        is_ok22 = false;
    }
}

void MainWindow::on_Num_Five_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Num_Five->setDisabled(true);
        sql_num.append("5, ");
        m_num[5] = 1;
        is_ok23 = true;
    }
    else {
        is_ok23 = false;
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(ui->tableView->line1[0][0].isNull() == true && !timers) {
        QMessageBox msg(this);
        msg.setText("还没有查找到规律呢！");
        msg.exec();
        return ;
    }
    memset(ui->tableView->line1,0,sizeof(ui->tableView->line1));
    memset(ui->tableView->line2,0,sizeof(ui->tableView->line2));
    ui->tableView->columncount = DataModel->columnCount();
    ui->tableView->rowcount = DataModel->rowCount();
    ui->tableView->repaint();
    exchangeMode(1);
}



void MainWindow::on_start_clicked()
{
    qDebug()<<index1-5;
    QSqlQuery qsq;
    qsq.exec("select rowid from "+ sel_kind + " where real_id=" + QString::number(sel_no,10));
    if(qsq.first()) {
        if(qsq.value(0).toInt() < 110) {
            is_ok50 = true;
        }
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->Bit_Five->setEnabled(true);
    ui->Bit_Five->setCheckState(Qt::CheckState::Unchecked);
    ui->Bit_Four->setEnabled(true);
    ui->Bit_Four->setCheckState(Qt::CheckState::Unchecked);
    ui->Bit_One->setEnabled(true);
    ui->Bit_One->setCheckState(Qt::CheckState::Unchecked);
    ui->Bit_Seven->setEnabled(true);
    ui->Bit_Seven->setCheckState(Qt::CheckState::Unchecked);
    ui->Bit_Six->setEnabled(true);
    ui->Bit_Six->setCheckState(Qt::CheckState::Unchecked);
    ui->Bit_Three->setEnabled(true);
    ui->Bit_Three->setCheckState(Qt::CheckState::Unchecked);
    ui->Bit_Two->setEnabled(true);
    ui->Bit_Two->setCheckState(Qt::CheckState::Unchecked);
    ui->FiveTime->setEnabled(true);
    ui->FiveTime->setCheckState(Qt::CheckState::Unchecked);
    ui->FourTime->setEnabled(true);
    ui->FourTime->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Eight->setEnabled(true);
    ui->Num_Eight->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Five->setEnabled(true);
    ui->Num_Five->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Four->setEnabled(true);
    ui->Num_Four->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Nine->setEnabled(true);
    ui->Num_Nine->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_One->setEnabled(true);
    ui->Num_One->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Seven->setEnabled(true);
    ui->Num_Seven->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Six->setEnabled(true);
    ui->Num_Six->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Three->setEnabled(true);
    ui->Num_Three->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Two->setEnabled(true);
    ui->Num_Two->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Zero->setEnabled(true);
    ui->Num_Zero->setCheckState(Qt::CheckState::Unchecked);
    ui->SixMoreTime->setEnabled(true);
    ui->SixMoreTime->setCheckState(Qt::CheckState::Unchecked);
    ui->ThreeTime->setEnabled(true);
    ui->ThreeTime->setCheckState(Qt::CheckState::Unchecked);
    ui->qxc->setEnabled(true);
    ui->qxc->setCheckState(Qt::CheckState::Unchecked);
    ui->fc3d->setEnabled(true);
    ui->fc3d->setCheckState(Qt::CheckState::Unchecked);
    ui->pl3->setEnabled(true);
    ui->pl3->setCheckState(Qt::CheckState::Unchecked);
    ui->pl5->setEnabled(true);
    ui->pl5->setCheckState(Qt::CheckState::Unchecked);
    sql_bit = "";
    sql_cmp = "";
    sql_kind = "";
    sql_num = "";
    p_index = q_index = s_index = 0;
    if(timers == true) {
        return ;
    }
    QMessageBox msg(this);
    msg.setText("您现在可以重新勾选选项了！");
    msg.exec();
}

void MainWindow::on_Bit_Six_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Bit_Six->setDisabled(true);
        sql_bit.append("5, ");
        m_bit[6] = 1;
        is_ok21 = true;
    }
    else {
        is_ok21 = false;
    }
}

void MainWindow::on_Bit_Seven_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        ui->Bit_Seven->setDisabled(true);
        sql_bit.append("6, ");
        m_bit[7] = 1;
        is_ok22 = true;
    }
    else {
        is_ok22 = false;
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    QSqlQuery qsq4;
    QSqlQuery qsq41;
    qsq4.exec("DELETE FROM `realdata1`;");
    qsq41.exec("DELETE FROM 'sqlite_sequence' WHERE name='realdata1';");
    QSqlQuery qsq412;
    QSqlQuery qsq411;
    qsq412.exec("DELETE FROM `realdata2`;");
    qsq411.exec("DELETE FROM 'sqlite_sequence' WHERE name='realdata2';");
    if(timers == true) {
        return ;
    }
    QMessageBox msg(this);
    msg.setText("后台规律已经删除完毕~！");
    msg.exec();
}

void MainWindow::task_reload() {
    timers = true;
    ui->progressBar_2->setRange(0,5);
    for(int i = 0;i < 5;i ++) {
        on_pushButton_8_clicked();
        rt = new RealQThread(this);
        QObject::connect(rt, SIGNAL(finished()), rt, SLOT(deleteLater()));
        QObject::connect(dw1, SIGNAL(givesig(int)), rt, SLOT(giveresult(int)));
        QObject::connect(rt, &RealQThread::signalRunOver, &loop, &QEventLoop::quit);
        QObject::connect(dw1, SIGNAL(givedec(int,int)), ui->progressBar, SLOT(setRange(int,int)));
        QObject::connect(rt, SIGNAL(resultReady(int)), ui->progressBar, SLOT(setValue(int)));
        on_pushButton_3_clicked();
        usleep(5000);
        disp(list_table[i]);
        usleep(1000);
        ui->progressBar_2->setValue(i);
        ui->cb_kinds->setCurrentIndex(i);
        exchangeMode(i);
        QSqlQuery qsqt;
        clearrsq(table_data1);
        clearrsq(table_data2);
        QString str2 = "select is_new from "+list_table[i]+ " order by id_data desc limit 0,1;";
        qsqt.exec(str2);
        if(qsqt.first()) {
            if(qsqt.value(0).toInt() == 1) {
                continue ;
            }
        }
        usleep(1000);
        usleep(1000);
        QString str = "select real_id from "+list_table[i]+ " order by id_data desc limit 0,1;";
        QSqlQuery qsq;
        qsq.exec(str);
        if(qsq.first()) {
            ui->cb_no->setCurrentIndex(ui->cb_no->count() - 1);
        }
        emit startThread();
        usleep(5000);
        while (on_off) {
            usleep(1000);
            on_pushButton_2_clicked();
        }
        on_off = true;
    }
    ui->progressBar_2->setValue(5);
    timers = false;
}


void MainWindow::usleep(unsigned int msec)
{
    QElapsedTimer t;

    t.start();
    while (t.elapsed() < msec) {
        QCoreApplication::processEvents();
    }

}

void MainWindow::on_timeEdit_userTimeChanged(const QTime &time)
{
    timestring = time.toString("hh:mm");
    QTimer *m_timer;
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(autoKeepSampleTimeOut()));
    m_timer->start(2*1000*60); //every 2 minutes
    QDateTime datetime = QDateTime::currentDateTime();
    if(datetime.toString("hh:mm") == timestring && isgo)
    {
        task_reload();
    }
    m_timer->stop();
    m_timer->destroyed();
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked) {
        isgo = true;
    } else {
        isgo = false;
    }
}

void MainWindow::on_pushButton_5_clicked()
{

}
