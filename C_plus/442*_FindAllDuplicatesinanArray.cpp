class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        // option 1 O(n) time and O(n) space
        // make use of hash table O(logn)
        //         unordered_map<int,int> mp;
        //         vector<int> ret;
        //         for(int n:nums) mp[n]++;

        //         for(auto iter = mp.begin(); iter !=mp.end();++iter){

        //             if(iter->second ==2 ) ret.emplace_back(iter->first);
        //         }
        //         return ret;

        // option 2 O(n) time and O(1) space
        // use a little bit math
        // use set to strot this answer
        // abs(arr[i]) -1 原本arr[i]應該被放置的索引位置 , 例如 arr[i] = 4 ，應該放置索引3的位置
        // 依序 scan 陣列，如果先前沒遇到，並將arr[i] = -arr[i] 相反數，有遇過 則為負數則將arr[i]放置set
        //

        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i)
        {
            int index = abs(nums[i]) - 1;

            if (nums[index] > 0)
                nums[index] = -nums[index];
            else
                ret.push_back(abs(nums[i]));
        }
        return ret;
    }
};