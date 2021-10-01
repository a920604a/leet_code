#define min(a, b) ((a < b) ? a : b)

int minSubArrayLen(int target, int *nums, int numsSize)
{
    // slide window
    int l = 0, r = 0;
    int len = numsSize + 1;
    int cur = 0;
    while (r < numsSize)
    {
        int c = nums[r++];
        cur += c;
        while (cur >= target)
        {
            printf("%d\t%d\n", l, r);
            len = min(len, r - l);
            int d = nums[l++];
            cur -= d;
        }
    }
    return len == numsSize + 1 ? 0 : len;
}