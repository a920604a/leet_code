class Solution
{
public:
    void traverse(string num, int target, long diff, long curNum, string out, vector<string> &ret)
    {

        if (num.size() == 0 && curNum == target)
        {
            ret.push_back(out);
            return;
        }

        for (int i = 1; i <= num.size(); ++i)
        {
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0')
                return;

            string next = num.substr(i);
            if (out.size() > 0)
            {
                traverse(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, ret);
                traverse(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, ret);
                traverse(next, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur, ret);
            }
            else
            {
                traverse(next, target, stoll(cur), stoll(cur), cur, ret);
            }
        }
    }
    vector<string> addOperators(string num, int target)
    {
        vector<string> ret;
        traverse(num, target, 0, 0, "", ret);
        return ret;
    }
};