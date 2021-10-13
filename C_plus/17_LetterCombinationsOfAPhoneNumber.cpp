class Solution
{
public:
    void dfs(string digits, int i, unordered_map<int, string> mp, vector<string> &ret, string path)
    {
        if (i == digits.size())
        {
            ret.push_back(path);
            return;
        }
        for (char c : mp[digits[i] - '0'])
        {
            dfs(digits, i + 1, mp, ret, path + c);
        }
    }
    vector<string> letterCombinations(string digits)
    {

        unordered_map<int, string> mp = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}};

        // DFS
        // vector<string> ret;
        // if(digits.size() ==0) return ret;
        // dfs(digits, 0, mp, ret,"");
        // return ret;

        queue<string> q;
        vector<string> ret;
        if (digits.size() == 0)
            return ret;
        for (char c : mp[digits[0] - '0'])
        {
            string d;
            d.push_back(c);
            q.push(d);
        }

        for (int i = 1; i < digits.size(); ++i)
        {
            int size = q.size();
            for (int j = 0; j < size; ++j)
            {
                string c = q.front();
                q.pop();
                for (char d : mp[digits[i] - '0'])
                {
                    string temp = c;
                    temp.push_back(d);
                    q.push(temp);
                }
            }
        }
        // copy queue to ret
        while (!q.empty())
        {
            string d = q.front();
            ret.push_back(d);
            q.pop();
        }

        return ret;
    }
};