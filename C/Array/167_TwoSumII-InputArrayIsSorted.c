

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    int *ret = calloc(2, sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numbersSize - 1; ++i)
    {
        int sum = target - numbers[i];
        int l = i + 1, r = numbersSize - 1;
        while (l <= r)
        {
            int ≈ = l + (r - l) / 2;
            if (sum == numbers[mid])
            {
                ret[0] = i + 1;
                ret[1] = mid + 1;
                return ret;
            }
            else if (sum < numbers[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    return ret;
}