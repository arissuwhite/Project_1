#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "matrix.h"

typedef struct matrix {
    int w, h;
    int** arr;
} matrix;
int main(void) {
    setlocale(LC_ALL, "Rus");
    int w, h, item;
    matrix a, b, c;
    matrix d;
    scanf("%d%d%d", &w, &h, &item);
    if (w <= 0 || h <= 0) {
        printf("Wrong size(matrix height and width can not be below 1)");
        return 0;
    }
    printf("\nMatrix filling d(item=%d):\n", item);
    d = fill(h, w, item);
    printmat(d);
    a = fill(w, h, item);
    printf("\nMatrix filling a(item=%d):\n", item);
    printmat(a);
    printf("\n");
    printf("Matrix b (random filling with numbers from 0 to 9):\n");
    b = rand_fill(w, h);
    printmat(b);
    printf("\nMatrix sum, new matrix:\n");
    c = mat_sum(a, b);
    printmat(c);
    printf("\nMatrix substraction, new matrix:\n");
    c = mat_sub(a, b);
    printmat(c);
    printf("\nMatrix multiplication a and d, new matrix:\n");
    c = mat_multi(a, d);
    printf("%d %d\n", c.h, c.w);
    printmat(c);
    printf("\nTransposed matrix b, new matrix:\n");
    c = mat_tran(b);
    printmat(c);
    mat_free(c);
    matrix newmat;
    newmat = mat_copy(b);
    printf("\n%d %d\n", newmat.w, newmat.h);
    printf("\nRandom filled matrix(b) was copied to new matrix:\n");
    printmat(newmat);
    return 0;
}