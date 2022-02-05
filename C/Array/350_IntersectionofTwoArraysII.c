

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
    int pivot = nums[r];
    int i = l - 1;
    for (int j = l; j <= r; ++j)
    {
        if (nums[j] < pivot)
            swap(&nums[++i], &nums[j]);
    }
    i++;
    swap(&nums[r], &nums[i]);
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
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    quickSort(nums1, 0, nums1Size - 1);
    quickSort(nums2, 0, nums2Size - 1);
    int a = 0, b = 0, count = 1;
    int *ret = malloc(sizeof(int));
    while (a < nums1Size && b < nums2Size)
    {
        if (nums1[a] == nums2[b])
        {
            ret = realloc(ret, sizeof(int) * count);
            ret[count - 1] = nums1[a];
            count++;
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