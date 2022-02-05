

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *nums, int l, int r)
{
    int i = l - 1;
    int pivot = nums[r];

    for (int j = l; j <= r; ++j)
    {
        if (nums[j] < pivot)
            swap(&nums[++i], &nums[j]);
    }
    swap(&nums[++i], &nums[r]);
    return i;
}
void quickSort(int *nums, int l, int r)
{
    if (l < r)
    {
        int p = partition(nums, l, r);
        quickSort(nums, l, p - 1);
        quickSort(nums, p + 1, r);
    }
}
int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    quickSort(nums1, 0, nums1Size - 1);
    quickSort(nums2, 0, nums2Size - 1);

    int *ret = malloc(sizeof(int));
    int a = 0, b = 0, count = 1;
    while (a < nums1Size && b < nums2Size)
    {
        if (nums1[a] == nums2[b])
        {
            ret = realloc(ret, sizeof(int) * count);
            ret[count - 1] = nums1[a];
            count++;
            while (a < nums1Size - 1 && nums1[a] == nums1[a + 1])
                a++;
            while (b < nums2Size - 1 && nums2[b] == nums2[b + 1])
                b++;
            a++;
            b++;
        }
        else if (nums1[a] < nums2[b])
            a++;
        else
            b++;
    }
    *returnSize = count - 1;
    return ret;
}