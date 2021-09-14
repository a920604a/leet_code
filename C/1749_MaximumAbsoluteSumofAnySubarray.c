#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int maxAbsoluteSum(int *nums, int numsSize)
{

    //      1   -3  2   3   -4
    //mx    1   -2  2   5   1
    //mn    1   -3  -1  2   -2
    //ans(abs)

    //      2   -5  1   -4  3   -2
    //mx    2   -3  1   -3  3    1
    //mn    2   -5  -4  -8  -5  -7
    //abs
    int *mx = calloc(numsSize, sizeof(int));
    int *mn = calloc(numsSize, sizeof(int));
    int ans = max(nums[0], -nums[0]);
    mx[0] = nums[0], mn[0] = nums[0];
    for (int i = 1; i < numsSize; ++i)
    {
        mx[i] = max(nums[i] + mx[i - 1], nums[i]);
        mn[i] = min(nums[i] + mn[i - 1], nums[i]);
        ans = max(ans, max(mx[i], -mx[i]));
        ans = max(ans, max(mn[i], -mn[i]));
    }
    return ans;
}