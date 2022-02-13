

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    // 先用Binary Search 找到 陣列中有多少元素小於target(也就是說 target 要插入陣列需要插入在哪個位置)

    int l = 0, r = numsSize;
    *returnSize = 2;
    int *ret = calloc(*returnSize, sizeof(int));
    ret[0] = ret[1] = -1;
    if (numsSize == 0)
        return ret;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            r = mid;
        else if (nums[mid] > target)
            r = mid;
        else
            l = mid + 1;
    }
    if (l < 0 || l > numsSize - 1 || nums[l] != target)
        return ret;
    r = l;
    while (r < numsSize - 1 && nums[r + 1] == nums[r])
        r++;
    ret[0] = l;
    ret[1] = r;
    return ret;
}
