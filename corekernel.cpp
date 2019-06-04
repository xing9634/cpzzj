#include<iostream>
#include "mainwindow.h"
#include"qtableview.h"
#include<string.h>
using namespace std;
#define DRAGON start - (MAXSIZE + gap) * cmp - 3
#define DRAGON2 start - (MAXSIZE + gap) * 1 - 3

using namespace std;
//算法部分

void Drawabler::make_mat(int col,matrix matb) {
    for(int i = col;i < MAXSIZE + col;i ++) {
        for(int j = 0;j < MAXSIZE;j ++) {
            mat1.array[i - col][j] = matb.array[i][j];
            qDebug()<<matb.array[i][j];
        }
        qDebug()<<" ";
    }
    qDebug()<<"cykablabnskldhnakosjdioasjdklasjdoksajdklasjdklasjdklasjdklasjdklsajlkdsajkldjaskldjsakldajskld";
}
void Drawabler::make_matfirst(int col,matrix matb) {
    for(int i = col;i < MAXSIZE - 1 + col;i ++) {
        for(int j = 0;j < MAXSIZE;j ++) {
            mat1.array[i - col][j] = matb.array[i][j];
        }
    }
}

int Drawabler::maptoi(int num){
    int k = 1;
    for(int i = 0;i <4;i++ ){
        for(int j = 0;j <4;j ++) {
            if(k == num) {
                return i;
            }
            k ++;
        }
    }
    return -1;
}

int Drawabler::maptoj(int num){
    int k = 1;
    for(int i = 0;i <4;i++ ){
        for(int j = 0;j <4;j ++) {
            if(k == num) {
                return j;
            }
            k ++;
        }
    }
    return -1;
}


