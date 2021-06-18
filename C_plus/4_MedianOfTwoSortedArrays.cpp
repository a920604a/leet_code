class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // option 1  O(n^2)
        int size = nums1.size() + nums2.size();
        vector<int> merge(size, 0);
        double ret = 0.0;
        for (int i = 0; i < nums1.size(); ++i)
            merge[i] = nums1[i];
        for (int i = nums1.size(); i < merge.size(); ++i)
            merge[i] = nums2[i - nums1.size()];

        // sort(merge.begin(), merge.end());
        for (int j = nums1.size(); j < merge.size(); ++j)
        {
            int key = merge[j];
            int k = j - 1;
            while (k > -1 && merge[k] > key)
            {
                merge[k + 1] = merge[k];
                k--;
            }
            merge[k + 1] = key;
        }

        if (merge.size() % 2 == 1)
        {
            ret = merge[size / 2];
        }
        else
        {
            ret += merge[size / 2 - 1];
            ret += merge[size / 2];
            ret /= 2;
        }

        return ret;

        // option 2 two-pointer O(log (m+n))
        //         vector<int> merge;
        //         int l = 0, r = 0;
        //         while(l<nums1.size() && r<nums2.size()){
        //             if( nums1[l] <= nums2[r]){
        //                 merge.push_back(nums1[l]);
        //                 l++;
        //             }
        //             else{
        //                 merge.push_back(nums2[r]);
        //                 r++;
        //             }
        //         }
        //         if(l<nums1.size()){
        //             while(l<nums1.size()){
        //                 merge.push_back(nums1[l]);
        //                 l++;
        //             }
        //         }
        //         if(r<nums2.size()){
        //             while(r<nums2.size()){
        //                 merge.push_back(nums2[r]);
        //                 r++;
        //             }
        //         }

        //         int size = merge.size();
        //         double ret = 0;
        //         if(size%2==1) ret = merge[size/2];
        //         else{
        //             ret += merge[size/2-1];
        //             ret += merge[size/2];
        //             ret /=2;
        //         }
        //         return ret;
    }
};