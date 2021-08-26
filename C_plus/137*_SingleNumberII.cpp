class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {

        // option 0 cheap
        //         unordered_map<int,int> dict;
        //         for(int n :nums) dict[n]++;

        //         for(int n :nums){
        //             if(dict[n]==1) return n;
        //         }
        //         return -1;

        // option 1 Bit manipulation O(n) time and O(1) space
        // 按照位元 ，每位取為1總和 %3 ，即為答案

        int ret = 0;
        for (int i = 0; i < 32; ++i)
        {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j)
            {
                sum += (nums[j] >> i) & 1;
            }

            ret += (sum % 3) << i;
        }

        return ret;
    }
};