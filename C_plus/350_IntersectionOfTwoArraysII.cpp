class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        // option 1
        // O(1000*1000)

        //         vector<int> ret1(1001,0); // record frequency
        //         vector<int> ret2(1001,0); // record frequency
        //         for(int n:nums1) ret1[n]++;
        //         for(int n:nums2) ret2[n]++;

        //         vector<int> ret;
        //         for(int i=0;i<ret1.size();++i){
        //             if(ret1[i]>0 && ret2[i]>0){
        //                 int freq = min(ret1[i], ret2[i]);
        //                 while(freq){
        //                     freq--;
        //                     ret.push_back(i);
        //                 }
        //             }
        //         }
        //         return ret;

        // option 2 O(n) time and O(n) space
        // make use to map instead of two vector
        vector<int> ret;
        unordered_map<int,int> m;
        for(int n:nums1) m[n]++;
        for(int n:nums2){
            if(m[n]>0){
                ret.push_back(n);
                m[n]--;
            }
        }
        return ret;

        // option 2.2 one vector 
        vector<int> his(1000,0);
        vector<int> ret;
        for(int n:nums1) his[n]++;
        for(int n:nums2){
            if(his[n]>0){
                ret.push_back(n);
                his[n]--;
            }
        }
        return ret;



        // option 3
        // use two pointer O(n)
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int l = 0, r = 0;
        vector<int> ret;
        while (l < nums1.size() && r < nums2.size())
        {
            if (nums1[l] == nums2[r])
            {
                ret.push_back(nums1[l]);
                l++;
                r++;
            }
            else if (nums1[l] > nums2[r])
                r++;
            else
                l++;
        }
        return ret;
    }
};