

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
    for (int j = l; j < r; ++j)
    {
        if (nums[j] < pivot)
        {
            i++;
            swap(&nums[j], &nums[i]);
        }
    }
    i++;
    swap(&nums[i], &nums[r]);
    return i;
}
void quickSort(int *nums, int l, int r)
{
    if (l < r)
    {
        int pivot = partition(nums, l, r);
        quickSort(nums, l, pivot - 1);
        quickSort(nums, pivot + 1, r);
    }
}
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{

    quickSort(nums1, 0, nums1Size - 1);
    quickSort(nums2, 0, nums2Size - 1);

    int *ret = NULL;
    int count = 0;
    int l = 0, r = 0;

    while (l < nums1Size && r < nums2Size)
    {
        if (nums1[l] == nums2[r])
        {
            ret = realloc(ret, sizeof(int) * (count + 1));
            ret[count] = nums1[l];
            count++;

            // while(l< nums1Size -1 && nums1[l]==nums1[l+1]) l++;
            // while(r< nums2Size -1 && nums2[r] == nums2[r+1]) r++;
            l++;
            r++;
        }
        else if (nums1[l] < nums2[r])
            l++;
        else
            r++;
    }
    *returnSize = count;
    return ret;
}