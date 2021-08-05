class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // option 1 brute O(n^2) time out

        // int sum = 0, n=nums.size(), ret=0;
        // for(int i=0;i<n;++i){
        //     sum = nums[i];
        //     if(sum==k) ret++;
        //     for(int j=i+1;j<n;++j){
        //         sum +=nums[j];
        //         if(k==sum ) ret++;
        //     }
        // }
        // return ret;

        // option 2 simplify brute time out
        //         int  n= nums.size(), ret=0;
        //         vector<int> sum =nums;
        //         for(int i=1;i<n;++i){
        //             sum[i] =sum[i-1]+nums[i];
        //         }
        //         for(int i =0;i<n;++i){
        //             if(sum[i]==k) ret++;
        //             for(int j=i-1;j>=0;j--){
        //                 if(sum[i]-sum[j] ==k) ret++;
        //             }
        //         }

        //         return ret;

        // option 3 O(n) time and O(n) space 
        // 前綴和主要適用場景是原始數組不會步修改的情況下，頻繁的查詢某個區間的累加和。
        int n = nums.size();
        vector<int> sum = vector<int>(n+1,0);
        for(int i=1;i<=n;++i) sum[i] = sum[i-1] + nums[i-1];
        unordered_map<int,int> mp;
        //base case
        mp[0] = 1;
        int ret = 0;
        for(int i=1;i<=n ;++i){
            int target = sum[i] - k;
            if(mp.count(target)){
                ret += mp[target];
            }
            mp[sum[i]]++;
        }
        return ret;
        
    }
};