#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100
typedef struct {
    int row;
    int col;
    int value;
} element;

typedef struct SparseMatrix{
    element data[MAX_TERMS];
    int rows; //실제 항의 행의 개수
    int cols; //실제 항의 열의 개수
    int terms; //실제 항의 개수
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a)
{
    SparseMatrix b;

    int bindex;
    b.rows = a.cols;
    b.cols = a.rows;
    b.terms = a.terms;

    if(a.terms > 0) {
        bindex = 0;
        for(int c = 0; c < a.cols; c++) {
            for(int i = 0; i <a.terms; i++)
            {
                if(a.data[i].col == c) {
                    b.data[bindex].row = a.data[i].col;
                    b.data[bindex].col = a.data[i].row;
                    b.data[bindex].value = a.data[i].value;
                    bindex++;
                }
            }

        }

    }
    return b;

}

void matrix_print(SparseMatrix a)
{
    printf("==============================\n");
    int i,j;
    int term=0;
    for(i = 0;i < a.rows;i++)
    {
        for(j=0 ; j<a.cols ; j++)
        {
            if((a.data[term].row==i)&&(a.data[term].col==j))
            {
                printf("%d ", a.data[term].value);
                term++;
            }else{
                printf("%d ", 0);
            }
        }
        printf("\n");
    }


}

int main(void)
{
    SparseMatrix m ={{{0, 3, 7},{1, 0, 9},{1, 5, 8},{3, 0, 6}, {3, 1, 5}, {4, 5, 1},{5, 2, 2}},
    6,
    6,
    7
    };
    SparseMatrix result;

    result = matrix_transpose2(m);
    matrix_print(m);
    matrix_print(result);
    return 0;
}
