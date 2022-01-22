class Solution
{
public:
    void traverse(int r, int l, string path, vector<string> &ret)
    {
        if (l > r || l < 0 || r < 0)
            return;
        if (l == 0 && r == 0)
        {
            ret.push_back(path);
            return;
        }

        path.push_back('(');
        traverse(r, l - 1, path, ret);
        path.pop_back();

        path.push_back(')');
        traverse(r - 1, l, path, ret);
        path.pop_back();
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ret;
        string r = "";
        traverse(n, n, r, ret);
        return ret;
    }
};