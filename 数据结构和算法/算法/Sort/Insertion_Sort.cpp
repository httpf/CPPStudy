//每次选择一个元素，和已经排序的元素进行比较，然后插入到合适的位置

void Insertion_Sort(int arr[], int length)
{
    int i, j;
    for(i = 1; i < length; i++)
    {
        int tmp = arr[i];
        for(j = i - 1; j > 0 && arr[j] < arr[j-1]; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
}
//首先挑选一个数，然后和前面已经排序的数进行比较，在合适的位置插入，时间复杂度为O(n2)
//每次创建一个变量，空间复杂度为O(1)
void Insert_Sort(int arr[], int length)
{
    int i, j;
    for(i = 1; i < length; i++)
    {
        int tmp = arr[i];
        for(j = i; j > 0 && arr[j-1] > tmp; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
}