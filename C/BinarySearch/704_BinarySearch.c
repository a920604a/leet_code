

int search(int *nums, int numsSize, int target)
{
    // int l = 0, r = numsSize-1;
    // while(l<=r){
    //     int mid = l+(r-l)/2;
    //     if(nums[mid] == target) return mid;
    //     else if(nums[mid]<target) l = mid+1;
    //     else r= mid-1;
    // }
    // return -1;

    int l = 0, r = numsSize;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    if (l < numsSize && nums[l] == target)
        return l;
    return -1;
}