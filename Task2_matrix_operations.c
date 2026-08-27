// Task 2: Matrix Operations
// CodeAlpha C Programming Internship
// Author: Aryan Pandey

#include <stdio.h>

void addMatrices();
void multiplyMatrices();
void transposeMatrix();

int main() {
    int ch;

    do {
        printf("\n===== Matrix Operations =====\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("3. Transpose\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        if (ch == 1)
            addMatrices();
        else if (ch == 2)
            multiplyMatrices();
        else if (ch == 3)
            transposeMatrix();
        else if (ch == 4)
            printf("Bye!\n");
        else
            printf("Invalid choice\n");

    } while (ch != 4);

    return 0;
}

void addMatrices() {
    int a[10][10], b[10][10], c[10][10];
    int r, c1, i, j;

    printf("\nEnter rows and cols: ");
    scanf("%d %d", &r, &c1);

    printf("Enter matrix A:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter matrix B:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < r; i++)
        for (j = 0; j < c1; j++)
            c[i][j] = a[i][j] + b[i][j];

    printf("Result:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c1; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
}

void multiplyMatrices() {
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2, i, j, k;

    printf("\nEnter rows and cols of A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and cols of B: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Cannot multiply! cols of A != rows of B\n");
        return;
    }

    printf("Enter matrix A:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter matrix B:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("Result:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
}

void transposeMatrix() {
    int a[10][10], t[10][10];
    int r, c, i, j;

    printf("\nEnter rows and cols: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            t[j][i] = a[i][j];

    printf("Transpose:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++)
            printf("%d ", t[i][j]);
        printf("\n");
    }
}
