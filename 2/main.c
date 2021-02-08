#include <stdio.h>
#include <stdlib.h>
double*** mem_alloc_3D_double(int w, int h, int m);
void addition_3D(double*** data1, double*** data2);

double*** mem_alloc_3D_double(int w, int h, int m)
{
    double***arr = (double***)malloc(sizeof(double**)*w);
    int i,j,k;
    for(i=0;i<w;i++)
    {
        arr[i] = (double**)malloc(sizeof(double*)*h);
        for(j=0;j<h;j++)
        {
            arr[i][j] = (double*)malloc(sizeof(double)*m);
        }
    }
    return arr;
}

void addition_3D(double*** data1, double*** data2)
{
    double data;
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                data = data1[i][j][k] + data2[i][j][k];
                printf("%f\t",data);
            }
            printf("\n");
        }
        printf("\n");
    }

}
void memoryRelease(double*** data, int width, int length, int height)
{
    int i, j;
    for (i = 0; i < width; i++)
    {
        for (j = 0; j < height; j++)
        {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);
}

int main()
{
    int i,j,k,cnt;
    double*** data1 = mem_alloc_3D_double(3,3,3);
    double*** data2 = mem_alloc_3D_double(3,3,3);// 3x3x3 วาด็
    cnt = 1;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                data1[i][j][k] = cnt;
                printf("%f\t ", data1[i][j][k]);
                cnt++;
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("========================\n");
     for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                data2[i][j][k] = cnt;
                printf("%f ", data2[i][j][k]);
                cnt++;
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("========================\n");
    addition_3D(data1, data2);
    memoryRelease(data1,3,3,3);
    memoryRelease(data2,3,3,3);
}
