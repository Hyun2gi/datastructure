#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[2][3];
    int B[2][3];
    int length1 = sizeof(A[0])/sizeof(A[0][0]);
    int length2 = sizeof(A)/sizeof(A[0]);

    for(int i =0;i< 2;i++)
    {
        for (int j=0;j<3;j++)
        {

            scanf("%d",A[i][j]);

        }

    }

    for(int i =0;i<2;i++)
    {
        for (int j=0;j<3;j++)
        {
            printf("%d",A[i][j]);
        }

    }
}
