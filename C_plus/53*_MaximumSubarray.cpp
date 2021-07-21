class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // option 0 brute
        // int ret = nums[0];
        // for(int i=0;i<nums.size();++i){
        //     int total = 0;
        //     for(int j=i;j<nums.size();++j){
        //         total += nums[j];
        //         ret = max(ret, total);
        //     }
        // }
        // return ret;

        // option 1 brute force use dp
        // O(n) time, O(n) space
        // -2 1 -3 4 -1 2 1 -5 4
        // -2 1 -2 4  3 5 6  1 5
        // int n = nums.size(), ret = nums[0];
        // vector<int> dp(nums.begin(), nums.end()); // initalize dp
        // for(int i=1;i<n;++i){
        //     dp[i] = max(dp[i-1] + nums[i], nums[i]);
        //     ret = max(ret, dp[i]); //每次更新dp，都順便更新一下最大值
        // }
        // return ret;

        // option 1.1 improvec dp O(n) time O(1) 1 space
        // int n= nums.size();
        // int dp_0 = nums[0];
        // int dp_1 = 0 , ret = dp_0;
        // for(int i=1;i<n;++i){
        //     dp_1 = max(nums[i]+dp_0 , nums[i]);
        //     dp_0 = dp_1; // 為了下一輪的更新
        //     ret = max(ret, dp_1);
        // }
        // return ret;

        // option 2  divide and conquer
        return GetMax(nums, 0, nums.size() - 1);

        // option 3 Kadane’s Algorithm O(n) simplify option 0
        // int n = nums.size(), local_max = 0;
        // int global_max = INT_MIN;
        // for (int i = 0; i < n; ++i)
        // {
        //     local_max = max(nums[i], nums[i] + local_max);
        //     if (local_max > global_max)
        //     {
        //         global_max = local_max;
        //     }
        // }
        // return global_max;
    }
    int GetMax(vector<int> &nums, int l, int r)
    {

        if (l >= r)
            return nums[l];
        int mid = (l + r) / 2;
        int lmax = GetMax(nums, l, mid - 1);
        int rmax = GetMax(nums, mid + 1, r);
        int mmax = nums[mid];
        int temp = nums[mid];
        for (int i = mid - 1; i >= l; i--)
        {

            temp += nums[i];
            mmax = max(mmax, temp);
        }

        temp = mmax;
        for (int i = mid + 1; i <= r; ++i)
        {

            temp += nums[i];
            mmax = max(mmax, temp);
        }
        return max(mmax, max(lmax, rmax));
    }
};
