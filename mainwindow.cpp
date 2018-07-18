#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include "corekernel.h"
#include"qtableview.h"
#include"QMessageBox"
#include <QDateTime>
#include "QHBoxLayout"


void MainWindow::initializeModel(QMySQlQueryModel *model)
  {

      //QString num = QString::number(pos,10);
     // QString num2 = QString::number(pos+8,10);
     // QString sel = "select one,two,three,four,five,six,seven from data where id_data>="+num+"and id_data<"+num2;
      model->setTable("data");
     // model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      model->removeColumn(0);
      model->removeColumn(9);
      model->select();
      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("real_id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("sum"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("one"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("two"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("three"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("four"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("five"));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("six"));
      model->setHeaderData(8, Qt::Horizontal, QObject::tr("seven"));
  }

void MainWindow::changeModel(QMySQlQueryModel *model)
  {

      //QString num = QString::number(pos,10);
     // QString num2 = QString::number(pos+8,10);
     // QString sel = "select one,two,three,four,five,six,seven from data where id_data>="+num+"and id_data<"+num2;
      model->setTable("MyTable");
     // model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      model->select();
      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("real_id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("sum"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("one"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("two"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("three"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("four"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("five"));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("six"));
      model->setHeaderData(8, Qt::Horizontal, QObject::tr("seven"));
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
    DataModel = new QMySQlQueryModel(this,this->sqlcon->getDB());
    initializeModel(DataModel);
    pos1 = 1;
    colored = 0;
    used = 0;
    ok = false;
    int k = 1;
    b1 = b2 = b3 = b4 = false;
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            mapper[i][j] = k;
            k++;
        }
    }
    //qi->setModel(&DataModel);
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
    //mtv->setModel(&DataModel2);
    ui->tableView->setStyleSheet("alternate-background-color: rgba(170, 255, 255,0.25);");
    //ui->tableView->viewport()->installEventFilter(this);
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(fuckyou2()));
    QObject::connect(ui->start,SIGNAL(clicked()),this,SLOT(fuckyou1()));
    QObject::connect(ui->rb1,SIGNAL(clicked()),this,SLOT(fuckyou3()));
    QObject::connect(ui->rb2,SIGNAL(clicked()),this,SLOT(fuckyou4()));
    QObject::connect(ui->rb3,SIGNAL(clicked()),this,SLOT(fuckyou5()));
    QObject::connect(ui->rb4,SIGNAL(clicked()),this,SLOT(fuckyou6()));
    QObject::connect(ui->next,SIGNAL(clicked()),this,SLOT(fuckyou7()));
    QObject::connect(ui->prev,SIGNAL(clicked()),this,SLOT(fuckyou8()));
    QObject::connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(fuckyou9()));
    ui->tableView->columncount = DataModel->columnCount();
    ui->tableView->rowcount = DataModel->rowCount();
    ui->progressBar->setValue(0);
    QString num1 = "select real_id from data";
    QSqlQuery qsq1;
    qsq1.exec(num1);
    int c = 0;
    while(qsq1.next())
    {
        real_id[c] = qsq1.value(0).toInt();
        c++;
    }
    ui->spinBox->setMaximum(100000);
    ui->spinBox->setDisplayIntegerBase(0);
    //qDebug()<<ui->tableView->rect().width()<<"Width";
    //qDebug()<<ui->tableView->rect().height()<<"Height";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FindBestWay(QMySQlQueryModel *model)
{

}

