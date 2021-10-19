class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        // option 1 O(nlogn) time and O(1) space
        // sort and compare
        // int ret = 1;
        // sort(nums.begin(), nums.end());
        // int n= nums.size();
        // for(int i=0;i<n ;++i){
        //     if(nums[i] >0) {
        //         if(ret==nums[i]) ret++;
        //     }
        // }
        // return ret;

        // option 1 O(n) time and O(n) time
        int n = nums.size();
        vector<int> vec(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0 && nums[i] < n + 1)
                vec[nums[i]]++;
        }
        for (int i = 1; i < vec.size(); ++i)
        {
            if (vec[i] == 0)
                return i;
        }
        return vec.size();
    }
};