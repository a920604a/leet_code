/*
 * @Author: yuan
 * @Date: 2021-05-02 11:22:17
 * @LastEditTime: 2021-05-02 11:22:26
 * @FilePath: /C_plus/287_FindDuplicateNumber.cpp
 */
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // int n = nums.size()-1;
        // vector<int> v(n,0);
        // for(int i:nums){
        //     if(v[i-1]>=1) return i;
        //     v[i-1]++;
        // }
        // return -1;
        set<int> s;
        for (int i : nums)
        {
            if (s.find(i) == s.end())
                s.insert(i);
            else
                return i;
        }
        return -1;
    }
};