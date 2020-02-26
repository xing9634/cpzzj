#include<iostream>
#include "corekernel.h"
#include"qtableview.h"
#include<string.h>


#define DRAGON start - (4 + gap) * cmp - 3
#define DRAGON2 start - (4 + gap) * 1 - 3

using namespace std;
//算法部分

void Drawabler::make_mat(int col,int mode) {
    for(int i = col;i < 4 + col;i ++) {
        for(int j = 0;j < MAXSIZE;j ++) {
            mat1.array[i - col][j] = matA[mode].array[i][j];
            qDebug()<<mat1.array[i - col][j];
        }
        qDebug()<<" ";
    }
    qDebug()<<"cykablabnskldhnakosjdioasjdklasjdoksajdklasjdklasjdklasjdklasjdklsajlkdsajkldjaskldjsakldajskld";
}
void Drawabler::make_matfirst(int col,int mode) {
    for(int i = col;i < 4 - 1 + col;i ++) {
        for(int j = 0;j < MAXSIZE;j ++) {
            mat1.array[i - col][j] = matA[mode].array[i][j];
        }
    }
}

int Drawabler::maptoi(int num){
    int k = 1;
    for(int i = 0;i <4;i++ ){
        for(int j = 0;j <MAXSIZE;j ++) {
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
        for(int j = 0;j < MAXSIZE;j ++) {
            if(k == num) {
                return j;
            }
            k ++;
        }
    }
    return -1;
}


bool Drawabler::Find(QSqlDatabase db,int gap,int start,matrix matb,int mode,int dec) {
    int cmp = 1;
    for(int i = 0;i <= dec - 1;i ++) {
        memset(this->str1,-1,sizeof(this->str1));
        memset(this->str2,-1,sizeof(this->str2));
        for(int j = 1;j <= MAXSIZE * 3; j++) { //1:1
            make_matfirst(start - 3,mode);
            int ti = maptoi(j);
            int tj = maptoj(j);
            bool o1 = i == mat1.array[ti][tj];
            for(int k = 0;k < MAXSIZE;k ++) {
                make_mat(DRAGON2,mode);
                if(o1 && mat1.array[ti][tj] == mat1.array[3][k]){
                    while(DRAGON >= 0) {
                        qDebug()<<"|csacasca";
                        make_mat(DRAGON,mode);
                        if(mat1.array[ti][tj] == mat1.array[3][k])
                        {

                            cmp++;
                        } else {
                            break;
                        }
                    }
                    str1[0] = k + MAXSIZE * 3 + 1;
                    str1[1] = -1;
                    str1[2] = -1;
                    str2[0] = j;
                    str2[1] = -1;
                    str2[2] = -1;
                    save(db,str1,str2,i,gap,cmp,k,start,mode);
                }
                cmp = 1;

            }
        }
        cmp = 1;
        for(int j = 1;j <= MAXSIZE * 3; j++) { //1:2 and 2:1

            for(int ks = j;ks <= MAXSIZE * 3; ks++) {
                make_matfirst(start - 3,mode);
                int ji = maptoi(j);
                int jj = maptoj(j);
                int ki = maptoi(ks);
                int kj = maptoj(ks);
                if(ks == j) continue ;
                bool o1 = i  == (mat1.array[ji][jj] + mat1.array[ki][kj] ) % dec ;
                bool o2 = (i + mat1.array[ki][kj] ) % dec == mat1.array[ji][jj]  ;
                for(int k = 0;k < MAXSIZE;k ++) {
                    make_mat(DRAGON2,mode);
                    if(o1 && (mat1.array[ji][jj] + mat1.array[ki][kj] ) % dec  ==  mat1.array[3][k])   {

                        while(DRAGON >= 0) {
                            make_mat(DRAGON,mode);
                            if((mat1.array[ji][jj] + mat1.array[ki][kj]  ) % dec  ==  mat1.array[3][k] )
                            {

                                cmp++;
                            } else {
                                break;
                            }
                        }
                        str1[0] = k + MAXSIZE * 3 + 1;
                        str1[1] = -1;
                        str1[2] = -1;
                        str2[0] = ks;
                        str2[1] = j;
                        str2[2] = -1;
                        save(db,str1,str2,i,gap,cmp,k,start,mode);
                    }
                    cmp = 1;

                    if(o2 && (mat1.array[3][k] + mat1.array[ki][kj] ) % dec  == (mat1.array[ji][jj] )%dec) {
                        while(DRAGON >= 0) {
                            make_mat(DRAGON,mode);
                            if((mat1.array[3][k] + mat1.array[ki][kj]  ) % dec  == (mat1.array[ji][jj] ) % dec)
                            {

                                cmp++;
                            }else {
                                break;
                            }
                        }
                        str1[0] = k + MAXSIZE * 3 + 1;
                        str1[1] = ks;
                        str1[2] = -1;
                        str2[0] = j;
                        str2[1] = -1;
                        str2[2] = -1;
                        save(db,str1,str2,i,gap,cmp,k,start,mode);
                    }
                    cmp = 1;

                }
            }
        }
        cmp = 1;
        for(int j = 1;j <= MAXSIZE * 3; j++) { //3:1 and 1:3 2:2

            for(int ks = j;ks <= MAXSIZE * 3; ks++) {
                for(int ps = ks;ps <= MAXSIZE * 3; ps ++) {
                    make_matfirst(start - 3,mode);
                    int ji = maptoi(j);
                    int jj = maptoj(j);
                    int ki = maptoi(ks);
                    int kj = maptoj(ks);
                    int pi = maptoi(ps);
                    int pj = maptoj(ps);
                    if(ks == j) continue ;
                    if(ks == ps) continue ;
                    if(ps == j) continue ;
                    bool o1 = i   == (mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj] ) % dec;
                    bool o2 = (i + mat1.array[pi][pj] ) % dec == (mat1.array[ji][jj] + mat1.array[ki][kj]  ) % dec ;
                    bool o3 = (i + mat1.array[ki][kj] + mat1.array[pi][pj] ) % dec== (mat1.array[ji][jj] ) % dec ;
                    for(int k = 0;k < MAXSIZE;k ++) {
                        make_mat(DRAGON2,mode);
                        if(o1 && (mat1.array[ji][jj] + mat1.array[ki][kj] +  mat1.array[pi][pj]  ) % dec  == (mat1.array[3][k] ) % dec) {
                            while(DRAGON >= 0) {
                                make_mat(DRAGON,mode);
                                if((mat1.array[ji][jj] + mat1.array[ki][kj] +  mat1.array[pi][pj]  ) % dec  == (mat1.array[3][k] ) % dec)
                                {

                                    cmp++;
                                }else {
                                    break;
                                }
                            }
                            str1[0] = k + MAXSIZE * 3 + 1;
                            str1[1] = -1;
                            str1[2] = -1;
                            str2[0] = ps;
                            str2[1] = ks;
                            str2[2] = j;
                            save(db,str1,str2,i,gap,cmp,k,start,mode);
                        }
                        cmp = 1;
                        if(o2 && (mat1.array[ji][jj] + mat1.array[ki][kj]  ) % dec  == (mat1.array[3][k] + mat1.array[pi][pj]  ) % dec) {
                            while(DRAGON >= 0) {
                                make_mat(DRAGON,mode);
                                if((mat1.array[ji][jj] + mat1.array[ki][kj] ) % dec  == (mat1.array[3][k] + mat1.array[pi][pj]) % dec)
                                {

                                    cmp++;
                                }else {
                                    break;
                                }
                            }
                            str1[0] = k + MAXSIZE * 3 + 1;
                            str1[1] = ps;
                            str1[2] = -1;
                            str2[0] = ks;
                            str2[1] = j;
                            str2[2] = -1;
                            save(db,str1,str2,i,gap,cmp,k,start,mode);
                        }
                        cmp = 1;

                        if(o3 && mat1.array[ji][jj]    == (mat1.array[3][k] + mat1.array[pi][pj] + mat1.array[ki][kj])%dec) {
                            while(DRAGON >= 0) {
                                make_mat(DRAGON,mode);
                                if(mat1.array[ji][jj]    == (mat1.array[3][k] + mat1.array[pi][pj] + mat1.array[ki][kj] ) % dec)
                                {

                                    cmp++;
                                }else {
                                    break;
                                }
                            }
                            str1[0] = k + MAXSIZE * 3 + 1;
                            str1[1] = ps;
                            str1[2] = ks;
                            str2[0] = j;
                            str2[1] = -1;
                            str2[2] = -1;
                            save(db,str1,str2,i,gap,cmp,k,start,mode);
                        }
                        cmp = 1;

                    }
                }
            }
        }
        cmp = 1;
        for(int j = 1;j <= MAXSIZE * 3; j++) { //3:2 and 2:3

            for(int ks = j;ks <= MAXSIZE * 3; ks++) {
                for(int ps = ks;ps <= MAXSIZE * 3; ps ++) {
                    for(int cs = ps;cs <=MAXSIZE * 3;cs ++) {
                        make_matfirst(start - 3,mode);
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
                        bool o1 = ( i + mat1.array[ci][cj]  ) % dec== (mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj]  ) % dec ;
                        bool o2 = ( i + mat1.array[pi][pj] + mat1.array[ci][cj]  ) % dec== (mat1.array[ji][jj] + mat1.array[ki][kj]  ) % dec ;
                        for(int k = 0;k < MAXSIZE;k ++) {
                            make_mat(DRAGON2,mode);
                            if(o1 && (mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj] ) % dec == (mat1.array[3][k] + mat1.array[ci][cj]  ) % dec){
                                while(DRAGON >= 0) {
                                    make_mat(DRAGON,mode);
                                    if((mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj]  ) % dec == (mat1.array[3][k] + mat1.array[ci][cj]  ) % dec)
                                    {

                                        cmp++;
                                    }else {
                                        break;
                                    }
                                }
                                str1[0] = k + MAXSIZE * 3 + 1;
                                str1[1] = cs;
                                str1[2] = -1;
                                str2[0] = ps;
                                str2[1] = ks;
                                str2[2] = j;
                                save(db,str1,str2,i,gap,cmp,k,start,mode);
                            }
                            cmp = 1;

                            if(o2 && (mat1.array[ji][jj] + mat1.array[ki][kj]  ) % dec == (mat1.array[3][k] + mat1.array[ci][cj]  +  mat1.array[pi][pj]  ) % dec){
                                while(DRAGON >= 0) {
                                    make_mat(DRAGON,mode);
                                    if((mat1.array[ji][jj] + mat1.array[ki][kj] ) % dec == (mat1.array[3][k] + mat1.array[ci][cj] + mat1.array[pi][pj]  ) % dec)
                                    {

                                        cmp++;
                                    }else {
                                        break;
                                    }
                                }
                                str1[0] = k + MAXSIZE * 3 + 1;
                                str1[1] = cs;
                                str1[2] = ps;
                                str2[0] = ks;
                                str2[1] = j;
                                str2[2] = -1;
                                save(db,str1,str2,i,gap,cmp,k,start,mode);
                            }
                            cmp = 1;
                        }
                    }
                }
            }
        }
        for(int j = 1;j <= MAXSIZE * 3; j++) { //3:3
            for(int ks = j;ks <= MAXSIZE * 3; ks++) {
                for(int ps = ks;ps <= MAXSIZE * 3; ps ++) {
                    for(int cs = ps;cs <=MAXSIZE * 3;cs ++) {
                        for(int qs = cs;qs <= MAXSIZE * 3; qs ++) {
                            make_matfirst(start - 3,mode);
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
                            bool o1 = ( i + mat1.array[ci][cj] + mat1.array[qi][qj] ) % dec== (mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj] ) % dec ;
                            for(int k = 0;k < MAXSIZE;k ++) {
                                make_mat(DRAGON2,mode);
                                if(o1 && (mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj] ) % dec == (mat1.array[3][k] + mat1.array[ci][cj] + mat1.array[qi][qj]   ) % dec){
                                    while(DRAGON >= 0) {
                                        make_mat(DRAGON,mode);
                                        if((mat1.array[ji][jj] + mat1.array[ki][kj] + mat1.array[pi][pj]  ) % dec == (mat1.array[3][k] + mat1.array[ci][cj] + mat1.array[qi][qj]   ) % dec)
                                        {

                                            cmp++;
                                        }else {
                                            break;
                                        }
                                    }
                                    str1[0] = k + MAXSIZE * 3 + 1;
                                    str1[1] = cs;
                                    str1[2] = qs;
                                    str2[0] = ps;
                                    str2[1] = ks;
                                    str2[2] = j;
                                    save(db,str1,str2,i,gap,cmp,k,start,mode);
                                }
                                cmp = 1;

                            }
                        }
                    }
                }
            }
        }
        emit givesig(knt);
        knt ++;
    }
    emit givesig(knt);
    return false;
}

