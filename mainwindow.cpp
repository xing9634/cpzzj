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
          char*  ch;
          QByteArray ba = Enum_type[i].toLatin1();
          ch=ba.data();
          model->setHeaderData(i, Qt::Horizontal, QObject::tr(ch));
      }
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
          char*  ch;
          QByteArray ba = Enum_type[i].toLatin1();
          ch=ba.data();
          model->setHeaderData(i, Qt::Horizontal, QObject::tr(ch));
      }
  }
void MainWindow::exchangeMode(int mode)
{
    switch(mode)
    {
    case 1 :{
        this->initializeModel(this->DataModel,"qxc_data");
        ui->tableView->setModel(DataModel);
        ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.25);");
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->setColumnWidth(0,55);actiona();MAXSIZE = 4;set_data(DataModel);break;
        }
    case 2 : {
        this->initializeModel(this->DataModel,"dlt_data");
        ui->tableView->setModel(DataModel);
        ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.25);");
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->setColumnWidth(0,55);
        actiona();MAXSIZE = 4;set_data(DataModel);break;
        }
    case 3 : {
        this->initializeModel(this->DataModel,"fc3d_data");
        ui->tableView->setModel(DataModel);
        ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.25);");
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->setColumnWidth(0,55);actiona();MAXSIZE = 3;set_data(DataModel);break;
        }
    case 4 : {
        this->initializeModel(this->DataModel,"pl3_data");
        ui->tableView->setModel(DataModel);
        ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.25);");
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->setColumnWidth(0,55);actiona();MAXSIZE = 3;set_data(DataModel);break;
        }
    case 5 : {
        this->initializeModel(this->DataModel,"pl5_data");
        ui->tableView->setModel(DataModel);
        ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.25);");
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->setColumnWidth(0,55);actiona();MAXSIZE = 4;set_data(DataModel);break;
        }
    case 6 : {
        this->initializeModel(this->DataModel,"ssq_data");
        ui->tableView->setModel(DataModel);
        ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.25);");
        ui->tableView->setAlternatingRowColors(true);
        ui->tableView->setColumnWidth(0,55);actiona();MAXSIZE = 4;set_data(DataModel);break;
        }

    }
}
void MainWindow::set_data(QMySQlQueryModel *DataModel) {
    int sizeone = 4;
    if(DataModel->columnCount() <= 5) {
        sizeone = 3;
        int k = 1;
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
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
    if(DataModel->columnCount() >= 6) {
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
    } if(DataModel->columnCount()>= 7) {
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
    } if(DataModel->columnCount() >= 8) {
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
    qDebug() <<this->sqlcon->getDB().isOpenError() ;
    DataModel = new QMySQlQueryModel(this,this->sqlcon->getDB());
    initializeModel(DataModel,"qxc_data");
    pos1 = 1;
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
    rt = new RealQThread();
    //qi->setModel(&DataModel);
    ui->tableView->setModel(DataModel);
    ui->tableView->setStyleSheet("background-color: rgb(255, 255, 245); alternate-background-color: rgba(250,250,210,0.25);");
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
    sel_bit = 0;
    sel_kind = "qxc_data";
    sel_no = 0;
    sel_num = 0;
    sel_time = 3;
    //mtv->setModel(&DataModel2);
    //ui->tableView->viewport()->installEventFilter(this);
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(fuckyou2()));
    QObject::connect(ui->next,SIGNAL(clicked()),this,SLOT(fuckyou7()));
    QObject::connect(ui->cb_bits,SIGNAL(currentIndexChanged(int)),this, SLOT(bitLoadList(int)));
    QObject::connect(ui->cb_nums,SIGNAL(currentIndexChanged(int)),this, SLOT(numLoadList(int)));
    QObject::connect(ui->cb_kinds,SIGNAL(currentIndexChanged(int)),this, SLOT(kindLoadList(int)));
    QObject::connect(ui->cb_no,SIGNAL(currentIndexChanged(int)),this, SLOT(noLoadList(int)));
    QObject::connect(ui->cb_times,SIGNAL(currentIndexChanged(int)),this, SLOT(timeLoadList(int)));
    QObject::connect(ui->prev,SIGNAL(clicked()),this,SLOT(fuckyou8()));
    ui->tableView->columncount = DataModel->columnCount();
    ui->tableView->rowcount = DataModel->rowCount();
    ui->progressBar->setValue(0);
    QString num1 = "select real_id from qxc_data";
    QSqlQuery qsq1;
    qsq1.exec(num1);
    int c = 0;
    while(qsq1.next())
    {
        real_id[c] = qsq1.value(0).toInt();
        ui->cb_no->insertItem(c,QString::number(real_id[c],10),real_id[c]);
        c++;
    }
    set_data(DataModel);
    MAXSIZE = 4;
    pos = 1;
    pos2 = 1;
    ui->cb_bits->insertItem(0,"个位",0);
    ui->cb_bits->insertItem(1,"十位",1);
    ui->cb_bits->insertItem(2,"百位",2);
    ui->cb_bits->insertItem(3,"千位",3);
    ui->cb_bits->insertItem(4,"万位",4);
    ui->cb_bits->insertItem(5,"十万位",5);
    ui->cb_bits->insertItem(6,"百万位",6);
    ui->cb_kinds->insertItem(0,"七星彩","qxc_data");
    ui->cb_kinds->insertItem(1,"大乐透","dlt_data");
    ui->cb_kinds->insertItem(2,"福彩3D","fc3d_data");
    ui->cb_kinds->insertItem(3,"排列3","pl3_data");
    ui->cb_kinds->insertItem(4,"排列5","pl5_data");
    ui->cb_kinds->insertItem(6,"双色球","ssq_data");
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
    QTimer *timer = new QTimer(this);
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
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(task()));
    timer->start(2*1000*60);
    qDebug()<<DataModel->columnCount();
    qDebug()<<matA[0].array[0][0];
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::kindLoadList(int type)
{
    sel_kind = ui->cb_kinds->currentData().toString();
    exchangeMode(ui->cb_kinds->currentIndex() + 1);
}

void MainWindow::noLoadList(int type)
{
    sel_no = ui->cb_no->currentData().toInt();
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


void MainWindow::FindBestWay(QMySQlQueryModel *model)
{

}

void MainWindow::fuckyou1()
{

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
    if(is_ok50 == true) {
        QMessageBox msg(this);
        msg.setText("不能使用当前期数来查找规律！");
        msg.exec();
        is_ok50 = false;
        return ;
    }
    int index = 0;
    mainth = true;
    QSqlQuery qsq;
    QSqlQuery qsq1;
    qsq.exec("select rowid from "+sel_kind+" where real_id="+QString::number(sel_no,10) );
    if(qsq.first()) {
        index = qsq.value(0).toInt();
    }
    qsq1.exec("select rowid from "+sel_kind+" limit 0,1");
    if(qsq1.first()) {
        index -= qsq1.value(0).toInt();
    }

    index1 = index;
    qDebug()<<index1<<"    cascascascacascascascascascascascascascascascacacaca";
    //qDebug()<<DataModel->data(index,Qt::TextAlignmentRole).toInt()<<"Hello ";
    //printf("%d\n",w.qc->rowViewportPosition(1));
    ui->progressBar->setRange(0,4);
    rt->start = index1-5;
   // rt->db = this->sqlcon->getDB();
    //rt->begin();
    int k = 0;
    for(int gap = 0;gap<4;gap++)
    {
        k++;
        ui->progressBar->setValue(k);
        QCoreApplication::processEvents();
        Drawabler dw1(gap,DataModel);
        dw1.kind = sel_kind;
        if(sel_kind == "fc3d" || sel_kind == "pl3") {
            dw1.MAXSIZE = 3;
            int k1 = 1;
            for(int i = 0;i<3;i++)
            {
                for(int j = 0;j<3;j++)
                {
                    dw1.maper[i][j] = k1;
                    k1++;
                }
            }
        } else {
            dw1.MAXSIZE = 4;
        }
        dw1.re_start = sel_no;
        for(int i  = 0;i < 4;i ++) {
            if(isvalid[i] == true) {
                dw1.Find(this->sqlcon->getDB(),gap,index1,matA[i],i);
            }
        }
    }
    QSqlQuery qsq2;
    qsq2.exec("insert into updatestatus(status) VALUES('FALSE')");
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
    qDebug()<<"select id,num,data1,data2,data3,gap,cmp,pos,start from realdata1 where pos="+QString::number(sel_bit,10)+" and cmp="+QString::number(sel_time,10)+" and mode="+QString::number(mode,10);
    qsq0.exec("select id,num,data1,data2,data3,gap,cmp,pos,start from realdata1 where pos="+QString::number(sel_bit,10)+" and cmp="+QString::number(sel_time,10)+" and mode="+QString::number(mode,10));
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
    qsq1.exec("select id,num,data1,data2,data3,gap,cmp,pos,start from realdata2 where pos ="+QString::number(sel_bit,10)+" and cmp="+QString::number(sel_time,10)+" and mode="+QString::number(mode));
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

void MainWindow::savepic(int id,int index)
{
    QString runPath;
    QString hglpName;
    QString hglpPath;
    QSqlQuery qsq2;
    QString cd;
    QString num2 = QString::number(id, 10);
    QString num3 = QString::number(pointer2[colored].cmp);
    QString num4 = QString::number(pointer2[colored].gap);
    QString num5 = QString::number(pointer2[colored].start+5+MAXNO);
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy-MM-dd");
    qsq2.exec("select data from cdata where no="+num5);
    if(qsq2.first())
    {
       cd = qsq2.value(0).toString();
    }
    QString num1 = QString::number(index, 10);
    QString as1 = num5+"-"+num4+"-"+num3+"-"+num2+"-"+num1+".png";
    runPath = QCoreApplication::applicationDirPath();       //获取exe路径
    hglpName = "photo";
    hglpPath = QString("%1/%2").arg(runPath).arg(hglpName);
    QPixmap pix = ui->tableView->grab(ui->tableView->viewport()->rect());
    qDebug()<<ui->tableView->rect().x()<<ui->tableView->rect().size()<<"x";
    QString astr = QString("%1/%2/%3/").arg(hglpPath).arg(cd).arg(num5);
    QString Filename = QString("%4_%5_%6-%7_qxc").arg(num3).arg(num4).arg(num1).arg(num2);
    isDirExist(astr);
    pix.save(astr+Filename+".png","PNG");
    QSqlQuery qsq;
    qsq.prepare("insert into imgpath(picname,start,gap,no,cmp,date) values (?,?,?,?,?,?)");
    qsq.addBindValue(Filename);
    qsq.addBindValue(pointer2[colored].start);
    qsq.addBindValue(pointer2[colored].gap);
    qsq.addBindValue(pointer2[colored].start+5+MAXNO);
    qsq.addBindValue(pointer2[colored].cmp);
    qsq.addBindValue(current_date);
    qsq.exec();
    qDebug()<<qsq.lastError();
}

int MainWindow::getXfromMap(int data)
{
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
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
        for(int j = 0;j<4;j++)
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
    qDebug()<<x<<y;
    if(x==-1||y==-1)
    {
        return ;
    }
    else{
        line.setX(ui->tableView->columnViewportPosition(y+ADDS+posadd)+ui->tableView->columnWidth(y+ADDS+posadd)/2.0);
        line.setY(ui->tableView->rowViewportPosition(x)+ui->tableView->rowHeight(x)/2.0);
    }
    qDebug() <<x<<y<<"pos";
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
    int position = 0;
    pos = QString::number(sel_bit,10);
    QString time = QString::number(sel_time,10);
    QString nums = QString::number(sel_num,10);
    QString table = kind;
    QString pos1 = QString::number(sel_bit,10);
    QSqlQuery qsq22;
    int started = sel_no;
    db.transaction();
    qsq22.exec("select rowid from "+sel_kind+" where real_id="+QString::number(sel_no,10));
    QSqlQuery qsq33;
    if(qsq22.first()) {
        started = qsq22.value(0).toInt();
    }
    qsq33.exec("select rowid,data1,data2,data3,gap,cmp,pos from realdata1 where pos="+pos+"  and cmp="+time+" and num="+nums+ " and mode=0");
    if(qsq33.first()) {
        start = QString::number(started,10);
        end = QString::number(started - ( MAXSIZE + qsq33.value(4).toInt())*qsq33.value(5).toInt(),10);
        id = QString::number(qsq33.value(0).toInt(),10);
    }
    qDebug()<<start;
    position = used;
    qDebug()<<pos<<"used================================="<<pointer1[used].id;
    QString as1 = "select data1,data2,data3,gap,cmp,pos,mode from realdata1 where pos="+pos+"  and cmp="+time+" and num="+nums +" and mode=0";
    QString as2 = "select data1,data2,data3,gap,cmp,pos,mode from realdata2 where pos="+pos+"  and cmp="+time+" and num="+nums+ " and mode=0";
    db.commit();
    QSqlQuery qsq7;
    qDebug()<<as1<<as2;
    QString create_table = "DROP TABLE `MyTable`;";
    QString createtable;
    QString querry_table;
    if(sel_kind == "qxc_data") {
        createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL,`four` INT NULL,`five` INT NULL,`six` INT NULL,`seven` INT NULL);";
        querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`,`four`,`five`,`six`,`seven`) SELECT `real_id`,`one`,`two`,`three`,`four`,`five`,`six`,`seven` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    } else if(sel_kind == "pl3_data") {
        createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL);";
        querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`) SELECT `real_id`,`one`,`two`,`three` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    } else if(sel_kind == "pl5_data") {
        createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL,`four` INT NULL,`five` INT NULL);";
        querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`,`four`,`five`) SELECT `real_id`,`one`,`two`,`three`,`four`,`five` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    } else if(sel_kind == "fc3d_data") {
        createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL);";
        querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`) SELECT `real_id`,`one`,`two`,`three` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    } else if(sel_kind == "dlt_data") {
        createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL,`four` INT NULL,`five` INT NULL);";
        querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`,`four`,`five`) SELECT `real_id`,`one`,`two`,`three`,`four`,`five` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    } else if(sel_kind == "ssq_data") {
        createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL,`four` INT NULL,`five` INT NULL,`six` INT NULL);";
        querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`,`four`,`five`,`six`) SELECT `real_id`,`one`,`two`,`three`,`four`,`five`,`six` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    }
    QString tail_table[4];
    for(int i  = 0;i < 4;i ++) {
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
    if(!qsq1.isValid()) {
        QMessageBox msg(this);
        msg.setText("没有找到相关规律！");
        msg.exec();
        return false;
    }
    int ccmp1,ccmp2;
    qsq1.first();
    for(int i = 0;i<qsq1.value(4).toInt();i++)
    {
        if(getXfromMap(qsq1.value(0).toInt())!=-1&&getYfromMap(qsq1.value(0).toInt())!=-1)
         executeSql(line1[i][0],getXfromMap(qsq1.value(0).toInt()) + DataModel->rowCount() - (i)*(qsq1.value(3).toInt() + MAXSIZE) - 4,getYfromMap(qsq1.value(0).toInt()) , qsq1.value(6).toInt());
        if(getXfromMap(qsq1.value(1).toInt())!=-1&&getYfromMap(qsq1.value(1).toInt())!=-1)
            executeSql(line1[i][1],getXfromMap(qsq1.value(1).toInt()) + DataModel->rowCount() - (i)*(qsq1.value(3).toInt() + MAXSIZE) - 4,getYfromMap(qsq1.value(1).toInt()) , qsq1.value(6).toInt());
        if(getXfromMap(qsq1.value(2).toInt())!=-1&&getYfromMap(qsq1.value(2).toInt())!=-1)
            executeSql(line1[i][2],getXfromMap(qsq1.value(2).toInt()) + DataModel->rowCount() - (i)*(qsq1.value(3).toInt() + MAXSIZE) - 4,getYfromMap(qsq1.value(2).toInt()) , qsq1.value(6).toInt());
    }
    ccmp1 = qsq1.value(6).toInt();
    qsq2.exec(as2);
    qsq2.first();
    qDebug()<<as2<<as1<<qsq2.lastError();
    for(int i = 0;i<qsq2.value(4).toInt();i++)
    {
        qDebug()<<qsq2.lastError()<<"csacjabuicaqavbcuyavbuvauh";
        if(getXfromMap(qsq2.value(0).toInt())!=-1&&getYfromMap(qsq2.value(0).toInt())!=-1)
            executeSql(line2[i][0],getXfromMap(qsq2.value(0).toInt()) + DataModel->rowCount() - (i)*(qsq2.value(3).toInt() + MAXSIZE) - 4,getYfromMap(qsq2.value(0).toInt()) , qsq2.value(6).toInt());
        if(getXfromMap(qsq2.value(1).toInt())!=-1&&getYfromMap(qsq2.value(1).toInt())!=-1)
            executeSql(line2[i][1],getXfromMap(qsq2.value(1).toInt()) + DataModel->rowCount() - (i)*(qsq2.value(3).toInt() + MAXSIZE) - 4,getYfromMap(qsq2.value(1).toInt()) , qsq2.value(6).toInt());
        if(getXfromMap(qsq2.value(2).toInt())!=-1&&getYfromMap(qsq2.value(2).toInt())!=-1)
            executeSql(line2[i][2],getXfromMap(qsq2.value(2).toInt()) + DataModel->rowCount() - (i)*(qsq2.value(3).toInt() + MAXSIZE) - 4,getYfromMap(qsq2.value(2).toInt()) , qsq2.value(6).toInt());
    }
    ccmp2 = qsq2.value(6).toInt();
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
    ui->tableView->repaint();
    savepic(pointer2[position].id,index);
    return true;
}


