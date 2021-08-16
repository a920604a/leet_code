class Solution
{
public:
    vector<int> smallestRange(vector<vector<int> > &nums)
    {

        // [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]

        // [0,1],[4,0],[5,2],[9,1],[10,0],[12,1],[15,0],[18,2],[20,1],[22,2],[24,0],[26,0],[30,2]

        vector<pair<int, int> > v;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int n : nums[i])
                v.push_back(make_pair(n, i));
        }
        sort(v.begin(), v.end());
        // 對 v 做 Minimum Window Substring
        int l = 0, valid = 0;
        vector<int> ret;
        int diff = INT_MAX;
        unordered_map<int, int> window; // index 0-2 mapping freq
        for (int r = 0; r < v.size(); r++)
        {
            auto c = v[r];

            if (window[c.second] == 0)
                valid++;

            window[c.second]++;

            while (valid == n && l <= r)
            {
                if (v[r].first - v[l].first < diff)
                {
                    diff = v[r].first - v[l].first;
                    ret = {v[l].first, v[r].first};
                }
                auto d = v[l++];

                window[d.second]--;
                if (window[d.second] == 0)
                    valid--;
            }
        }
        return ret;
    }
};