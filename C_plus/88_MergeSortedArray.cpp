/*
 * @Author: yuan
 * @Date: 2021-04-08 13:51:45
 * @LastEditTime: 2021-04-08 13:51:45
 * @FilePath: /C_plus/88_MergeSortedArray.cpp
 */
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = m, j = 0; i < nums1.size(), j < nums2.size(); j++, i++)
        {
            nums1[i] = nums2[j];
        }
        for (int n : nums1)
            cout << n << " ";
        //sorted nums1
        for (int i = m; i < nums1.size(); ++i)
        {
            int key = nums1[i];
            int j = i - 1;
            while (j >= 0 && nums1[j] > key)
            {
                nums1[j + 1] = nums1[j];
                j--;
            }
            nums1[j + 1] = key;
        }
    }
};