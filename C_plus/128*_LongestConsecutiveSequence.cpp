class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // option 1 cheat O(nlogn)
        // if(nums.empty()) return 0;
        // if(nums.size()==1) return 1;
        // sort(nums.begin(), nums.end());
        // set<int> s(nums.begin(), nums.end());
        // vector<int> v(s.begin(), s.end()) ;
        // int ret =1, cs=1;
        // for(int i=1;i<v.size();i++){
        //     if(v[i]==v[i-1]+1){
        //         cs++;
        //         ret = max(ret, cs);
        //     }
        //     else cs = 1;
        // }
        // return ret;

        // option 2 hash table O(n)
        // set<int> s(nums.begin(), nums.end());
        // int ret = 0;
        // for(int n:nums){
        //     if(s.find(n)==s.end()) continue; // comment to faster
        //     s.erase(n);
        //     int pre = n-1;
        //     int next = n+1;
        //     while(s.find(pre)!=s.end()) s.erase(pre--);
        //     while(s.find(next)!=s.end()) s.erase(next++);
        //     int count = next-pre-1;
        //     ret = max(ret, count);
        // }
        // return ret;

        // option 3 hash table 擴散
        unordered_map<int, int> m;
        int ret = 0;
        for (int n : nums)
        {
            if (m.find(n) != m.end())
                continue;
            int left = m.count(n - 1) ? m[n - 1] : 0;
            int right = m.count(n + 1) ? m[n + 1] : 0;
            int sum = left + right + 1;
            cout << sum << endl;
            m[n] = sum;
            ret = max(ret, sum);
            // update hash table
            m[n - left] = sum;
            m[n + right] = sum;
        }
        return ret;
    }
};