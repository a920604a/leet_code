

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 2;
    int *ret = calloc(*returnSize, sizeof(int));
    for (int i = 0; i < numsSize; ++i)
    {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] > 0)
            nums[idx] *= -1;
        else
            ret[0] = abs(nums[i]);
    }
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] > 0)
            ret[1] = i + 1;
    }

    return ret;
}