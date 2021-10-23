class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int n = num1.size(), m = num2.size();
        vector<int> ret(n + m, 0);
        int carry = 0;
        for (int i = n - 1; i > -1; i--)
        {
            for (int j = m - 1; j > -1; j--)
            {
                int p1 = i + j, p2 = i + j + 1;
                int mul = (num1[i] - '0') * (num2[j] - '0') + ret[p2];
                ret[p2] = mul % 10;
                ret[p1] += mul / 10;
            }
        }
        string ans;
        int i = 0;
        while (i < ret.size() && ret[i] == 0)
            i++;
        for (int j = i; j < ret.size(); ++j)
            ans += ret[j] + '0';
        return ans == "" ? "0" : ans;
    }
};
;