void MainWindow::mainthing2()
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
    selected(this->sqlcon->getDB(),sel_bit,sel_no,sel_kind,sel_time,sel_num);
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
    QSqlQuery qsq1;
    QSqlQuery qsq2;
    QString as1;
    QString as2;
    as1 = "truncate realdata1";
    as2 = "truncate realdata2";
    qsq1.exec(as1);
    qsq1.exec(as2);
}

void MainWindow::mainthing9()
{

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

void MainWindow::disp() {
    file.setFileName("data.txt");
    file.open(QIODevice::ReadOnly);
    QByteArray t[500] ;
    int i  = 0;
    qDebug()<<file.isOpen();
    while(!file.atEnd()) {
        t[i] += file.readLine();
        readF.a = t[i].split('\t');
        qDebug()<<readF.a[0]<<readF.a[1]<<sel_kind<<endl;
        QSqlQuery qsq;
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date = current_date_time.toString("yyyy-MM-dd");
        if(sel_kind == "dlt_data") {
            qsq.prepare("insert into dlt_data(real_id,one,two,three,four,five,date) values(?,?,?,?,?,?,?)");
            for(int j = 0;j < 6;j ++) {
                qsq.addBindValue(readF.a[i].toInt());
            }
            qsq.addBindValue(current_date);
        } else if(sel_kind == "ssq_data") {
            qsq.prepare("insert into ssq_data(real_id,one,two,three,four,five,six,date)values(?,?,?,?,?,?,?,?)");
            for(int j = 0;j < 7;j ++) {
                qsq.addBindValue(readF.a[j].toInt());
            }
            qsq.addBindValue(current_date);
        } else if(sel_kind == "pl3_data") {
            qsq.prepare("insert into pl3_data(real_id,one,two,three,date) values(?,?,?,?,?)");
            readF.b = readF.a[1].split(' ');
            qsq.addBindValue(readF.a[0].toInt());
            for(int j = 0;j < readF.b.length();j ++) {
                qsq.addBindValue(readF.b[j].toInt());
            }
            qsq.addBindValue(current_date);
        } else if(sel_kind == "pl5_data") {
            qsq.prepare("insert into pl5_data(real_id,one,two,three,four,five,date) values(?,?,?,?,?,?,?)");
            readF.b = readF.a[1].split(' ');
            qsq.addBindValue(readF.a[0].toInt());
            for(int j = 0;j < readF.b.length();j ++) {
                qsq.addBindValue(readF.b[j].toInt());
            }
            qsq.addBindValue(current_date);
        } else if(sel_kind == "qxc_data") {
            qsq.prepare("insert into qxc_data(real_id,one,two,three,four,five,six,seven,date) values(?,?,?,?,?,?,?,?,?)");
            readF.b = readF.a[1].split(' ');
            qDebug()<<readF.b[0]<<readF.b.length()<<endl;
            qsq.addBindValue(readF.a[0].toInt());
            for(int j = 0;j < readF.b.length();j ++) {
                qsq.addBindValue(readF.b[j].toInt());
            }
            qsq.addBindValue(current_date);
        } else if(sel_kind == "fc3d_data") {
            qsq.prepare("insert into fc3d_data(real_id,one,two,three,date) values(?,?,?,?,?)");
            readF.b = readF.a[1].split(' ');
            qsq.addBindValue(readF.a[0].toInt());
            for(int j = 0;j < readF.b.length();j ++) {
                qsq.addBindValue(readF.b[j].toInt());
            }
            qsq.addBindValue(current_date);
        }
        qsq.exec();
        qDebug()<<"ok";
        i++;
    }
    QMessageBox msg(this);
    msg.setText("导入完毕！");
    msg.exec();
    file.close();
}

void MainWindow::on_next_clicked()
{
    emit disp();
}

void MainWindow::vieweraction() {

    QSqlQuery qsq7;
    QSqlQuery qsq3;
    QSqlQuery qsq22;
    qsq22.exec("select rowid from "+sel_kind+" where real_id="+QString::number(table_data1[pos].start,10));
    QString start,end;
    int started;
    if(qsq22.first()) {
        started = qsq22.value(0).toInt();
    }
    start = QString::number(started);
    end = QString::number(started - ( MAXSIZE + table_data1[pos].gap)*table_data1[pos].cmp,10);
    QString create_table = "DROP TABLE `MyTable`;";
    QString createtable;
    QString querry_table;
    if(sel_kind == "qxc_data") {
        createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL,`four` INT NULL,`five` INT NULL,`six` INT NULL,`seven` INT NULL);";
        querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`,`four`,`five`,`six`,`seven`) SELECT `real_id`,`one`,`two`,`three`,`four`,`five`,`six`,`seven` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    } else if(sel_kind == "pl3_data") {
        createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL);";
        querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`) SELECT `real_id`,`one`,`two`,`three` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    } else if(sel_kind == "pl5_data") {
        createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL,`four` INT NULL,`five` INT NULL);";
        querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`,`four`,`five`) SELECT `real_id`,`one`,`two`,`three`,`four`,`five` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    } else if(sel_kind == "fc3d_data") {
        createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL);";
        querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`) SELECT `real_id`,`one`,`two`,`three` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    } else if(sel_kind == "dlt_data") {
        createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL,`four` INT NULL,`five` INT NULL);";
        querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`,`four`,`five`) SELECT `real_id`,`one`,`two`,`three`,`four`,`five` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    } else if(sel_kind == "ssq_data") {
        createtable = "CREATE TABLE `MyTable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL,`four` INT NULL,`five` INT NULL,`six` INT NULL);";
        querry_table = "INSERT INTO `MyTable` (`real_id`,`one`,`two`,`three`,`four`,`five`,`six`) SELECT `real_id`,`one`,`two`,`three`,`four`,`five`,`six` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    }
    QString tail_table[4];
    for(int i  = 0;i < 4;i ++) {
        tail_table[i] = "INSERT INTO `MyTable`(`real_id`,`"+string_table[i]+"`)VALUES("+QString::number(table_data1[pos].start,10)+","+QString::number(table_data1[pos].num,10)+");";
    }
    QSqlQuery qsqt;
    QSqlQuery qsq4;
    QSqlQuery qsq41;
    qsq4.exec("DELETE FROM MyTable;");
    qsq41.exec("DELETE FROM sqlite_sequence WHERE name = 'mytable';");
    qsq7.exec(createtable);
    qsq3.exec(querry_table);
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
         executeSql(line1[j][0],getXfromMap(table_data1[pos].one) + DataModel->rowCount() - (j)*(table_data1[pos].gap + MAXSIZE) - 4,getYfromMap(table_data1[pos].one) , table_data1[pos].mode);
        if(getXfromMap(table_data1[pos].two)!=-1&&getYfromMap(table_data1[pos].two)!=-1)
            executeSql(line1[j][1],getXfromMap(table_data1[pos].two) + DataModel->rowCount() - (j)*(table_data1[pos].gap + MAXSIZE) - 4,getYfromMap(table_data1[pos].two) , table_data1[pos].mode);
        if(getXfromMap(table_data1[pos].three)!=-1&&getYfromMap(table_data1[pos].three)!=-1)
            executeSql(line1[j][2],getXfromMap(table_data1[pos].three) + DataModel->rowCount() - (j)*(table_data1[pos].gap + MAXSIZE) - 4,getYfromMap(table_data1[pos].three) , table_data1[pos].mode);
    }
    for(int j = 0;j < table_data2[pos].cmp; j ++) {
        if(getXfromMap(table_data2[pos].one)!=-1&&getYfromMap(table_data2[pos].one)!=-1)
         executeSql(line2[j][0],getXfromMap(table_data2[pos].one) + DataModel->rowCount() - (j)*(table_data2[pos].gap + MAXSIZE) - 4,getYfromMap(table_data2[pos].one) , table_data2[pos].mode);
        if(getXfromMap(table_data2[pos].two)!=-1&&getYfromMap(table_data2[pos].two)!=-1)
            executeSql(line2[j][1],getXfromMap(table_data2[pos].two) + DataModel->rowCount() - (j)*(table_data2[pos].gap + MAXSIZE) - 4,getYfromMap(table_data2[pos].two) ,table_data2[pos].mode);
        if(getXfromMap(table_data2[pos].three)!=-1&&getYfromMap(table_data2[pos].three)!=-1)
            executeSql(line2[j][2],getXfromMap(table_data2[pos].three) + DataModel->rowCount() - (j)*(table_data2[pos].gap + MAXSIZE) - 4,getYfromMap(table_data2[pos].three) , table_data2[pos].mode);
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
    ui->tableView->repaint();
    savepic(table_data1[pos].id,table_data1[pos].pos);
}

