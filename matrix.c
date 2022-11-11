#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "matrix.h"
int main(void) {
    setlocale(LC_ALL, "Rus");
    int w, h, item;
    matrix a,b,c;
    scanf("%d%d%d", &w, &h, &item);
    if (w <= 0 || h <= 0) {
        printf("Wrong size(matrix height and width can not be below 1)");
        return 0;
    }
    a = fill(w, h, item);
    printf("���������� ������� ������ %d:\n", item);
    for (int i = 0; i < a.h; i++) {
        for (int j = 0; j < a.w; j++) {
            printf("%d ", a.arr[i][j]);
        }
        printf("\n");
    }
    // ����� ����������� �������
    printf("\n");
    printf("���������� ������� rand ������ �� 0 �� 9:\n");
    b = rand_fill(w,h);
    for (int i = 0; i < b.h; i++) {
        for (int j = 0; j < b.w; j++) {
            printf("%d ", b.arr[i][j]);
        }
        printf("\n");
    }
    // ����� �������, ����������� ��������
    printf("\n����� ������� c, ����� ������ a � b\n");
    c = mat_sum(a, b);
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            printf("%d ", c.arr[i][j]);
        }
        printf("\n");
    }
    // ����� ����� ������� c (c=a+b)
    printf("\n����� ������� c, �������� ������ a � b\n");
    c = mat_sub(a, b);
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            printf("%d ", c.arr[i][j]);
        }
        printf("\n");
    }
    // ����� ����� ������� c (c=a-b)
    printf("\n����� ������� c, ������������ ������ a � b\n");
    c = mat_multi(a, b);
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            printf("%d ", c.arr[i][j]);
        }
        printf("\n");
    }
    // ����� ����� ������� c (c=a*b)
    printf("\n����� ������� c, ����������������� ������� b\n");
    c = mat_tran(b);
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            printf("%d ", c.arr[i][j]);
        }
        printf("\n");
    }
    // ����� ����������������� ������� a, � ����� ������� c
    mat_free(c);
    mat_copy(b);
    for (int i = 0; i < c.h; i++) {
        for (int j = 0; j < c.w; j++) {
            printf("%d ", c.arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}