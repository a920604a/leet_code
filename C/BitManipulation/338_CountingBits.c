

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int count(int n)
{
    int ret = 0;
    while (n)
    {
        n = n & (n - 1);
        ret++;
    }
    return ret;
}
int *countBits(int n, int *returnSize)
{
    *returnSize = n + 1;
    int *ret = calloc(n + 1, sizeof(int));
    // for(int i=0;i<=n;++i){
    //     ret[i] = count(i);
    // }
    for (int i = 1; i <= n; ++i)
    {
        ret[i] = ret[i & (i - 1)] + 1;
    }
    return ret;
}