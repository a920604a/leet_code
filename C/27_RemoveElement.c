

int removeElement(int *nums, int numsSize, int val)
{
    int slow = -1, fast = 0;
    while (fast < numsSize)
    {
        if (nums[fast] != val)
        {
            nums[++slow] = nums[fast];
        }
        fast++;
    }
    return slow + 1;
}