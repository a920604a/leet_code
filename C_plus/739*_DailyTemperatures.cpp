class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> sta;
        int size = temperatures.size();
        vector<int> ret(size, 0);
        for (int i = 0; i < size; ++i)
        {
            while (!sta.empty() && temperatures[i] > temperatures[sta.top()])
            {
                int t = sta.top();
                sta.pop();
                ret[t] = i - t;
            }
            sta.push(i);
        }
        return ret;
    }
};