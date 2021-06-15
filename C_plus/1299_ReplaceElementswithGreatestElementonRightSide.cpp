/*
 * @Author: yuan
 * @Date: 2021-05-05 19:47:54
 * @LastEditTime: 2021-05-05 19:48:15
 * @FilePath: /C_plus/1299_ReplaceElementswithGreatestElementonRightSide.cpp
 */
class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        if (arr.size() == 1)
            return {-1};
        vector<int> ret(arr.size(), -1);
        int _max = 0;
        for (int i = arr.size() - 1; i > 0; i--)
        {
            _max = max(_max, arr[i]);
            ret[i - 1] = _max;
        }
        return ret;
    }
};