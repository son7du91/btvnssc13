#include <stdio.h>
void inputMatrix(int matrix[100][100], int rows, int cols) {
    printf("\nNhập giá trị cho ma trận (%d hàng, %d cột):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Phần tử tại vị trí [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void printMatrix(int matrix[100][100], int rows, int cols) {
    printf("\nMa trận (%d hàng, %d cột):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    int matrix[100][100];
    printf("Nhập số hàng: ");
    scanf("%d", &rows);
    printf("Nhập số cột: ");
    scanf("%d", &cols);
    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);
    return 0;
}
