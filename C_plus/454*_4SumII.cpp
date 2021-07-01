class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        // hash table 。存儲AB hash table兩個總和及出現次數，再去找CD hash table找相反數是否存在。
        // O(n^2)
        //         unordered_map<int,int> mp;
        //         for(int i=0;i<nums1.size();++i){
        //             for(int j = 0;j<nums2.size();++j){
        //                 mp[nums1[i]+nums2[j]]++;
        //             }
        //         }
        //         int ret = 0;
        //         for(int i=0;i<nums3.size();++i){
        //             for(int j = 0;j<nums4.size();++j){
        //                 int target = nums3[i]+ nums4[j];
        //                 ret += mp[-target];
        //             }
        //         }

        //         return ret;

        // improved
        unordered_map<int, int> mp;
        int ret = 0;
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                mp[a + b]++;
            }
        }
        for (int c : nums3)
        {
            for (int d : nums4)
            {
                ret += mp[-c - d];
            }
        }
        return ret;
    }
};