class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        // option 1 先串起來在用插入排序 O(n^2) time

        //         for(int i=m, j=0;i<nums1.size(), j<n;++i,++j){
        //             nums1[i] = nums2[j];
        //         }

        //         for(int i =m;i<nums1.size();++i){
        //             int key = nums1[i];
        //             int j = i-1;
        //             while( j>-1 && key<nums1[j]){
        //                 nums1[j+1] = nums1[j];
        //                 j--;
        //             }
        //             nums1[j+1] = key;
        //         }

        // option 2 Merge sort , O(a+b) time and O(a+b) space
        vector<int> nums(m + n, 0);

        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                nums[k++] = nums1[i];
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                nums[k++] = nums2[j];
                j++;
            }
        }

        while (i < m)
            nums[k++] = nums1[i++];
        while (j < n)
            nums[k++] = nums2[j++];
        nums1 = nums;
    }
};