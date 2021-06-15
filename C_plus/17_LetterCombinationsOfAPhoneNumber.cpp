class Solution
{
public:
    map<int, string> dict = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}};
    vector<string> ret;
    void dfs(string s, int cur, string temp)
    {
        if (cur >= 0)
        {
            for (char c : dict[s[cur] - '0'])
            {
                dfs(s, cur - 1, c + temp);
            }
        }
        else
        {
            ret.push_back(temp);
            return;
        }
    }
    vector<string> letterCombinations(string digits)
    {
        int n = digits.length();
        if (n <= 0)
            return ret;
        dfs(digits, n - 1, "");
        return ret;
    }
};