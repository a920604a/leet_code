

void moveZeroes(int *nums, int numsSize)
{

    int slow = -1, fast = 0;
    while (fast < numsSize)
    {
        if (nums[fast] != 0)
        {
            nums[++slow] = nums[fast];
        }
        fast++;
    }
    slow++;
    while (slow < numsSize)
        nums[slow++] = 0;
}