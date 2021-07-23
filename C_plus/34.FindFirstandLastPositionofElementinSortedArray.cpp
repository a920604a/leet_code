class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        // binary search
        // 尋找左邊界 框架
        // [1,2,3,4,7,8,10] , target = 6
        //  left = 4 ，代表該數組小於target = 6的有4個
        //         if(nums.empty()) return {-1,-1};
        //         if(nums.back() < target || target < nums[0]) return {-1,-1};

        //         int left =0, right = nums.size()-1;
        //         while(left<=right){
        //             int mid = left + (right-left)/2;
        //             if(nums[mid] == target) right = mid-1;
        //             else if(nums[mid] > target) right = mid-1;
        //             else if(nums[mid] < target) left = mid +1;
        //         }
        //         cout<<left<<endl;
        //         if(nums[left]!= target) return {-1,-1};
        //         vector<int> ret = {left};
        //         // left < nums.size()-1  防止nums[left+1] 溢位
        //         while(left < nums.size()-1  && nums[left] == nums[left+1]) left++;
        //         ret.push_back(left);
        //         return ret;

        // version 2
        if (nums.empty())
            return {-1, -1};
        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                right = mid;
            else if (nums[mid] > target)
                right = mid;
            else if (nums[mid] < target)
                left = mid + 1;
        }
        if (left > nums.size() - 1 || nums[left] != target)
            return {-1, -1};
        vector<int> ret = {left};
        while (left < nums.size() - 1 && nums[left] == nums[left + 1])
            left++;
        ret.push_back(left);
        return ret;
    }
};