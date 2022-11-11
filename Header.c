#include "matrix.h"
#include<stdio.h>
#include<stdlib.h>
//1
typedef struct m{
    int w, h;
    int** arr;
} matrix;
//2
matrix fill(int w, int h, int item) {
    matrix a;
    a.w = w;
    a.h = h;
    a.arr = (int**)malloc(sizeof(int*) * a.h);
    for (int i = 0; i < a.h; i++) {
        a.arr[i] = (int*)malloc(sizeof(int*) * a.w);
    }
    for (int i = 0; i < a.h; i++) {
        for (int j = 0; j < a.w; j++) {
            a.arr[i][j] = item;
        }
    }
    return a;
}
//3
matrix rand_fill(int w, int h) {
    matrix b;
    b.w = w;
    b.h = h;
    b.arr = (int**)malloc(sizeof(int*) * b.h);
    for (int i = 0; i < b.h; i++) {
        b.arr[i] = (int*)malloc(sizeof(int*) * b.w);
    }
    for (int i = 0; i < b.h; i++) {
        for (int j = 0; j < b.w; j++) {
            b.arr[i][j] = rand() % 10;
        }
    }
    return b;
}
//4.1
matrix mat_sum(matrix a, matrix b) {
    matrix c;
    c.w = a.w;
    c.h = a.h;
    c.arr = (int**)malloc(sizeof(int*) * c.h);
    for (int i = 0; i < c.h; i++) {
        c.arr[i] = (int*)malloc(sizeof(int*) * c.w);
    }
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            c.arr[i][j] = a.arr[i][j] + b.arr[i][j];
        }
    }
    return c;
}
//4.2
matrix mat_sub(matrix a, matrix b) {
    matrix c;
    c.w = a.w;
    c.h = a.h;
    c.arr = (int**)malloc(sizeof(int*) * c.h);
    for (int i = 0; i < c.h; i++) {
        c.arr[i] = (int*)malloc(sizeof(int*) * c.w);
    }
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            c.arr[i][j] = a.arr[i][j] - b.arr[i][j];
        }
    }
    return c;
}
//5.1
matrix mat_multi(matrix a, matrix b) {
    matrix c;
    int flag = 0;
    if (a.w != b.h)flag = 1;
    c.w = a.w;
    c.h = a.h;
    c.arr = (int**)malloc(sizeof(int*) * c.h);
    for (int i = 0; i < c.h; i++) {
        c.arr[i] = (int*)malloc(sizeof(int*) * c.w);
    }
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            c.arr[i][j] = 0;
            for (int k = 0; k < a.h; k++) {
                c.arr[i][j] += a.arr[i][k] * b.arr[k][j];
            }
        }
    }
    if (flag == 1) {
        printf("\nMultiplication is not possible\n\nStraight multiplication:\n\n");
        return c;
    }
    else return c;
}
//6
matrix mat_tran(matrix b) {
    matrix c;
    c.w = b.w;
    c.h = b.h;
    c.arr = (int**)malloc(sizeof(int*) * c.h);
    for (int i = 0; i < c.h; i++) {
        c.arr[i] = (int*)malloc(sizeof(int*) * c.w);
    }
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            c.arr[i][j] = b.arr[j][i];
        }
    }
    return c;
}
//7
void mat_free(matrix c) {
    for (int i = 0; i < c.w; i++)
        free(c.arr[i]);
    free(c.arr);
}
//8
void mat_copy(matrix b) {
    matrix c;
    c.w = b.w;
    c.h = b.h;
    c.arr = (int**)malloc(sizeof(int*) * c.h);
    for (int i = 0; i < c.h; i++) {
        c.arr[i] = (int*)malloc(sizeof(int*) * c.w);
    }
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            c.arr[i][j] = b.arr[i][j];
        }
    }
}