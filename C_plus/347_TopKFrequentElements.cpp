class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // option 1
        unordered_map<int, int> m;
        vector<int> ret;
        priority_queue<pair<int, int> > pq;

        for (int i = 0; i < nums.size(); ++i)
            m[nums[i]]++;

        for (auto a : m)
            pq.push(make_pair(a.second, a.first));

        while (!pq.empty() && k)
        {
            ret.emplace_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ret;
    }
};