

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *singleNumber(int *nums, int numsSize, int *returnSize)
{
    long diff = 0;
    for (int i = 0; i < numsSize; ++i)
        diff ^= *(nums + i);
    diff &= -diff;
    *returnSize = 2;
    int *ret = calloc(2, sizeof(int));
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] & diff)
            ret[0] ^= nums[i];
        else
            ret[1] ^= nums[i];
    }
    return ret;
}