void MainWindow::fuckyou1()
{
    emit mainthing();
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

void MainWindow::mainthing9()
{
    index1 = ui->spinBox->value();
}

void MainWindow::mainthing4()
{
    if(b2 == false)
        b2 = true;
}

//搜寻按钮
void MainWindow::mainthing()
{
    QSqlQuery qsq;
    QModelIndex index2 = DataModel->index(1,1);
    //qDebug()<<DataModel->data(index,Qt::TextAlignmentRole).toInt()<<"Hello ";
    qsq.exec("select status from updatestatus");
    qsq.last();
    QString status = qsq.value(0).toString();
    if(qsq.record().isEmpty())
        status = "TRUE";
    if(status == "FALSE")
        return ;
    //printf("%d\n",w.qc->rowViewportPosition(1));
    ui->progressBar->setRange(0,4*(MAXCMP-2));
    int k = 0;
    Drawabler::Matrixx mat1[4],mat2[4];
    for(int gap = 0;gap<4;gap++)
    {
        for(int cmp = 2;cmp<MAXCMP;cmp++)
        {
            ui->progressBar->setValue(k);
            k++;
            QCoreApplication::processEvents();
            Drawabler dw1(mat1[gap],mat2[gap],gap,DataModel);
            dw1.Find(this->sqlcon->getDB(),gap,cmp,index1-5);

        }
    }
    QSqlQuery qsq2;
    qsq2.exec("insert into updatestatus(status) VALUES('FALSE')");

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

void MainWindow::selector(int index)
{
    memset(pointer1,0,sizeof(pointer1));
    memset(pointer2,0,sizeof(pointer2));
    QSqlQuery qsq0;
    QSqlQuery qsq1;
    int k = 0;
    qsq0.exec("select id,num,data1,data2,data3,gap,cmp,pos,start from realdata1 where pos="+QString::number(index,10));
    while(qsq0.next())
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
    pointer1->len = k;
    k = 0;
    qsq1.exec("select id,num,data1,data2,data3,gap,cmp,pos,start from realdata2 where pos ="+QString::number(index,10));
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
    QDate current_date = QDate::currentDate();
    QString cd = current_date.toString("yyyy-MM-dd");
    QString num2 = QString::number(id, 10);
    QString num3 = QString::number(pointer2[colored].cmp);
    QString num4 = QString::number(pointer2[colored].gap);
    QString num5 = QString::number(pointer2[colored].start+5+MAXNO);
    QString num1 = QString::number(index, 10);
    QString as1 = num5+"-"+num4+"-"+num3+"-"+num2+"-"+num1+".png";
    runPath = QCoreApplication::applicationDirPath();       //获取exe路径
    hglpName = "photo";
    hglpPath = QString("%1/%2").arg(runPath).arg(hglpName);
    QPixmap pix = ui->tableView->grab(ui->tableView->viewport()->rect());
    QString astr = QString("%1/%2/%3/").arg(hglpPath).arg(cd).arg(num5);
    QString Filename = QString("%4_%5_%6-%7_qxc").arg(num3).arg(num4).arg(num1).arg(num2);
    isDirExist(astr);
    pix.save(astr+Filename+".png","PNG");
    QSqlQuery qsq;
    qsq.prepare("insert into imgpath(picid,picname,start,gap,cmp) values (?,?,?,?,?)");
    qsq.addBindValue(num2+"-"+num1);
    qsq.addBindValue(astr);
    qsq.addBindValue(pointer2[colored].start);
    qsq.addBindValue(pointer2[colored].gap);
    qsq.addBindValue(pointer2[colored].cmp);
    qsq.exec();
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


void MainWindow::executeSql(QPointF &line,int x,int y)//核心函数之一，必须保留
{
    qDebug()<<x<<y;
    if(x==-1||y==-1)
    {
        return ;
    }
    else{
        line.setX(ui->tableView->columnViewportPosition(y+ADDS)+ui->tableView->columnWidth(y+ADDS)/2.0);
        line.setY(ui->tableView->rowViewportPosition(x)+ui->tableView->rowHeight(x)/2.0);
    }
    //qDebug() <<x<<y<<"pos";
}


bool MainWindow::selected(QSqlDatabase db,int index,int no) //核心函数之一，必须保留
{
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
    QSqlQuery qsq4;
    QString end;
    int cons = real_id[0]%MAXNO - 1;
    int position = 0;
    pos = QString::number(index,10);
    start = QString::number(pointer1[used].start + MAXNO + cons,10);
    end = QString::number(pointer1[used].start + MAXNO + cons - (MAXSIZE+pointer1[used].gap)*pointer1[used].cmp + 2,10);
    id = QString::number(pointer1[used].id,10);
    qDebug()<<start<<end;
    position = used;
    qDebug()<<pos<<"used================================="<<pointer1[used].id;
    QString as1 = "select data1,data2,data3 from realdata1 where pos="+pos+" and id="+id;
    QString as2 = "select data1,data2,data3 from realdata2 where pos="+pos+" and id="+id;
    QSqlQuery qsq6;
    QString as6 = "call listview("+QString::number(pointer1[used].num,10)+","+end+","+start+","+pos+")";
    qsq6.exec(as6);
    qDebug()<<as1;
    changeModel(DataModel);
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
   // qDebug()<<as2;
    qsq1.exec(as1);
    qsq1.first();
    for(int i = 0;i<pointer1[position].cmp;i++)
    {
        int bshop = (MAXSIZE + pointer1[used].gap)*pointer1[used].cmp;
        qDebug()<<getXfromMap(qsq1.value(0).toInt()) - (i+1)*(pointer1[used].gap + MAXSIZE) + bshop;
        qDebug()<<getXfromMap(qsq1.value(1).toInt()) - (i+1)*(pointer1[used].gap + MAXSIZE) + bshop;
        qDebug()<<getXfromMap(qsq1.value(2).toInt()) - (i+1)*(pointer1[used].gap + MAXSIZE) + bshop;
        executeSql(line1[i][0],getXfromMap(qsq1.value(0).toInt()) - (i+1)*(pointer1[used].gap + MAXSIZE) + bshop,getYfromMap(qsq1.value(0).toInt()));
        executeSql(line1[i][1],getXfromMap(qsq1.value(1).toInt()) - (i+1)*(pointer1[used].gap + MAXSIZE) + bshop,getYfromMap(qsq1.value(1).toInt()));
        executeSql(line1[i][2],getXfromMap(qsq1.value(2).toInt()) - (i+1)*(pointer1[used].gap + MAXSIZE) + bshop,getYfromMap(qsq1.value(2).toInt()));
    }
    qsq2.exec(as2);
    qsq2.first();
    for(int i = 0;i<pointer2[position].cmp;i++)
    {
        int bshop = (MAXSIZE + pointer2[used].gap)*pointer1[used].cmp;
        qDebug()<<bshop;
        executeSql(line2[i][0],getXfromMap(qsq2.value(0).toInt()) - (i+1)*(pointer2[used].gap + MAXSIZE) + bshop,getYfromMap(qsq2.value(0).toInt()));
        executeSql(line2[i][1],getXfromMap(qsq2.value(1).toInt()) - (i+1)*(pointer2[used].gap + MAXSIZE) + bshop,getYfromMap(qsq2.value(1).toInt()));
        executeSql(line2[i][2],getXfromMap(qsq2.value(2).toInt()) - (i+1)*(pointer2[used].gap + MAXSIZE) + bshop,getYfromMap(qsq2.value(2).toInt()));
    }
    used = used+1;
    for(int i = 0;i<pointer1[position].cmp;i++)
    {
        for(int j = 0;j<3;j++)
        {
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
    if(b1 == true)
    {
        memset(pointer1,0,sizeof(pointer1));
        memset(pointer2,0,sizeof(pointer2));
        selector(0);
        selected(this->sqlcon->getDB(),0,index1);
        b1 = false;
    }
    else if(b2 == true)
    {
        memset(pointer1,0,sizeof(pointer1));
        memset(pointer2,0,sizeof(pointer2));
        selector(1);
        selected(this->sqlcon->getDB(),1,index1);
        b2 = false;
    }
    else if(b3 == true)
    {
        memset(pointer1,0,sizeof(pointer1));
        memset(pointer2,0,sizeof(pointer2));
        selector(2);
        selected(this->sqlcon->getDB(),2,index1);
        b3 = false;
    }
    else if(b4 == true)
    {
        memset(pointer1,0,sizeof(pointer1));
        memset(pointer2,0,sizeof(pointer2));
        selector(3);
        selected(this->sqlcon->getDB(),3,index1);
        b4 = false;
    }
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
