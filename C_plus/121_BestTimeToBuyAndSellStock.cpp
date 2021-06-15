class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ret = 0;
        int _min = INT_MAX;
        for (int i = 0; i < prices.size(); ++i)
        {
            _min = min(_min, prices[i]);
            ret = max(ret, prices[i] - _min);
        }
        return ret;
    }
};