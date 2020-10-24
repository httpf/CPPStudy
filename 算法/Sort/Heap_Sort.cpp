/*
若需升序排序，需先将序列调整为大顶堆，然后将堆顶元素和叶尾元素交换，则叶尾元素已经排好序；
再对堆进行调整为大顶堆，堆顶元素和次叶尾元素交换

size/2-1  最后一个非叶元素
2*index+1 左孩子
2*index+2 右孩子
*/

void adjust(int arr[], int len, int index)
{
    int left = 2 * index + 1, right = 2 * index  + 2;
    int max =  index;
    int tmp;
    if(left < len && arr[left] > arr[max]) max = left;
    if(right <  len && arr[right] > arr[max]) max = right;
    if(max  != index)
    {
        tmp = arr[index];
        arr[index] = arr[max];
        arr[max] = tmp;
        adjust(arr, len, max);
    }
}

void heapSort(int arr[], int size)
{
    int i, tmp;
    for(i = size/2-1; i>=0;i--)
    {
        adjust(arr, size, i);
    }
    for(i = size - 1; i >= 1; i--)
    {
        tmp = arr[0];
        arr[0] =  arr[i];
        arr[i] = tmp;
        adjust(arr, i, 0);
    }
}