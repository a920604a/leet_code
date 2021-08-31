class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // option 1
        //         int l =0, r = nums.size()-1;
        //         while(l<r){
        //             int mid = l+(r-l)/2;
        //             if(nums[mid] > nums[r]) l= mid+1;
        //             else r= mid;
        //         }

        //         return nums[l];

        // option 2 binary search
        int l = 0, r = nums.size() - 1, mid = 0;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] < nums[r])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l];
    }
};