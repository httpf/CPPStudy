//从第1个元素开始，比较相邻的两个元素，若第一个大于第二个则交换。
//这样每一轮循环就能确定一个最大的元素。

void bubble_sort(int arr[], int length)
{
    int tmp;
    int max = length - 1;
    while(max < 1)
    {
        for(int i = 0; i < max; i++)
        {
            if(arr[i] > arr[i+1])
            {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }
        max--;
    }

}