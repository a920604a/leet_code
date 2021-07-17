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

        // option 2
        // int size = nums2.size();
        // vector<int> dp(size, -1);

        // for(int i=0;i<size;++i){
        //     int t = -1;
        //     for(int j = i+1;j<size;++j){
        //         if(nums2[j]>nums2[i]){
        //             t = nums2[j];
        //             break;
        //         }
        //     }
        //     dp[i] = t;
        // }
        // for(int d:dp) cout<<d<<" ";
        // vector<int> ret;
        // for(int n:nums1){
        //     int t=-1;
        //     for(int j=0;j<size;++j){
        //         if(n==nums2[j]){
        //             t= dp[j];
        //             break;
        //         }
        //     }
        //     ret.push_back(t);

        // }
        // return ret;

        // option 3 hash table value mapping index
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
        
        // option 4 mono stack
        stack<int> sta;
        int size = nums2.size();
        vector<int> mono(size,-1);
        
        for(int i=0;i<size;++i){
            while(!sta.empty() && nums2[i]> nums2[sta.top()]){
                int t = sta.top();
                sta.pop();
                mono[t] = nums2[i];
            }
            sta.push(i);
        }
        for(int m:mono) cout<<m<<" ";
        
        vector<int> ret;
        for(int i =0;i<nums1.size();++i){
            vector<int>::iterator it =  std::find(nums2.begin(), nums2.end(), nums1[i]);
            int idx = std::distance(nums2.begin(), it);
            ret.push_back(mono[idx]);
            
        }
        return ret;
    }
};