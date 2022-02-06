

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *singleNumber(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 2;
    int *ret = calloc(*returnSize, sizeof(int));
    unsigned int diff = 0;
    for (int i = 0; i < numsSize; ++i)
        diff ^= nums[i];
    diff &= -diff;
    for (int i = 0; i < numsSize; ++i)
    {
        if (diff & nums[i])
            ret[0] ^= nums[i];
        else
            ret[1] ^= nums[i];
    }
    return ret;
}
