/*
 * @Author: yuan
 * @Date: 2021-05-05 20:11:13
 * @LastEditTime: 2021-05-05 20:11:25
 * @FilePath: /C_plus/1346_CheckIfNandItsDoubleExist.cpp
 */
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        set<int> s;
        for (int n : arr)
        {
            if (s.find(n * 2) != s.end() || (n % 2 == 0 && s.find(n / 2) != s.end()))
                return true;
            s.insert(n);
        }
        return false;
    }
};