class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {

        // option 1
        // 1. 先復原O(nlogn)
        // 2. binary search

        //         int peek = 0;
        //         for(int i=1;i<nums.size();++i){
        //             if(nums[i]<nums[i-1]){
        //                 peek = i;
        //                 break;
        //             }
        //         }
        //         sort(nums.begin(), nums.begin() + peek);
        //         sort(nums.begin()+peek + 1, nums.end());
        //         sort(nums.begin(), nums.end());

        //         int l = 0, r = nums.size()-1;

        //         while(l<=r){
        //             int mid = l + (r-l)/2;

        //             if(nums[mid] == target ) return true;
        //             else if(nums[mid] < target ) l = mid+1;
        //             else r = mid-1;
        //         }
        //         return false;

        // option 2
        // binary search

        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {

            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return true;

            else if (nums[r] > nums[mid])
            { // 右半部遞增
                if (nums[r] >= target && target > nums[mid])
                {
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            else if (nums[r] < nums[mid])
            { // 左半部遞增
                if (nums[l] <= target && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            else
                r--;
        }
        return false;
    }
};