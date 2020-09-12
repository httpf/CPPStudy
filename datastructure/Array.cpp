/*
数组常见操作
Insert, Get, Delete, Size
*/

#include <stdlib.h>
#include <stdio.h>

//插入一个数到递增数组中，使数组依然有序
int* insert(int *arr, size_t len, int val)
{
    int i;
    int *arr_new = new int[len+1];
    for(i = len - 1; i >= 0; i--)
    {
        if(arr[i] >= val)
            arr_new[i + 1] = arr[i];
        else
        {
            arr_new[i + 1] = val;
            break;
        }
        
    }
    if(i == -1)
    {
        arr_new[0] = val;
    }
    else
    {
        for(int j = 0; j <= i; j++)
        {
            arr_new[j] = arr[j];
        }
    }

    return arr_new;
}

int main()
{
    int arr[10] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int * arr_new = insert(arr, 10, 5);
    for(int i = 0; i< 11; i++)
    {
        printf("%d ", arr_new[i]);
    }
    printf("\n");
}