void MainWindow::viewer() {
    int i = 0;
    QSqlQuery qsq1;
    qsq1.exec("select id,num,data1,data2,data3,gap,cmp,pos,start,mode,kind from realdata1 limit 0,100");
    qDebug()<<qsq1.lastError();
    while(qsq1.next()) {
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
    qsq2.exec("select id,num,data1,data2,data3,gap,cmp,pos,start,mode,kind from realdata2 limit 0,100");
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
    for(int i = 0;i<6;i++)
    {
        for(int j = 0;j<3;j++)
        {
            qDebug()<<line1[i][j]<<"endl";
            ui->tableView->line1[i][j] = line1[i][j];
            ui->tableView->line2[i][j] = line2[i][j];
        }
    }
    if(pos == 1) {
        emit viewer();
    }
    pos ++;
    emit vieweraction();

}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery qsq4;
    QSqlQuery qsq41;
    qsq4.exec("DELETE FROM "+sel_kind+";");
    qsq41.exec("DELETE FROM sqlite_sequence WHERE name = "+sel_kind+";");
}

void MainWindow::on_qxc_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        sql_kind.append("and kind='qxc_data'");
        is_ok1 = true;
    }
    else {
        is_ok1 = false;
    }
}

void MainWindow::on_pl3_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        sql_kind.append("and kind='pl3_data' ");
        is_ok2 = true;
    }
    else {
        is_ok2 = false;
    }
}

