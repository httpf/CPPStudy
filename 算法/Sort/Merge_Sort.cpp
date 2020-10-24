/*
归并排序
时间复杂度总是 O(nlgn)
采用分治法。
将一个序列分成两部分（并递归），直到分割为只有一个元素为止；
然后将分割后的两组序列合并为一组（并递归），直到合并成一个完整的序列。
*/

void merge(int *A, int *L, int leftcount, int *R, int rightcount)
{
    int i = 0, j = 0, k = 0;
    while(i < leftcount && j < rightcount)
    {
        if(L[i] < R[i])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    while(i < leftcount) A[k++] = L[i++];
    while(j < rightcount) A[k++] = R[j++];
}

int merge_sort(int arr[], int length)
{
    if(length < 2)
        return;
    int mid, *L, *R, i;
    mid /=2;
    L = new int[mid];
    R = new int[length-mid];
    for(i = 0; i< mid; i++) L[i] = arr[i];
    for(i = mid; i < length; i++) R[i] = arr[i];
    merge_sort(L, mid);
    merge_sort(R, length - mid);
    merge(arr, L, mid, R, length-mid);

    delete [] L;
    delete [] R;
}