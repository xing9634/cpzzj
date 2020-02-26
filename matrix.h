#ifndef MATRIX_H
#define MATRIX_H
#include"qtableview.h"

#endif // MATRIX_H

class matrix {
public:
    int array[400][5];
    matrix() {
        for(int i = 0;i < 400;i ++)
        {
            for(int j = 0;j < 5;j ++)
            {
                array[i][j] = 0;
            }
        }
    }
};
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
