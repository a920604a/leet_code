#define max(a, b) ((a > b) ? a : b)

int lengthOfLIS(int *nums, int numsSize)
{

    // dp
    //  10  9   2   5   3   7   101 18
    //  1   1   1   1   1   1   1   1
    //  1   1   1   2   2   3   4   4

    int *dp = calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; ++i)
        *(dp + i) = 1;
    int ret = dp[0];
    for (int i = 1; i < numsSize; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
        ret = max(ret, dp[i]);
    }
    free(dp);
    return ret;
}