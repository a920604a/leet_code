/*
 * @Author: yuan
 * @Date: 2021-05-04 14:10:10
 * @LastEditTime: 2021-05-04 14:10:10
 * @FilePath: /C_plus/540_SingleElementinaSortedArray.cpp
 */
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        // int ret=0;
        // map<int,int>m;
        // for(int n:nums){
        //     m[n]++;
        // }
        // for(auto mp:m){
        //     if(mp.second==1) return mp.first;
        // }
        // return -1;

        int ret = 0;
        if (nums.size() == 1)
            return nums[0];
        for (int i = 0; i < nums.size() - 2; i += 2)
        {
            if (nums[i] != nums[i + 1])
                return nums[i];
        }
        return nums[nums.size() - 1];
    }
};