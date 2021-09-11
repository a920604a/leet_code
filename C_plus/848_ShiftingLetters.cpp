class Solution
{
public:
    char shift(char c, int n)
    {
        int a = (c - 'a' + n) % 26;
        return char(a + 'a');
    }
    string shiftingLetters(string s, vector<int> &shifts)
    {
        //prefix sum
        if (shifts.empty())
            return "";
        int n = shifts.size();
        //  3   5   9
        //  17  14  9

        for (int i = n - 2; i > -1; i--)
        {
            shifts[i] = (shifts[i + 1] + shifts[i]) % 26;
        }

        string ret;
        for (int i = 0; i < n; ++i)
        {
            ret += shift(s[i], shifts[i]);
        }
        return ret;
    }
};