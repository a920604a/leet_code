class Solution
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0]; // 升序
    }
    int maxEnvelopes(vector<vector<int> > &envelopes)
    {
        // step1. 先對w做升序，如果遇到w相同，用h做降序
        // step2. 基於上述排序，搜集h遞增子序列
        // step3. 針對h做最長遞增子序列

        int n = envelopes.size();
        //先對w做升序，如果遇到w相同，用h做降序
        sort(envelopes.begin(), envelopes.end(), compare);

        // 基於上述排序，搜集h遞增子序列
        vector<int> ret(n, 0);
        for (int i = 0; i < n; ++i)
        {
            ret[i] = envelopes[i][1];
        }

        // 基於上述排序，搜集h遞增子序列
        return lengthOfLIS(ret);
    }
    // leetcode - 300.
    int lengthOfLIS(vector<int> &nums)
    {
        //         // option 1  use dp 到目前為止的最長子序列長度
        //         // O(n^2) dp
        //         // 10 9 2 5 3 7 101 18
        //         //  1 1 1 2 2 3 4   4   dp[i] = max(dp[i], dp[j] +1)
        //         int n = nums.size(), ret = 0;
        //         vector<int> dp(n, 1);
        //         for(int i=0;i<n;++i){
        //             int local_max = nums[i];
        //             for(int j=0;j<i;++j){
        //                 if(nums[i]>nums[j]) dp[i] = max(dp[j]+1, dp[i]);
        //             }
        //             ret = max(ret, dp[i]);
        //             // 每次更新dp[i] 都來更新一下最大值
        //         }

        //         return ret;

        int n = nums.size();
        vector<int> top(n, 0); //  牌堆初始化０
        int piles = 0;
        for (int i = 0; i < n; ++i)
        {

            int poker = nums[i]; // 要處理的撲克牌

            int left = 0, right = piles;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (top[mid] > poker)
                    right = mid;
                else if (top[mid] < poker)
                    left = mid + 1;
                else
                    right = mid;
            }
            //沒找到合適的牌堆，新建一堆
            if (left == piles)
                piles++;
            top[left] = poker;
        }

        return piles;
    }
};