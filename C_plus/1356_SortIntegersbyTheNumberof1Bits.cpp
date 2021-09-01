class Solution
{
public:
    static int count(int n)
    {
        int ret = 0;
        while (n)
        {
            ret++;
            n = n & (n - 1);
        }
        return ret;
    }
    static bool cmp(int a, int b)
    {
        int ca = count(a), cb = count(b);
        if (ca == cb)
            return a < b;
        return ca < cb;
    }
    vector<int> sortByBits(vector<int> &arr)
    {
        // O(nlogn) time and O(1) time
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};