

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{

    int l = 0, r = numsSize;
    *returnSize = 2;
    int *ret = malloc(2 * sizeof(int));
    // left bound
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            r = mid;
        else if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    if (l > numsSize - 1 || l < 0 || nums[l] != target)
    {
        ret[0] = -1, ret[1] = -1;
        return ret;
    }
    ret[0] = l;
    while (l < numsSize - 1 && nums[l + 1] == target)
        l++;
    ret[1] = l;
    return ret;
}