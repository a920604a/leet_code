

int findDuplicate(int *nums, int numsSize)
{
    // modify array
    for (int i = 0; i < numsSize; ++i)
    {
        int idx = abs(*(nums + i)) - 1;
        if (*(nums + idx) < 0)
            return abs(*(nums + i));
        *(nums + idx) *= -1;
    }

    
    return -1;


    int slow = 0, fast = 0, t= 0;
    while(1){
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(slow==fast) break;
    }
    while(1){
        t = nums[t];
        slow = nums[slow];
        if(t==slow) break;
    }
    return t;
    
}