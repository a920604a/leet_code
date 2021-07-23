class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // version 1
        // int l = 0, r= nums.size()-1; // 注意
        // 搜索區間[l, r]
        // while(l<=r){
        //     int mid = l + (r-l)/2;
        //     if(nums[mid] == target) return mid;
        //     else if(nums[mid]< target) l = mid+1; // 注意
        //     else if(nums[mid]>target) r= mid-1; // 注意
        // }
        // return -1;

        // version 2
        int l = 0, r = nums.size();
        // 搜索區間[l, r)
        while (l < r)
        { //  終止條件 l==r
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid;
        }
        return nums[l] == target ? l : -1;
    }
};