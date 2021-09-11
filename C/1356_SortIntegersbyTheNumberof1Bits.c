

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count(int n)
{
    int ret = 0;
    while (n)
    {
        ret++;
        n &= n - 1;
    }
    return ret;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int *sortByBits(int *arr, int arrSize, int *returnSize)
{
    // bubble sort
    *returnSize = arrSize;
    for (int i = 0; i < arrSize - 1; ++i)
    {
        for (int j = 0; j < arrSize - 1; ++j)
        {
            if (count(arr[j]) == count(arr[j + 1]))
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
            else if (count(arr[j]) > count(arr[j + 1]))
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    return arr;
}