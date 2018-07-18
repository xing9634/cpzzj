#include"corekernel.h"
#include<iostream>
#include "mainwindow.h"
#include"qtableview.h"
using namespace std;
//算法部分
int Drawabler::OneToOne(int num,int start,int gap,int cmp,int pos)
{
    for(int i = 0;i<MAXSIZE-1;i++)
        {
            for(int j = 0;j<MAXSIZE;j++)
            {
                if(is_way(num,start,gap,cmp,1,i,j,3,pos,-1,-1,-1,-1,-1,-1,-1,-1))
                {
                       str1[0] = maper[i][j];
                       str2[0] = maper[3][pos];
                       return 1;
                }
            }
        }
        return -1;
}

int Drawabler::OneToTwo(int num,int start,int gap,int cmp,int pos)
{
    for(int i = 0;i<MAXSIZE-1;i++)
        {
            for(int j = 0;j<MAXSIZE;j++)
            {
                for(int k = 0;k<MAXSIZE-1;k++)
                {
                    for(int m = 0;m<MAXSIZE;m++)
                    {
                        if(i == k&&j==m)
                            continue;
                        if(is_way(num,start,gap,cmp,2,i,j,k,m,3,pos,-1,-1,-1,-1,-1,-1))
                        {
                               str1[0] = maper[i][j];
                               str2[0] = maper[k][m];
                               str2[1] = maper[3][pos];
                               return 1;
                        }
                    }
                }
            }
        }
        return -1;
}


