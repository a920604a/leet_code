
#define max(a, b) ((a > b) ? a : b)

int maxSubArray(int *nums, int numsSize)
{
    int ret = 0, global = INT_MIN;
    for (int i = 0; i < numsSize; ++i)
    {
        ret = max(ret + nums[i], nums[i]);
        global = max(ret, global);
    }
    return global;
}