void MainWindow::on_pl5_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        sql_kind.append("and kind='pl5_data' ");
        is_ok3 = true;
    }
    else {
        is_ok3 = false;
    }
}

void MainWindow::on_fc3d_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        sql_kind.append("and kind='fc3d_data' ");
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
        sql_cmp.append("3, ");
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
        sql_cmp.append("4, ");
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
        sql_cmp.append("5, ");
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
        sql_cmp.append("6,7,8,9,10 ");
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
        sql_bit.append("0, ");
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
        sql_bit.append("1, ");
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
        sql_bit.append("2, ");
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
        sql_bit.append("3, ");
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
        sql_bit.append("4, ");
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
        sql_num.append("6, ");
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
        sql_num.append("7, ");
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
        sql_num.append("8, ");
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
        sql_num.append("9, ");
        is_ok17 = true;
    }
    else {
        is_ok17 = false;
    }
}

void MainWindow::analyze() {
    QSqlQuery qsq7;
    QSqlQuery qsq3;
    QSqlQuery qsq22;
    qsq22.exec("select rowid from "+search_data1[pos2].kind+" where real_id="+QString::number(search_data1[pos2].start,10));
    qDebug()<<search_data1[pos2].kind<<"dwqdqwdqwedqw";
    QString start,end;
    int started;
    if(qsq22.first()) {
        started = qsq22.value(0).toInt();
    }
    start = QString::number(started);
    end = QString::number(started - ( MAXSIZE + search_data1[pos2].gap)*search_data1[pos2].cmp,10);
    QString create_search = "DROP table `Mytable`;";
    QString createsearch;
    QString querry_search;
    if(search_data1[pos2].kind == "qxc_data") {
        createsearch = "CREATE table `Mytable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL,`four` INT NULL,`five` INT NULL,`six` INT NULL,`seven` INT NULL);";
        querry_search = "INSERT INTO `Mytable` (`real_id`,`one`,`two`,`three`,`four`,`five`,`six`,`seven`) SELECT `real_id`,`one`,`two`,`three`,`four`,`five`,`six`,`seven` FROM "+sel_kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    } else if(search_data1[pos2].kind == "pl3_data") {
        createsearch = "CREATE table `Mytable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL);";
        querry_search = "INSERT INTO `Mytable` (`real_id`,`one`,`two`,`three`) SELECT `real_id`,`one`,`two`,`three` FROM "+search_data1[pos2].kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    } else if(search_data1[pos2].kind == "pl5_data") {
        createsearch = "CREATE table `Mytable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL,`four` INT NULL,`five` INT NULL);";
        querry_search = "INSERT INTO `Mytable` (`real_id`,`one`,`two`,`three`,`four`,`five`) SELECT `real_id`,`one`,`two`,`three`,`four`,`five` FROM "+search_data1[pos2].kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    } else if(search_data1[pos2].kind == "fc3d_data") {
        createsearch = "CREATE table `Mytable`(`real_id` INT NOT NULL PRIMARY KEY,`one` INT NULL,`two` INT NULL,`three` INT NULL);";
        querry_search = "INSERT INTO `Mytable` (`real_id`,`one`,`two`,`three`) SELECT `real_id`,`one`,`two`,`three` FROM "+search_data1[pos2].kind+" WHERE `rowid`<"+ start+" AND `rowid`>"+end+";";
    }
    QString tail_search[4];
    for(int i  = 0;i < 4;i ++) {
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
            executeSql(line1[j][0],getXfromMap(search_data1[pos2].one) + DataModel->rowCount() - (j)*(search_data1[pos2].gap + MAXSIZE) - 4,getYfromMap(search_data1[pos2].one),search_data2[pos2].mode);
        if(getXfromMap(search_data1[pos2].two)!=-1&&getYfromMap(search_data1[pos2].two)!=-1)
            executeSql(line1[j][1],getXfromMap(search_data1[pos2].two) + DataModel->rowCount() - (j)*(search_data1[pos2].gap + MAXSIZE) - 4,getYfromMap(search_data1[pos2].two) ,search_data2[pos2].mode);
        if(getXfromMap(search_data1[pos2].three)!=-1&&getYfromMap(search_data1[pos2].three)!=-1)
            executeSql(line1[j][2],getXfromMap(search_data1[pos2].three) + DataModel->rowCount() - (j)*(search_data1[pos2].gap + MAXSIZE) - 4,getYfromMap(search_data1[pos2].three),search_data2[pos2].mode);
    }
    for(int j = 0;j < search_data2[pos2].cmp; j ++) {
        if(getXfromMap(search_data2[pos2].one)!=-1&&getYfromMap(search_data2[pos2].one)!=-1)
            executeSql(line2[j][0],getXfromMap(search_data2[pos2].one) + DataModel->rowCount() - (j)*(search_data2[pos2].gap + MAXSIZE) - 4,getYfromMap(search_data2[pos2].one),search_data2[pos2].mode);
        if(getXfromMap(search_data2[pos2].two)!=-1&&getYfromMap(search_data2[pos2].two)!=-1)
            executeSql(line2[j][1],getXfromMap(search_data2[pos2].two) + DataModel->rowCount() - (j)*(search_data2[pos2].gap + MAXSIZE) - 4,getYfromMap(search_data2[pos2].two),search_data2[pos2].mode);
        if(getXfromMap(search_data2[pos2].three)!=-1&&getYfromMap(search_data2[pos2].three)!=-1)
            executeSql(line2[j][2],getXfromMap(search_data2[pos2].three) + DataModel->rowCount() - (j)*(search_data2[pos2].gap + MAXSIZE) - 4,getYfromMap(search_data2[pos2].three),search_data2[pos2].mode);
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
    ui->tableView->repaint();
    savepic(search_data1[pos2].id,search_data1[pos2].pos);
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
    sql_main1 = "select id,num,data1,data2,data3,gap,cmp,pos,start,mode,kind from realdata1 where start=" + ui->seq->text() + " ";
    sql_main2 = "select id,num,data1,data2,data3,gap,cmp,pos,start,mode,kind from realdata2 where start="+ ui->seq->text()+ " ";
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
    emit analyze_prep();
    pos2 ++;
    emit analyze();
}

void MainWindow::on_Num_Zero_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) // "选中"
    {
        sql_num.append("0, ");
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
        sql_num.append("1, ");
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
        sql_num.append("2, ");
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
        sql_num.append("3, ");
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
        sql_num.append("4, ");
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
        sql_num.append("5, ");
        is_ok23 = true;
    }
    else {
        is_ok23 = false;
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(ui->tableView->line1[0][0].isNull() == true) {
        QMessageBox msg(this);
        msg.setText("还没有查找到规律呢！");
        msg.exec();
        return ;
    }
    memset(ui->tableView->line1,0,sizeof(ui->tableView->line1));
    memset(ui->tableView->line2,0,sizeof(ui->tableView->line2));
    ui->tableView->repaint();
    exchangeMode(1);
}

