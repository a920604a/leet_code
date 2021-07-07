class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        // option 1 brute force O(n^2)
        //         vector<int> ret;
        //         for(int n:nums1){
        //             int i=0, next = -1;
        //             while(nums2[i]!=n) i++;

        //             for(i =i+1 ;i<nums2.size();i++){
        //                 if(nums2[i]>n){
        //                     next = nums2[i];
        //                     break;
        //                 }
        //             }
        //             ret.push_back(next);
        //         }
        //         return ret;

        // option 2  hash table value mapping index
        map<int, int> mp;
        vector<int> ret;
        for (int i = 0; i < nums2.size(); ++i)
            mp[nums2[i]] = i;

        for (int n : nums1)
        {

            int start = mp[n];
            int t = -1;
            for (int j = start + 1; j < nums2.size(); j++)
            {
                if (nums2[j] > n)
                {
                    t = nums2[j];
                    break;
                }
            }
            ret.push_back(t);
        }
        return ret;
    }
};