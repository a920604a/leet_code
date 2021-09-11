

int singleNumber(int *nums, int numsSize)
{

    long ret = 0;
    for (int i = 0; i < 32; ++i)
    {
        long sum = 0;
        for (int j = 0; j < numsSize; ++j)
        {
            sum += (nums[j] >> i) & 1;
        }
        ret += (sum % 3) << i;
    }
    return ret;
}