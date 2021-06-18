class Solution
{
public:
    // permutation
    map<int, string> dict = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}};

    void dfs(string digits, int cur, string cand, vector<string> &ret)
    {
        if (cur >= 0)
        {
            for (char c : dict[digits[cur] - '0'])
            {
                dfs(digits, cur - 1, c + cand, ret);
            }
        }

        else
        {
            ret.push_back(cand);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        int n = digits.length();
        vector<string> ret;
        if (n <= 0)
            return ret;
        dfs(digits, n - 1, "", ret);
        return ret;
    }
};