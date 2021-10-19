class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int highest = 0, cur = 0;
        for (int n : gain)
        {
            cur += n;
            highest = max(cur, highest);
        }
        return highest;
    }
};