void MainWindow::on_pushButton_5_clicked()
{
    if(pos2 == 1) {
        QMessageBox msg(this);
        msg.setText("还没有开始初始化规律！");
        msg.exec();
        return ;
    }
    pos2 ++;
    emit analyze();
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
    emit mainthing();
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->Bit_Five->setCheckState(Qt::CheckState::Unchecked);
    ui->Bit_Four->setCheckState(Qt::CheckState::Unchecked);
    ui->Bit_One->setCheckState(Qt::CheckState::Unchecked);
    ui->Bit_Seven->setCheckState(Qt::CheckState::Unchecked);
    ui->Bit_Six->setCheckState(Qt::CheckState::Unchecked);
    ui->Bit_Three->setCheckState(Qt::CheckState::Unchecked);
    ui->Bit_Two->setCheckState(Qt::CheckState::Unchecked);
    ui->FiveTime->setCheckState(Qt::CheckState::Unchecked);
    ui->FourTime->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Eight->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Five->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Four->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Nine->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_One->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Seven->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Six->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Three->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Two->setCheckState(Qt::CheckState::Unchecked);
    ui->Num_Zero->setCheckState(Qt::CheckState::Unchecked);
    ui->SixMoreTime->setCheckState(Qt::CheckState::Unchecked);
    ui->ThreeTime->setCheckState(Qt::CheckState::Unchecked);
    sql_bit = "";
    sql_cmp = "";
    sql_kind = "";
    sql_num = "";
}
