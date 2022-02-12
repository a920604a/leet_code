

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *decode(int *encoded, int encodedSize, int first, int *returnSize)
{
    *returnSize = encodedSize + 1;
    int *ret = calloc(*returnSize, sizeof(int));
    int pre = first;
    ret[0] = first;
    for (int i = 1; i < *returnSize; ++i)
    {
        ret[i] = encoded[i - 1] ^ pre;
        pre = ret[i];
    }
    return ret;
}