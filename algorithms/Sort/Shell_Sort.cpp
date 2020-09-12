//1. 分组
//2. 取数
//3. 对取的数进行插入排序
//该排序的时间复杂度与增量序列有关。
//若增量序列为1，则变为快速排序

void shell_sort(int arr[], size_t n)
{
    int i, j, k, group;
    for(group = n/2; group > 1; group /=2)
    {
        for(i = 0;i < group; i++)//第1组，第2组，第3组
        {
            for(j = i + group; j < n; j += group) //取每组中的数据，从第2个数据开始取
            {
                if(arr[j-group] > arr[j]) //若当前数据并不小于前一个数据，则不需要插入
                {
                    int tmp = arr[j];    //当前选择的数据，从第2个开始
                    k = j - group;       //当前数据的前一个位置
                    while(k>=0 && (arr[k] > tmp))
                    {
                        arr[k+group] = arr[k];
                        k -= group;
                    }
                    arr[k] = tmp;
                }
            }
        }
    }
}