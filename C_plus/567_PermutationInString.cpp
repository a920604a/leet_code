/*
 * @Author: yuan
 * @Date: 2021-05-04 15:42:59
 * @LastEditTime: 2021-05-04 15:43:00
 * @FilePath: /C_plus/567_PermutationInString.cpp
 */
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> count_arr(26, 0);
        vector<int> ret(26, 0);

        for (int i = 0; i < s1.size(); ++i)
            ret[s1[i] - 'a']++;

        for (int i = 0; i < s2.size(); ++i)
        {
            count_arr[s2[i] - 'a']++;
            if (i >= s1.size())
                count_arr[s2[i - s1.size()] - 'a']--;
            if (count_arr == ret)
                return true;
        }
        return false;
    }
};