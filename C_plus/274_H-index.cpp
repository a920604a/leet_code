class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int count = 0, n = citations.size();
        sort(citations.begin(), citations.end(), greater<>());
        for (int i = 0; i < n; ++i)
        {
            count += (citations[i] >= i + 1) ? 1 : 0;
        }
        return count;
    }
};