bool Drawabler::save(QSqlDatabase db, int *str1, int *str2, int num, int gap,int cmp,int pos,int start,int mode)
{
    if(!db.open() || cmp <= 2)
        return false;
    if(kind == "dlt_data" || kind == "ssq_data") {
        if(num == 0) {
            return false;
        }
    }
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

int Drawabler::FindBest(int mode) {
    int k = 0;
    k++;
    int dec = 10;
    qDebug()<<kind<<re_start<<matA[1].array[0][2];
    if(kind == "fc3d_data" || kind == "pl3_data") {
        MAXSIZE = 3;
        dec = 10;
        int k1 = 1;
        for(int i = 0;i<4;i++)
        {
            for(int j = 0;j<3;j++)
            {
                maper[i][j] = k1;
                k1++;
            }
        }
    } else if(kind == "ssq_data") {
        MAXSIZE = 5;
        dec = 33;
        int k1 = 1;
        for(int i = 0;i<4;i++)
        {
            for(int j = 0;j<5;j++)
            {
                maper[i][j] = k1;
                k1++;
            }
        }
    } else if(kind == "dlt_data") {
        MAXSIZE = 5;
        dec = 35;
        int k1 = 1;
        for(int i = 0;i<4;i++)
        {
            for(int j = 0;j<5;j++)
            {
                maper[i][j] = k1;
                k1++;
            }
        }
    } else {
        MAXSIZE = 4;
        dec = 10;
        int k1 = 1;
        for(int i = 0;i<4;i++)
        {
            for(int j = 0;j<4;j++)
            {
                maper[i][j] = k1;
                k1++;
            }
        }
    }
    if(kind == "pl5_data") {
        emit givedec(0,dec * times[0]);
    } else if(kind == "qxc_data") {
        emit givedec(0,dec * times[1]);
    } else if(kind == "fc3d_data") {
        emit givedec(0,dec * times[2]);
    } else if(kind == "ssq_data") {
        emit givedec(0,dec * times[3]);
    } else if(kind == "dlt_data") {
        emit givedec(0,dec * times[4]);
    }
    if(kind == "pl5_data" && mode > 1) {
        return 0;
    } else if(kind == "ssq_data" && mode > 2) {
        return 0;
    } else if(kind == "fc3d_data" && mode > 0) {
        return 0;
    } else if(kind == "dlt_data" && mode > 0) {
        return 0;
    }
    Find(db,0,indexs + 1,matA[mode],mode,dec);

}
