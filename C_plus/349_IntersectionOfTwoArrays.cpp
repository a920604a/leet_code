/*
 * @Author: yuan
 * @Date: 2021-05-02 12:05:39
 * @LastEditTime: 2021-05-02 12:05:40
 * @FilePath: /C_plus/349_IntersectionOfTwoArrays.cpp
 */
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s;
        set<int> n(nums1.begin(), nums1.end());
        for (int i : nums2)
        {
            if (n.find(i) != n.end())
                s.insert(i);
        }

        return vector<int>(s.begin(), s.end());
    }
};