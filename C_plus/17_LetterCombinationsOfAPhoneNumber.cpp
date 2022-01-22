class Solution
{
public:
    void traverse(string digits, unordered_map<int, string> &dict, vector<string> &ret, string str, int l)
    {

        if (digits.size() == str.size())
        {
            ret.push_back(str);
            return;
        }

        for (char c : dict[digits[l] - '0'])
        {
            traverse(digits, dict, ret, str + c, l + 1);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        // DFS
        //         vector<string> ret;
        //         string str;

        //         unordered_map<int, string> dict = {
        //             {2, "abc"},{3, "def"}, {4,"ghi"}, {5,"jkl"}, {6,"mno"}, {7,"pqrs"}, {8,"tuv"}, {9,"wxyz"}
        //         };
        //         if(digits.empty()) return ret;
        //         traverse(digits,dict, ret, str, 0);
        //         return ret;

        queue<string> q;
        unordered_map<int, string> dict = {
            {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        for (char c : dict[digits[0] - '0'])
        {
            string d;
            d.push_back(c);
            q.push(d);
        }

        vector<string> ret;
        for (int i = 1; i < digits.size(); ++i)
        {
            int size = q.size();
            for (int j = 0; j < size; ++j)
            {
                string temp = q.front();
                q.pop();
                for (char c : dict[digits[i] - '0'])
                    q.push(temp + c);
            }
        }
        while (!q.empty())
        {
            string s = q.front();
            q.pop();
            ret.push_back(s);
        }
        return ret;
    }
};