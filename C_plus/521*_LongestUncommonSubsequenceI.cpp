class Solution
{
public:
    int findLUSlength(string a, string b)
    {

        // 情況一，兩字串相等，return -1
        // 情況二，兩字串不相等，return max(n,m)
        int n = a.size(), m = b.size();
        if (a == b)
            return -1;
        else
            return max(n, m);
    }
};