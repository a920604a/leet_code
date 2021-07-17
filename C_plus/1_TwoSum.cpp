/*
 * @Author: yuan
 * @Date: 2021-03-20 15:06:39
 * @LastEditTime: 2021-07-15 14:14:59
 * @FilePath: /leet_code/C_plus/1_TwoSum.cpp
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // https://web.stanford.edu/class/cs9/sample_probs/TwoSum.pdf
        // option 1 brute O(n^2) time and O(1) space
        // int n = nums.size();
        // for(int i=0;i<n;++i){
        //     for(int j=i+1;j<n;++j){
        //         if(nums[i]+nums[j]==target) return {i,j};
        //     }
        // }
        // return {};

        option 2 Hashing O(n) time and O(n) space
        map<int, int> tmp;
        for (int i = 0; i < nums.size(); i++)
        {

            if (tmp.find(target - nums.at(i)) != tmp.end())
            {
                return {tmp[target - nums.at(i)], i};
            }
            tmp[nums.at(i)] = i;
        }
        return {};

        

    }
};