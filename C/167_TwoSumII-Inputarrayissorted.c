

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{

    int i = 0, j = numbersSize - 1;
    int *ret = calloc(*returnSize = 2, sizeof(int));

    while (i < j)
    {
        if (target == numbers[i] + numbers[j])
        {
            ret[0] = i + 1;
            ret[1] = j + 1;
            return ret;
        }
        else if (target < numbers[i] + numbers[j])
            j--;
        else
            i++;
    }
    return ret;
}