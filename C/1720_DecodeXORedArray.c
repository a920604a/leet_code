

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *decode(int *encoded, int encodedSize, int first, int *returnSize)
{

    *returnSize = encodedSize + 1;
    int *ret = calloc(*returnSize, sizeof(int));
    int pre = first;
    // 1 0 2 1 => 1 2 3
    // xor 交換律
    // 2^1 = 3 then 1 = 3^2,
    // 0^2 = 2 then 0 = 2^2,
    // 1^0 = 1 then 1 = 1^0,
    // first = 1
    // first^en[i] = arr[i+1] , first = arr[i+1]
    ret[0] = first;
    for (int i = 1; i < *returnSize; ++i)
    {
        ret[i] = first ^ encoded[i - 1];
        first = ret[i];
    }
    return ret;
}