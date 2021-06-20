class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        // option 1
        //  O(n) time O(1) space
        // if(nums.size()==1) return nums[0];
        // int ret = 0;
        // for(int i =0;i<nums.size();i+=2){
        //     if(nums[i]!=nums[i+1]){
        //         ret = nums[i];
        //         break;
        //     }
        // }
        // return ret;

        // option 1 O(logn) time O(1) space
        // 長度必定是奇數，如果mid索引是偶數代表索引前面的數字應該都是兩兩一對，如果不是mid索引的值會與前一索引值相同，則落單的數必定在前面，反之相反。
        // binary search
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size(), l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == nums[mid + 1])
            {
                if (mid % 2 == 1)
                    r = mid;
                else
                    l = mid + 1;
            }
            else
            {
                if (mid == 0 || nums[mid] != nums[mid - 1])
                    return nums[mid];
                if (mid % 2 == 0)
                    r = mid;
                else
                    l = mid + 1;
            }
        }
        return nums[l];
    }
};