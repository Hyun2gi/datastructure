#include <stdio.h>
#include <stdlib.h>
double*** mem_alloc_3D_double(int width, int length, int height);
double*** addition_3D(double*** data1, double*** data2);
void memoryRelease(double*** data, int width, int length, int height);

int main()
{
    int i,j,k,cnt;
    double*** data1 = mem_alloc_3D_double(3,3,3);
    double*** data2 = mem_alloc_3D_double(3,3,3); // 3x3x3 할당
    cnt = 1;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                data1[i][j][k] = cnt;
                printf("%f ", data1[i][j][k]);
                cnt++;
            }
        }
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
        }
    }
    printf("========================\n");
    double*** data3 = mem_alloc_3D_double(3,3,3);
    data3 = addition_3D(data1, data2);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                printf("%f ", data3[i][j][k]);
            }
        }
    }
    printf("========================\n");
    memoryRelease(data1,3,3,3);
    memoryRelease(data2,3,3,3);
    memoryRelease(data3,3,3,3); // 3x3x3 해제
}

double*** mem_alloc_3D_double(int width, int length, int height)
{
    double*** data;
    int i, j;
    data = (double***)malloc(sizeof(double**) * height);
    for (i = 0; i < height; i++)
    {
        data[i] = (double**)malloc(sizeof(double*) * length);
        for (j = 0; j < length; j++)
        {
            data[i][j] = (double*)malloc(sizeof(double) * width);
        }
    }
    return data;
}

double*** addition_3D(double*** data1, double*** data2)
{
    double*** data;
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                data[i][j][k] = data1[i][j][k] + data2[i][j][k];
            }
        }
    }
    return data;

}

void memoryRelease(double*** data, int width, int length, int height)
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < length; j++)
        {
            free(data[i][j]);
            if (data[i][j] != NULL)
            {
                return 1;
            }
        }
    }
    for (i = 0; i < height; i++)
    {
        free(data[i]);
        if (data[i] != NULL)
        {
            return 1;
        }
    }
    free(data);
    return 0;

}
