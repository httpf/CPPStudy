//每一轮循环就确定一个最小的元素，并与首元素进行交换。

void select_sort(int arr[], size_t len)
{
    int i, j, tmp;

    if(len < 2)
        return;

    for(i = 0; i < len -1; i++)//依次取 第1个 位置 到 倒数第2个 位置
    {
        int min = i;
        for(j = i + 1; j < len; j++)//循环所取位置之后的所有数，与最小数进行比较，若比最小数小，则交换
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}