int Drawabler::OneToThree(int num,int start,int gap,int cmp,int pos)
{
    for(int i = 0;i<MAXSIZE-1;i++)
        {
            for(int j = 0;j<MAXSIZE;j++)
            {
                for(int k = 0;k<MAXSIZE-1;k++)
                {
                    for(int m = 0;m<MAXSIZE;m++)
                    {
                        if(i == k&&j==m)
                            continue;
                        for(int n = 0;n<MAXSIZE-1;n++)
                        {
                            for(int o = 0;o<MAXSIZE;o++)
                            {
                                if(i == n&&j== o)
                                    continue;
                                if(k == n&&m == o)
                                    continue;
                                if(is_way(num,start,gap,cmp,3,i,j,k,m,n,o,3,pos,-1,-1,-1,-1))
                                {
                                       str1[0] = maper[i][j];
                                       str2[0] = maper[k][m];
                                       str2[1] = maper[n][o];
                                       str2[2] = maper[3][pos];
                                       return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
}

int Drawabler::TwoToOne(int num,int start,int gap,int cmp,int pos)
{
    for(int i = 0;i<MAXSIZE-1;i++)
        {
            for(int j = 0;j<MAXSIZE;j++)
            {
                for(int k = 0;k<MAXSIZE-1;k++)
                {
                    for(int m = 0;m<MAXSIZE;m++)
                    {
                        if(i == k&&j==m)
                            continue;
                        if(is_way(num,start,gap,cmp,4,i,j,k,m,3,pos,-1,-1,-1,-1,-1,-1))
                        {
                               str1[0] = maper[i][j];
                               str1[1] = maper[k][m];
                               str2[0] = maper[3][pos];
                               return 1;
                        }
                    }
                }
            }
        }
        return -1;
}

int Drawabler::TwoToTwo(int num,int start,int gap,int cmp,int pos)
{
    for(int i = 0;i<MAXSIZE-1;i++)
        {
            for(int j = 0;j<MAXSIZE;j++)
            {
                for(int k = 0;k<MAXSIZE-1;k++)
                {
                    for(int m = 0;m<MAXSIZE;m++)
                    {
                        if(i == k&&j==m)
                            continue;
                        for(int n = 0;n<MAXSIZE-1;n++)
                        {
                            for(int o = 0;o<MAXSIZE;o++)
                            {
                                if(i == n&&j== o)
                                    continue;
                                if(k == n&&m == o)
                                    continue;
                                if(is_way(num,start,gap,cmp,5,i,j,k,m,n,o,3,pos,-1,-1,-1,-1))
                                {
                                       str1[0] = maper[i][j];
                                       str1[1] = maper[k][m];
                                       str2[0] = maper[n][o];
                                       str2[1] = maper[3][pos];
                                       return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
}

int Drawabler::TwoToThree(int num,int start,int gap,int cmp,int pos)
{
    for(int i = 0;i<MAXSIZE-1;i++)
        {
            for(int j = 0;j<MAXSIZE;j++)
            {
                for(int k = 0;k<MAXSIZE-1;k++)
                {
                    for(int m = 0;m<MAXSIZE;m++)
                    {
                        if(i == k&&j==m)
                            continue;
                        for(int n = 0;n<MAXSIZE-1;n++)
                        {
                            for(int o = 0;o<MAXSIZE;o++)
                            {
                                if(i == n&&j== o)
                                    continue;
                                if(k == n&&m == o)
                                    continue;
                                for(int p = 0;p<MAXSIZE-1;p++)
                                {
                                    for(int q = 0;q<MAXSIZE;q++)
                                    {
                                        if(i == p&&j==q)
                                            continue;
                                        if(k == p&&m ==q)
                                            continue;
                                        if(n == p&&o == q)
                                            continue;
                                        if(is_way(num,start,gap,cmp,6,i,j,k,m,n,o,p,q,3,pos,-1,-1))
                                        {
                                               str1[0] = maper[i][j];
                                               str1[1] = maper[k][m];
                                               str2[0] = maper[n][o];
                                               str2[1] = maper[p][q];
                                               str2[2] = maper[3][pos];
                                               return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
}

int Drawabler::ThreeToOne(int num,int start,int gap,int cmp,int pos)
{
   for(int i = 0;i<MAXSIZE-1;i++)
        {
            for(int j = 0;j<MAXSIZE;j++)
            {
                for(int k = 0;k<MAXSIZE-1;k++)
                {
                    for(int m = 0;m<MAXSIZE;m++)
                    {
                        if(i == k&&j==m)
                            continue;
                        for(int n = 0;n<MAXSIZE-1;n++)
                        {
                            for(int o = 0;o<MAXSIZE;o++)
                            {
                                if(i == n&&j== o)
                                    continue;
                                if(k == n&&m == o)
                                    continue;
                                if(is_way(num,start,gap,cmp,7,i,j,k,m,n,o,3,pos,-1,-1,-1,-1))
                                {
                                       str1[0] = maper[i][j];
                                       str1[1] = maper[k][m];
                                       str1[2] = maper[n][o];
                                       str2[0] = maper[3][pos];
                                       return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
}

int Drawabler::ThreeToTwo(int num,int start,int gap,int cmp,int pos)
{
    for(int i = 0;i<MAXSIZE-1;i++)
        {
            for(int j = 0;j<MAXSIZE;j++)
            {
                for(int k = 0;k<MAXSIZE-1;k++)
                {
                    for(int m = 0;m<MAXSIZE;m++)
                    {
                        if(i == k&&j==m)
                            continue;
                        for(int n = 0;n<MAXSIZE-1;n++)
                        {
                            for(int o = 0;o<MAXSIZE;o++)
                            {
                                if(i == n&&j== o)
                                    continue;
                                if(k == n&&m == o)
                                    continue;
                                for(int p = 0;p<MAXSIZE-1;p++)
                                {
                                    for(int q = 0;q<MAXSIZE;q++)
                                    {
                                        if(i == p&&j==q)
                                            continue;
                                        if(k == p&&m ==q)
                                            continue;
                                        if(n == p&&o == q)
                                            continue;
                                        if(is_way(num,start,gap,cmp,8,i,j,k,m,n,o,p,q,3,pos,-1,-1))
                                        {
                                               str1[0] = maper[i][j];
                                               str1[1] = maper[k][m];
                                               str1[2] = maper[n][o];
                                               str2[0] = maper[p][q];
                                               str2[1] = maper[3][pos];
                                               return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
}


int Drawabler::ThreeToThree(int num,int start,int gap,int cmp,int pos)
{
    for(int i = 0;i<MAXSIZE-1;i++)
        {
            for(int j = 0;j<MAXSIZE;j++)
            {
                for(int k = 0;k<MAXSIZE-1;k++)
                {
                    for(int m = 0;m<MAXSIZE;m++)
                    {
                        if(i == k&&j==m)
                            continue;
                        for(int n = 0;n<MAXSIZE-1;n++)
                        {
                            for(int o = 0;o<MAXSIZE;o++)
                            {
                                if(i == n&&j== o)
                                    continue;
                                if(k == n&&m == o)
                                    continue;
                                for(int p = 0;p<MAXSIZE-1;p++)
                                {
                                    for(int q = 0;q<MAXSIZE;q++)
                                    {
                                        if(i == p&&j==q)
                                            continue;
                                        if(k == p&&m ==q)
                                            continue;
                                        if(n == p&&o == q)
                                            continue;
                                        for(int r = 0;r<MAXSIZE-1;r++)
                                        {
                                            for(int s = 0;s<MAXSIZE;s++)
                                            {
                                                if(i == r&&j==s)
                                                    continue;
                                                if(k == r&&m ==s)
                                                    continue;
                                                if(n == r&&o == s)
                                                    continue;
                                                if(p == r&&q==s)
                                                    continue;
                                                if(is_way(num,start,gap,cmp,9,i,j,k,m,n,o,p,q,r,s,3,pos))
                                                {
                                                       str1[0] = maper[i][j];
                                                       str1[1] = maper[k][m];
                                                       str1[2] = maper[n][o];
                                                       str2[0] = maper[p][q];
                                                       str2[1] = maper[r][s];
                                                       str2[2] = maper[3][pos];
                                                       return 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
}

bool Drawabler::save(QSqlDatabase db, int *str1, int *str2, int num, int gap,int cmp,int pos,int start)
{
    if(!db.open())
        return false;
    QSqlQuery qsq;
    qsq.prepare("insert into realdata1(num,data1,data2,data3,gap,cmp,pos,start) values (?,?,?,?,?,?,?,?)");
    qsq.addBindValue(num);
    qsq.addBindValue(str1[0]);
    qsq.addBindValue(str1[1]);
    qsq.addBindValue(str1[2]);
    qsq.addBindValue(gap);
    qsq.addBindValue(cmp);
    qsq.addBindValue(pos);
    qsq.addBindValue(start);
    qsq.exec();
    QSqlQuery qsq1;
    qsq1.prepare("insert into realdata2(num,data1,data2,data3,gap,cmp,pos,start) values (?,?,?,?,?,?,?,?)");
    qsq1.addBindValue(num);
    qsq1.addBindValue(str2[0]);
    qsq1.addBindValue(str2[1]);
    qsq1.addBindValue(str2[2]);
    qsq1.addBindValue(gap);
    qsq1.addBindValue(cmp);
    qsq1.addBindValue(pos);
    qsq1.addBindValue(start);
    qsq1.exec();
    return true;
}

bool Drawabler::is_way(int num,int start,int gap,int cmp,int mode,int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy,int ex,int ey,int fx,int fy)
{
    int add = MAXSIZE;
    int a = -3;
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    int n4 = 0;
    int n5 = 0;
    int n6 = 0;
    int n7 = 0;
    int n8 = 0;
    int n9 =0;
    bool o1 = mat1.array[ax +  start - MAXSIZE+1][ay] == num;
    bool o2 = mat1.array[ax +  start - MAXSIZE+1][ay] == (10+num + mat1.array[bx +  start - MAXSIZE+1][by])%10;
    bool o3 = mat1.array[ax +  start - MAXSIZE+1][ay] == (10+num + mat1.array[bx +  start - MAXSIZE+1][by]+mat1.array[cx +  start - MAXSIZE+1][cy])%10;
    bool o4 = (mat1.array[ax +  start - MAXSIZE+1][ay] + mat1.array[bx +  start - MAXSIZE+1][by] + 10)%10== num;
    bool o5 = (mat1.array[ax +  start - MAXSIZE+1][ay] + mat1.array[bx +  start - MAXSIZE+1][by] + 10)%10 == (10+num + mat1.array[cx +  start - MAXSIZE+1][cy])%10;
    bool o6 = (mat1.array[ax +  start - MAXSIZE+1][ay] + mat1.array[bx +  start - MAXSIZE+1][by] + 10)%10 == (10+num + mat1.array[cx +  start - MAXSIZE+1][cy]+mat1.array[dx +  start - MAXSIZE+1][dy])%10;
    bool o7 = (mat1.array[ax + start - MAXSIZE+1][ay] + mat1.array[bx +  start - MAXSIZE+1][by] +mat1.array[cx +  start - MAXSIZE+1][cy]+ 10)%10 == num;
    bool o8 = (mat1.array[ax +  start - MAXSIZE+1][ay] + mat1.array[bx +  start - MAXSIZE+1][by] +mat1.array[cx +  start - MAXSIZE+1][cy]+ 10)%10 == (num + 10 + mat1.array[dx +  start - MAXSIZE+1][dy])%10;
    bool o9 = (mat1.array[ax +  start - MAXSIZE+1][ay] + mat1.array[bx +  start - MAXSIZE+1][by] +mat1.array[cx +  start - MAXSIZE+1][cy]+ 10)%10 == (num + 10 + mat1.array[dx +  start - MAXSIZE+1][dy] + mat1.array[ex +  start - MAXSIZE+1][ey])%10;
    for(int i = 1;i<cmp;i++)
    {
        if(mode == 1&&o1)
        {
            if(ax + start - (add+gap)*(i)+a<0||bx + start - (add+gap)*(i) +a<0)
                return false;
            bool ok1 = mat1.array[ax + start - (add+gap)*i +a ][ay] == mat1.array[bx + start - (add+gap)*i+a][by];
            bool ok2 = mat1.array[ax + start - (add+gap)*(i+1)][ay] == mat1.array[bx + start - (add+gap)*(i+1)+a][by];
            if(!ok1||!ok2)
                return false;
            if(ok1&&ok2)
            {
                 n1++;
            }
            if(n1==cmp-1&&i==cmp-1)
            {
                return true;
            }
        }
        if(mode == 4&&o4)
        {
            if(ax + start - (add+gap)*(i)+a<0||bx + start - (add+gap)*(i)+a<0||cx + start - (add+gap)*(i)+a<0)
                return false;
            bool ok1 = (mat1.array[ax + start - (gap+add)*i+a][ay] +mat1.array[bx + start - (gap+add)*i+a][by] + 10)%10 == mat1.array[cx + start - (gap+add)*i+a ][cy];
            bool ok2 = (mat1.array[ax + start - (gap+add)*(i+1)+a][ay] +mat1.array[bx + start - (gap+add)*(i+1)+a][by] + 10)%10 == mat1.array[cx + start - (gap+add)*(i+1)+a ][cy];
            if(!ok1||!ok2)
                return false;
            if(ok1&&ok2)
            {
                 n4++;
            }
            if(n4==cmp-1&&i==cmp-1)
            {
                return true;
            }
        }
        if(mode == 7&&o7)
        {
            if(ax + start - (add+gap)*(i)+a <0||bx + start - (add+gap)*(i)+a<0||cx + start - (add+gap)*(i)+a<0||dx + start - (MAXSIZE+gap)*(i) +a<0)
                return false;
            bool ok1 = (mat1.array[ax + start - (add+gap)*i +a][ay] +mat1.array[bx + start - (add+gap)*i+a ][by] + mat1.array[cx + start - (add+gap)*i +a][cy] + 10)%10== mat1.array[dx + start - (add+gap)*i+a ][dy];
            bool ok2 =  (mat1.array[ax + start - (add+gap)*(i+1)+a][ay] +mat1.array[bx + start - (add+gap)*(i+1)+a ][by] + mat1.array[cx + start - (add+gap)*(i+1)+a][cy] + 10)%10== mat1.array[dx + start - (add+gap)*(i+1)+a][dy];
            if(!ok1||!ok2)
                return false;
            if(ok1&&ok2)
            {
                 n7++;
            }
            if(n7==cmp-1&&i==cmp-1)
            {
                return true;
            }
        }
        if(mode == 2&&o2)
        {
            if(ax + start - (add+gap)*(i)+a<0||bx + start - (add+gap)*(i)+a <0||cx + start - (add+gap)*(i)+a <0)
                return false;
            bool ok1 = mat1.array[ax + start - (add+gap)*i +a][ay] == (10+mat1.array[bx + start - (add+gap)*i + a][by] + mat1.array[cx + start - (MAXSIZE+gap)*i +a][cy])%10;
            bool ok2 = mat1.array[ax + start - (add+gap)*(i+1) +a][ay] == (10+mat1.array[bx + start - (add+gap)*(i+1) + a][by] + mat1.array[cx - start + (MAXSIZE+gap)*(i+1) +a][cy])%10;
            if(!ok1||!ok2)
                return false;
            if(ok1&&ok2)
            {
                 n2++;
            }
            if(n2==cmp-1&&i==cmp-1)
            {
                return true;
            }
        }
        if(mode == 5&&o5)
        {
            if(ax + start - (add+gap)*(i)+a<0||bx + start - (add+gap)*(i)+a <0||cx + start - (MAXSIZE+gap)*(i)+a<0||dx + start - (MAXSIZE+gap)*(i)+a<0)
               return false;
            bool ok1 = (mat1.array[ax + start - (add+gap)*i+a][ay] +mat1.array[bx + start - (add+gap)*i+a][by] + 10)%10 == (mat1.array[cx + start - (MAXSIZE+gap)*i+a][cy] +mat1.array[dx + start - (add+gap)*i+a][dy] + 10)%10;
            bool ok2 = (mat1.array[ax + start - (add+gap)*(i+1)+a][ay] +mat1.array[bx + start - (add+gap)*(i+1)+a][by] + 10)%10 == (mat1.array[cx + start - (MAXSIZE+gap)*(i+1)+a][cy] +mat1.array[dx + start - (add+gap)*(i+1)+a][dy] + 10)%10;
            if(!ok1||!ok2)
                return false;
            if(ok1&&ok2)
            {
                 n5++;
            }
            if(n5==cmp-1&&i==cmp-1)
            {
                return true;
            }
        }
        if(mode == 8&&o8)
        {
            if(ax + start - (add+gap)*(i)+a<0||bx + start - (add+gap)*(i)+a<0||cx + start - (add+gap)*(i)+a <0||dx + start - (add+gap)*(i)+a<0||ex + start - (add+gap)*(i)+a<0)
               return false;
            bool ok1 = (10 + mat1.array[ax + start - (add+gap)*i+a][ay] + mat1.array[bx + start - (add+gap)*i+a][by] + mat1.array[cx + start - (add+gap)*i+a][cy])%10 == (mat1.array[dx + start - (add+gap)*i+a ][dy] + 10 + mat1.array[ex + start - (add+gap)*i +a][ey])%10;
            bool ok2 = (mat1.array[ax + start - (add+gap)*(i+1)+a][ay] + 10+mat1.array[bx + start - (add+gap)*(i+1)+a][by]+ mat1.array[cx + start - (add+gap)*(i+1)+a][cy])%10 == (mat1.array[dx + start - (add+gap)*(i+1) +a][dy] + 10 + mat1.array[ex + start - (add+gap)*(i+1)+a ][ey])%10;
            if(!ok1||!ok2)
                return false;
            if(ok1&&ok2)
            {
                 n8++;
            }
            if(n8==cmp-1&&i==cmp-1)
            {
                return true;
            }
        }
        if(mode == 3&&o3)
        {
            if(ax + start - (add+gap)*(i)+a<0||bx + start - (add+gap)*(i) +a<0||cx + start - (add+gap)*(i)+a <0||dx + start - (add+gap)*(i)+a <0)
                return false;
            bool ok1 = mat1.array[ax + start - (add+gap)*i+a][ay] == (mat1.array[bx + start - (add+gap)*i+a ][by] + mat1.array[cx + start - (add+gap)*i+a][cy] + mat1.array[dx + start - (add+gap)*i+a][dy]+10)%10;
            bool ok2 = mat1.array[ax + start - (add+gap)*(i+1)+a][ay] ==( mat1.array[bx + start - (add+gap)*(i+1)+a][by] + mat1.array[cx + start - (add+gap)*(i+1)+a ][cy] == mat1.array[dx + start - (add+gap)*(i+1) +a][dy]+10)%10;
            if(!ok1||!ok2)
                return false;
            if(ok1&&ok2)
            {
                 n3++;
            }
            if(n3==cmp-1&&i==cmp-1)
            {
                return true;
            }
        }
        if(mode == 6&&o6)
        {
            if(ax + start - (add+gap)*(i) +a<0||bx + start - (add+gap)*(i)+a<0||cx + start - (add+gap)*(i)+a<0||dx + start - (add+gap)*(i) +a<0||ex + start - (add+gap)*(i)+a<0)
                return false;
            bool ok1 = (10 + mat1.array[ax + start - (add+gap)*i+a][ay] + mat1.array[bx + start - (add+gap)*i+a][by] )%10 == (mat1.array[cx + start - (add+gap)*i+a][cy] + mat1.array[dx + start - (add+gap)*i+a][dy] + 10 + mat1.array[ex + start - (add+gap)*i +a][ey])%10;
            bool ok2 = (mat1.array[ax + start - (add+gap)*(i+1)+a][ay] + 10+mat1.array[bx + start - (add+gap)*(i+1)+a ][by])%10==( mat1.array[cx + start - (add+gap)*(i+1) +a][cy] + mat1.array[dx + start - (add+gap)*(i+1)+a][dy] + 10 + mat1.array[ex + start - (add+gap)*(i+1)+a ][ey])%10;
            if(!ok1||!ok2)
                return false;
            if(ok1&&ok2)
            {
                 n6++;
            }
            if(n6==cmp-1&&i==cmp-1)
            {
                return true;
            }
        }
        if(mode == 9&&o9)
        {
            if(ax + start - (add+gap)*(i) +a<0||bx + start - (add+gap)*(i)+a<0||cx + start - (add+gap)*(i)+a <0||dx + start - (add+gap)*(i) +a<0||ex + start - (add+gap)*(i)+a <0||fx + start - (add+gap)*(i)+a <0)
                return false;
            bool ok1 = (10 + mat1.array[ax + start - (add+gap)*i +a][ay] + mat1.array[bx + start - (add+gap)*i+a ][by] + mat1.array[cx + start - (add+gap)*i +a][cy])%10 ==( mat1.array[dx + start - (add+gap)*i+a][dy] + 10 + mat1.array[ex + start - (add+gap)*i+a][ey] + mat1.array[fx + start - (add+gap)*i+a ][fy])%10;
            bool ok2 = (mat1.array[ax + start - (add+gap)*(i+1) +a][ay] + 10+mat1.array[bx+start - (add+gap)*(i+1)+a ][by]+  mat1.array[cx + start - (add+gap)*(i+1) +a][cy])%10 == ( mat1.array[dx + start - (add+gap)*(i+1)+a ][dy]+ 10+ mat1.array[ex + start - (add+gap)*(i+1)+a ][ey]+mat1.array[fx + start - (add+gap)*(i+1)+a ][fy])%10;
            if(!ok1||!ok2)
                return false;
            if(ok1&&ok2)
            {
                 n9++;
            }
            if(n9==cmp-1&&i==cmp-1)
            {
                return true;
            }
        }
    }
    return false;
}


void Drawabler::Find(QSqlDatabase db,int gap,int cmp,int start)
{
    for(int i = 0;i<9;i++)
    {
        for(int j = 0;j<MAXSIZE;j++)
        {
            qDebug()<<i<<endl;
            if(OneToOne(i,start,gap,cmp,j) == 1)
            {
                save(db,str1,str2,i,gap,cmp,j,start);
                memset(str1,-1,sizeof(str1));
                memset(str2,-1,sizeof(str2));
            }
            if(OneToThree(i,start,gap,cmp,j) == 1)
            {
                save(db,str1,str2,i,gap,cmp,j,start);
                memset(str1,-1,sizeof(str1));
                memset(str2,-1,sizeof(str2));
            }
            if(OneToTwo(i,start,gap,cmp,j) == 1)
            {
                save(db,str1,str2,i,gap,cmp,j,start);
                memset(str1,-1,sizeof(str1));
                memset(str2,-1,sizeof(str2));
            }
            if(TwoToOne(i,start,gap,cmp,j) == 1)
            {
                save(db,str1,str2,i,gap,cmp,j,start);
                memset(str1,-1,sizeof(str1));
                memset(str2,-1,sizeof(str2));
            }
            if(TwoToTwo(i,start,gap,cmp,j) == 1)
            {
                save(db,str1,str2,i,gap,cmp,j,start);
                memset(str1,-1,sizeof(str1));
                memset(str2,-1,sizeof(str2));
            }
            if(TwoToThree(i,start,gap,cmp,j) == 1)
            {
                save(db,str1,str2,i,gap,cmp,j,start);
                memset(str1,-1,sizeof(str1));
                memset(str2,-1,sizeof(str2));
            }
            if(ThreeToOne(i,start,gap,cmp,j) == 1)
            {
                save(db,str1,str2,i,gap,cmp,j,start);
                memset(str1,-1,sizeof(str1));
                memset(str2,-1,sizeof(str2));
            }
            if(ThreeToTwo(i,start,gap,cmp,j) == 1)
            {
                save(db,str1,str2,i,gap,cmp,j,start);
                memset(str1,-1,sizeof(str1));
                memset(str2,-1,sizeof(str2));
            }
            if(ThreeToThree(i,start,gap,cmp,j) == 1)
            {
                save(db,str1,str2,i,gap,cmp,j,start);
                memset(str1,-1,sizeof(str1));
                memset(str2,-1,sizeof(str2));
            }
        }
    }
}
