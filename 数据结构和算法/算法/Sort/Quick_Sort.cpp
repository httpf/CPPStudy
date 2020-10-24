//快速排序 平均时间复杂度为 O(nlgn)，最坏时间复杂夫O(n2)
//以序列的第一个元素为 基准数
//序列的左右两端各有一个哨兵 l 和 r. r从右向左寻找第一个比基准数小的数，找到即停止；l从左向右寻找第一个比基准数大的数，找到即停止；
//交换l和r, 两个哨兵继续向前

void quick_sort(int arr[], int left, int right)
{
    int i, j, key, tmp;
    if(left > right)
        return;       //递归返回点
    key = arr[left];  //基准数
    i = left;
    j = right;
    while(i != j)
    {
        while(arr[j] > key && i < j) j--;
        while(arr[i] < key && i < j) i++;
        if(i < j)
        {
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
    arr[left] = arr[i];
    arr[i] = tmp;

    quick_sort(arr, left, i-1);
    quick_sort(arr, i+1, right);
}