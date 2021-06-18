class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        // option 1
        // 串起來
        int j = 0;
        for (int i = m; i < nums1.size(); ++i)
        {
            nums1[i] = nums2[j++];
        }
        for (int n : nums1)
            cout << n << " ";

        // insert sort
        for (int i = m; i < nums1.size(); ++i)
        {
            int key = nums1[i];
            int j = i - 1;
            while (j > -1 && nums1[j] > key)
            {
                nums1[j + 1] = nums1[j];
                j--;
            }
            nums1[j + 1] = key;
        }
    }
};