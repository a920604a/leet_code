class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {

        // option 1 O(logn) binary search
        //         int l=0, r= nums.size()-1;

        //         while(l<=r){
        //             int mid = (l+r)/2;

        //             if(target==nums[mid]) return mid;
        //             else if(target>nums[mid]) l = mid+1;
        //             else r = mid-1;
        //         }
        //         return l;


        // binary search
        // lower bound
        int l= 0 , r = nums.size();
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]< target) l = mid+1;
            else r= mid;
        }
        return l;

        
        // option 2
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= target)
                return i;
        }
        return nums.size();
    }
};