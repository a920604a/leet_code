

int search(int *nums, int numsSize, int target)
{
    // normal version
    // int l = 0, r = numsSize-1;
    // while(l<=r){
    //     int mid = l + (r-l)/2;
    //     if(nums[mid ] == target) return mid;
    //     else if(nums[mid] < target) l = mid+1;
    //     else r = mid-1;
    // }
    // return -1;

    // 左閉右開 區間
    // int l =0, r = numsSize;
    // while(l<r){
    //     int mid = l + (r-l)/2;
    //     if(nums[mid] == target) return mid;
    //     else if(nums[mid] < target) l = mid+1;
    //     else r = mid;
    // }
    // if(l> numsSize-1) return -1;
    // return nums[l]==target?l:-1;

    // left bound
    int l = 0, r = numsSize;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            r = mid;
        else if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    if (l > numsSize - 1)
        return -1;
    return nums[l] == target ? l : -1;
}
