#ifndef MATRIX_H
#define MATRIX_H

#endif // MATRIX_H


typedef struct Matrixx
{
    int array[1000][4];
    void Matrix() {
        for(int i = 0;i < 1000;i ++)
        {
            for(int j = 0;j < 4;j ++)
            {
                array[i][j] = 0;
            }
        }
    }
}matrix;

typedef struct Point
{
    int ipos;
    int jpos;
    int data;
}point;

typedef struct PointSet {
    point p1;
    point p2;
    point p3;
    int data;
}pset;
