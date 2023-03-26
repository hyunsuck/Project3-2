#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
    int row, col, value;
} element;

typedef struct sparse_matrix {
    element data[MAX_TERMS];
    int num_rows, num_cols, num_terms;
    // 행의 갯수, 열의 갯수, 항의 갯수
} sparse_matrix;

sparse_matrix transepose_matrix(sparse_matrix a) {
    sparse_matrix b;

    int b_index; // 행렬 b에서 현재 저장 위치
    b.num_rows = a.num_rows;
    b.num_cols = a.num_cols;
    b.num_terms = a.num_terms;

    if (a.num_terms > 0) {
        b_index = 0;
        for (int c = 0; c < a.num_cols; ++c) {
            for (int i = 0; i < a.num_terms; ++i) {
                if (a.data[i].col == c) {
                    b.data[b_index].row = a.data[i].col;
                    b.data[b_index].col = a.data[i].row;
                    b.data[b_index].value = a.data[i].value;
                    b_index++;
                }
            }
        }
    }
    return b;
}

void print_matrix(sparse_matrix a) {
    for (int i = 0; i < a.num_terms; ++i) {
        printf("(%d, %d, %d)\n", a.data[i].row, a.data[i].col, a.data[i].value);
    }
}
int main() {
    sparse_matrix m = { {{0,3,7},
                   {1,0,9},
                   {1,5,8},
                   {3,0,6},
                   {3,1,5},
                   {4,5,1},
                   {5,2,2}}, 6,6,7 };
    sparse_matrix result;
    printf("Enter row, column and value paris in order : 6 6 7\n");
    print_matrix(m);
    printf("The Transporsed matrix is : \n");
    result = transepose_matrix(m);
    print_matrix(result);
    return 0;
}