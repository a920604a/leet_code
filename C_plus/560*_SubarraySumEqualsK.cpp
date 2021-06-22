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

        // option 2 simplift brute time out
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

        // option 3 O(nlogn)

        // map<int,int> m;  // sum mapping the number of k occur
        // int sum=0,ret= 0;
        // m[0]++;
        // for(int i=0;i<nums.size();++i){
        //     sum += nums[i];
        //     if(m.find(sum-k)!=m.end()) ret += m[sum-k];
        //     m[sum]++;
        // }
        // return ret;
    }
};