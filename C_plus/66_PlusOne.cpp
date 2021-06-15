/*
 * @Author: yuan
 * @Date: 2021-04-08 08:15:02
 * @LastEditTime: 2021-04-08 09:03:16
 * @FilePath: /C_plus/66_PlusOne.cpp
 */
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> ret = digits;
        vector<int>::reverse_iterator iter;
        int sum = 0;
        for (iter = ret.rbegin(); iter != ret.rend(); iter++)
        {

            if (*iter == 9)
            {
                (*iter) = 0;
            }
            else
            {
                (*iter)++;
                break;
            }
        }
        if (ret.front() == 0)
            ret.insert(ret.begin(), 1);

        // for(int r:ret) cout<<r<<" ";

        return ret;
    }
};