bool Drawabler::Find(QSqlDatabase db,int gap,int start,matrix matb,int mode) {
    int cmp = 2;
    for(int i = 0;i <= 9;i ++) {
        memset(this->str1,-1,sizeof(this->str1));
        memset(this->str2,-1,sizeof(this->str2));
        for(int j = 1;j <= 12; j++) { //1:1
            make_matfirst(start - 3,matb);
            int ti = maptoi(j);
            int tj = maptoj(j);
            bool o1 = i == mat1.array[ti][tj];
            for(int k = 0;k < 4;k ++) {
                make_mat(DRAGON2,matb);
                if(o1 && mat1.array[ti][tj] == mat1.array[3][k]){
                    while(DRAGON >= 0) {
                        qDebug()<<"|csacasca";
                        make_mat(DRAGON,matb);
                        if(mat1.array[ti][tj] == mat1.array[3][k])
                        {

                            cmp++;
                        } else {
                            break;
                        }
                    }
                    str1[0] = k + 13;
                    str1[1] = -1;
                    str1[2] = -1;
                    str2[0] = j;
                    str2[1] = -1;
                    str2[2] = -1;
                    save(db,str1,str2,i,gap,cmp,k,start,mode);
                }
                cmp = 2;

            }
        }
        cmp = 2;
        for(int j = 1;j <= 12; j++) { //1:2 and 2:1

            for(int ks = j;ks <= 12; ks++) {
                make_matfirst(start - 3,matb);
                int ji = maptoi(j);
                int jj = maptoj(j);
                int ki = maptoi(ks);
                int kj = maptoj(ks);
                if(ks == j) continue ;
                bool o1 = i == (mat1.array[ji][jj] + mat1.array[ki][kj] + 10) % 10 ;
                bool o2 = (i + mat1.array[ki][kj] + 10) % 10 == (mat1.array[ji][jj] + 10) % 10 ;
                for(int k = 0;k < 4;k ++) {
                    make_mat(DRAGON2,matb);
                    if(o1 && (mat1.array[ji][jj] + mat1.array[ki][kj] + 10) % 10  == mat1.array[3][k]) {

                        while(DRAGON >= 0) {
                            make_mat(DRAGON,matb);
                            if((mat1.array[ji][jj] + mat1.array[ki][kj] + 10) % 10  == mat1.array[3][k])
                            {

                                cmp++;
                            } else {
                                break;
                            }
                        }
                        str1[0] = k + 13;
                        str1[1] = -1;
                        str1[2] = -1;
                        str2[0] = ks;
                        str2[1] = j;
                        str2[2] = -1;
                        save(db,str1,str2,i,gap,cmp,k,start,mode);
                    }
                    cmp = 2;

                    if(o2 && (mat1.array[3][k] + mat1.array[ki][kj] + 10) % 10  == mat1.array[ji][jj]) {
                        while(DRAGON >= 0) {
                            make_mat(DRAGON,matb);
                            if((mat1.array[3][k] + mat1.array[ki][kj] + 10) % 10  == mat1.array[ji][jj])
                            {

                                cmp++;
                            }else {
                                break;
                            }
                        }
                        str1[0] = k + 13;
                        str1[1] = ks;
                        str1[2] = -1;
                        str2[0] = j;
                        str2[1] = -1;
                        str2[2] = -1;
                        save(db,str1,str2,i,gap,cmp,k,start,mode);
                    }
                    cmp = 2;

                }
            }
        }
        cmp = 2;
        for(int j = 1;j <= 12; j++) { //3:1 and 1:3 2:2

            for(int ks = j;ks <= 12; ks++) {
                for(int ps = ks;ps <= 12; ps ++) {
                    make_matfirst(start - 3,matb);
                    int ji = maptoi(j);
                    int jj = maptoj(j);
                    int ki = maptoi(ks);
                    int kj = maptoj(ks);
                    int pi = maptoi(ps);
                    int pj = maptoj(ps);
                    if(ks == j) continue ;
                    if(ks == ps) continue ;
                    if(ps == j) continue ;
                    bool o1 = i == (mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj] + 10) % 10;
                    bool o2 = (i + mat1.array[pi][pj] + 10) % 10 == (mat1.array[ji][jj] + mat1.array[ki][kj] + 10) % 10 ;
                    bool o3 = (i + mat1.array[ki][kj] + mat1.array[pi][pj] + 10) % 10== (mat1.array[ji][jj] + 10) % 10 ;
                    for(int k = 0;k < 4;k ++) {
                        make_mat(DRAGON2,matb);
                        if(o1 && (mat1.array[ji][jj] + mat1.array[ki][kj] +  mat1.array[pi][pj] + 10) % 10  == mat1.array[3][k]) {
                            while(DRAGON >= 0) {
                                make_mat(DRAGON,matb);
                                if((mat1.array[ji][jj] + mat1.array[ki][kj] +  mat1.array[pi][pj] + 10) % 10  == mat1.array[3][k])
                                {

                                    cmp++;
                                }else {
                                    break;
                                }
                            }
                            str1[0] = k + 13;
                            str1[1] = -1;
                            str2[2] = -1;
                            str2[0] = ps;
                            str2[1] = ks;
                            str2[2] = j;
                            save(db,str1,str2,i,gap,cmp,k,start,mode);
                        }
                        cmp = 2;
                        if(o2 && (mat1.array[ji][jj] + mat1.array[ki][kj] + 10) % 10  == (mat1.array[3][k] + mat1.array[pi][pj] + 10) % 10) {
                            while(DRAGON >= 0) {
                                make_mat(DRAGON,matb);
                                if((mat1.array[ji][jj] + mat1.array[ki][kj] + 10) % 10  == (mat1.array[3][k] + mat1.array[pi][pj] + 10) % 10)
                                {

                                    cmp++;
                                }else {
                                    break;
                                }
                            }
                            str1[0] = k + 13;
                            str1[1] = ps;
                            str1[2] = -1;
                            str2[0] = ks;
                            str2[1] = j;
                            str2[2] = -1;
                            save(db,str1,str2,i,gap,cmp,k,start,mode);
                        }
                        cmp = 2;

                        if(o3 && (mat1.array[ji][jj] + 10) % 10  == mat1.array[3][k] + mat1.array[pi][pj] + mat1.array[ki][kj]) {
                            while(DRAGON >= 0) {
                                make_mat(DRAGON,matb);
                                if((mat1.array[ji][jj] + 10) % 10  == (mat1.array[3][k] + mat1.array[pi][pj] + mat1.array[ki][kj] + 10) % 10)
                                {

                                    cmp++;
                                }else {
                                    break;
                                }
                            }
                            str1[0] = k + 13;
                            str1[1] = ps;
                            str1[2] = ks;
                            str2[0] = j;
                            str2[1] = -1;
                            str2[2] = -1;
                            save(db,str1,str2,i,gap,cmp,k,start,mode);
                        }
                        cmp = 2;

                    }
                }
            }
        }
        cmp = 2;
        for(int j = 1;j <= 12; j++) { //3:2 and 2:3

            for(int ks = j;ks <= 12; ks++) {
                for(int ps = ks;ps <= 12; ps ++) {
                    for(int cs = ps;cs <=12;cs ++) {
                        make_matfirst(start - 3,matb);
                        int ji = maptoi(j);
                        int jj = maptoj(j);
                        int ki = maptoi(ks);
                        int kj = maptoj(ks);
                        int pi = maptoi(ps);
                        int pj = maptoj(ps);
                        int ci = maptoi(cs);
                        int cj = maptoj(cs);
                        if(ks == j) continue ;
                        if(ks == ps) continue ;
                        if(ps == j) continue ;
                        if(ps == cs) continue;
                        if(ks == cs) continue;
                        if(j == cs) continue;
                        bool o1 = ( i + mat1.array[ci][cj] + 10 ) % 10== (mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj] +10) % 10 ;
                        bool o2 = ( i + mat1.array[pi][pj] + mat1.array[ci][cj] + 10 ) % 10== (mat1.array[ji][jj] + mat1.array[ki][kj] +10) % 10 ;
                        for(int k = 0;k < 4;k ++) {
                            make_mat(DRAGON2,matb);
                            if(o1 && (mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj] +10) % 10 == (mat1.array[3][k] + mat1.array[ci][cj] + 10 ) % 10){
                                while(DRAGON >= 0) {
                                    make_mat(DRAGON,matb);
                                    if((mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj] +10) % 10 == (mat1.array[3][k] + mat1.array[ci][cj] + 10 ) % 10)
                                    {

                                        cmp++;
                                    }else {
                                        break;
                                    }
                                }
                                str1[0] = k + 13;
                                str1[1] = cs;
                                str1[2] = -1;
                                str2[0] = ps;
                                str2[1] = ks;
                                str2[2] = j;
                                save(db,str1,str2,i,gap,cmp,k,start,mode);
                            }
                            cmp = 2;

                            if(o2 && (mat1.array[ji][jj] + mat1.array[ki][kj] +10) % 10 == (mat1.array[3][k] + mat1.array[ci][cj] + 10 +  mat1.array[pi][pj] ) % 10){
                                while(DRAGON >= 0) {
                                    make_mat(DRAGON,matb);
                                    if((mat1.array[ji][jj] + mat1.array[ki][kj] +10) % 10 == (mat1.array[3][k] + mat1.array[ci][cj] + 10 + mat1.array[pi][pj] ) % 10)
                                    {

                                        cmp++;
                                    }else {
                                        break;
                                    }
                                }
                                str1[0] = k + 13;
                                str1[1] = cs;
                                str1[2] = ps;
                                str2[0] = ks;
                                str2[1] = j;
                                str2[2] = -1;
                                save(db,str1,str2,i,gap,cmp,k,start,mode);
                            }
                            cmp = 2;
                        }
                    }
                }
            }
        }
        for(int j = 1;j <= 12; j++) { //3:3
            for(int ks = j;ks <= 12; ks++) {
                for(int ps = ks;ps <= 12; ps ++) {
                    for(int cs = ps;cs <=12;cs ++) {
                        for(int qs = cs;qs <= 12; qs ++) {
                            make_matfirst(start - 3,matb);
                            int ji = maptoi(j);
                            int jj = maptoj(j);
                            int ki = maptoi(ks);
                            int kj = maptoj(ks);
                            int pi = maptoi(ps);
                            int pj = maptoj(ps);
                            int ci = maptoi(cs);
                            int cj = maptoj(cs);
                            int qi = maptoi(qs);
                            int qj = maptoj(qs);
                            if(ks == j) continue ;
                            if(ks == ps) continue ;
                            if(ps == j) continue ;
                            if(ps == cs) continue;
                            if(ks == cs) continue;
                            if(j == cs) continue;
                            if(ks == qs) continue;
                            if(ps == qs) continue;
                            if(cs == qs) continue;
                            bool o1 = ( i + mat1.array[ci][cj] + mat1.array[qi][qj]+ 10 ) % 10== (mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj] +10) % 10 ;
                            for(int k = 0;k < 4;k ++) {
                                make_mat(DRAGON2,matb);
                                if(o1 && (mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj] +10) % 10 == (mat1.array[3][k] + mat1.array[ci][cj] + mat1.array[qi][qj] + 10 ) % 10){
                                    while(DRAGON >= 0) {
                                        make_mat(DRAGON,matb);
                                        if((mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj] +10) % 10 == (mat1.array[3][k] + mat1.array[ci][cj] + mat1.array[qi][qj] + 10 ) % 10)
                                        {

                                            cmp++;
                                        }else {
                                            break;
                                        }
                                    }
                                    str1[0] = k + 13;
                                    str1[1] = cs;
                                    str1[2] = qs;
                                    str2[0] = ps;
                                    str2[1] = ks;
                                    str2[2] = j;
                                    save(db,str1,str2,i,gap,cmp,k,start,mode);
                                }
                                cmp = 2;

                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Drawabler::save(QSqlDatabase db, int *str1, int *str2, int num, int gap,int cmp,int pos,int start,int mode)
{
    if(!db.open() || cmp <= 2)
        return false;
    QSqlQuery qsq;
    qsq.prepare("insert into realdata1(num,data1,data2,data3,gap,cmp,pos,start,mode,kind) values (?,?,?,?,?,?,?,?,?,?)");
    qsq.addBindValue(num);
    qsq.addBindValue(this->str1[0]);
    qsq.addBindValue(this->str1[1]);
    qsq.addBindValue(this->str1[2]);
    qsq.addBindValue(gap);
    qsq.addBindValue(cmp);
    qsq.addBindValue(pos+mode);
    qsq.addBindValue(this->re_start);
    qsq.addBindValue(mode);
    qsq.addBindValue(kind);
    qsq.exec();
    qDebug()<<qsq.lastError();
    QSqlQuery qsq1;
    qsq1.prepare("insert into realdata2(num,data1,data2,data3,gap,cmp,pos,start,mode,kind) values (?,?,?,?,?,?,?,?,?,?)");
    qsq1.addBindValue(num);
    qsq1.addBindValue(this->str2[0]);
    qsq1.addBindValue(this->str2[1]);
    qsq1.addBindValue(this->str2[2]);
    qsq1.addBindValue(gap);
    qsq1.addBindValue(cmp);
    qsq1.addBindValue(pos+mode);
    qsq1.addBindValue(this->re_start);
    qsq1.addBindValue(mode);
    qsq1.addBindValue(kind);
    qsq1.exec();
    qDebug()<<qsq1.lastError();
    memset(this->str1,-1,sizeof(this->str1));
    memset(this->str2,-1,sizeof(this->str2));
    return true;
}


