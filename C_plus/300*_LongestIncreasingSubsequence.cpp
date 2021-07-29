class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // option 1 use dp 到目前為止的最長子序列長度
        // O(n^2) dp
        //        10    9   2   5   3   7   101   18
        //         1    1   1   1   1   1   1     1
        // i=1     1    1       
        // i=2     1    1   1
        // i=3     1    1   1   2
        // i=4     1    1   1   2   2
        // i=5     1    1   1   2   2   3
        // i=6     1    1   1   2   2   3   4
        // i=7     1    1   1   2   2   3   4   4
        
        //         int n = nums.size(), ret = 0;
        //         vector<int> dp(n, 1);
        //         for(int i=0;i<n;++i){
        //             for(int j=0;j<i;++j){
        //                 if(nums[i]>nums[j]) dp[i] = max(dp[j]+1, dp[i]);
        //             }
        //             ret = max(ret, dp[i]);
        //             // 每次更新dp[i] 都來更新一下最大值
        //         }

        //         return ret;

        // option 2 Binary search O(nlogn)

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
