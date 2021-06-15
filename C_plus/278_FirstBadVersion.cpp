/*
 * @Author: yuan
 * @Date: 2021-05-02 10:02:54
 * @LastEditTime: 2021-05-02 10:03:03
 * @FilePath: /C_plus/278_FirstBadVersion.cpp
 */
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};