class Solution
{
public:
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res)
    {
        if (left > right)
            return;
        if (left == 0 && right == 0)
            res.push_back(out);
        else
        {
            if (left > 0)
                generateParenthesisDFS(left - 1, right, out + '(', res);
            if (right > 0)
                generateParenthesisDFS(left, right - 1, out + ')', res);
        }
    }

    vector<string> generateParenthesis(int n)
    {

        // option 1
        vector<string> ret;
        generateParenthesisDFS(n, n, "", ret);
        return ret;
    }
};


