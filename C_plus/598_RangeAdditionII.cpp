class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int> > &ops)
    {

        // option 1
        if (ops.empty())
            return m * n;
        int a = m, b = n;
        for (vector<int> op : ops)
        {
            a = min(op[0], a);
            b = min(op[1], b);
        }
        return a * b;
    }
};