/*
 * @Author: yuan
 * @Date: 2021-05-04 21:57:15
 * @LastEditTime: 2021-05-04 21:57:15
 * @FilePath: /C_plus/941_ValidMountainArray.cpp
 */
class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int i = 0;
        int n = arr.size();
        while (i < n - 1 && arr[i] < arr[i + 1])
            i++;
        if (i == 0 || i == n - 1)
            return false;
        while (i < n - 1 && arr[i] > arr[i + 1])
            i++;
        return i == n - 1;
    }
};