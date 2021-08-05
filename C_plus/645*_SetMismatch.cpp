class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {

        // option 1 O(n) time and O(N) space
        // unordered_map<int,int> mp;
        // for(int n:nums) mp[n]++;
        // vector<int> ret;
        // for(int n =1 ;n<=nums.size() ;++n){
        //     if(mp.count(n) && mp[n] == 2)  ret.push_back(n);  // twice number
        // }
        // for(int n =1 ;n<=nums.size() ;++n){
        //     if(!mp.count(n)) ret.push_back(n); // missing number
        // }
        // return ret;

        // option 2
        //  a^a = 0 , a^0 = a，如果數字都放對的話，index^val = 0
        // 再加上 ^ 符合交換率
        // 拜訪過的index-1 給他相反數
        //index  1 2 3 4 5 6 7 8 9
        //val    1 2 3 4 5 6 7 8 9
        //      0   1   2   3
        //      1   2   2   4
        //      -1  -2  2   -4
        //          +
        int dup;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;

            if (nums[index] < 0)
                dup = abs(nums[i]);
            else
            {
                nums[index] *= -1;
            }
        }
        int missing = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                missing = i + 1;
            }
        }
        return {dup, missing};
    }
};