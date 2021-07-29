class Solution
{
public:
    string smallestSubsequence(string s)
    {
        vector<int> count(256, 0);
        vector<bool> instack(256, false);
        stack<int> sta;

        for (char c : s)
            count[c]++;

        for (char c : s)
        {
            count[c]--;

            if (instack[c])
                continue;

            while (!sta.empty() && sta.top() > c)
            {
                if (count[sta.top()] == 0)
                    break;
                instack[sta.top()] = false;
                sta.pop();
            }

            instack[c] = true;
            sta.push(c);
        }

        string ret;
        while (!sta.empty())
        {
            ret.insert(ret.begin(), sta.top());
            sta.pop();
        }
        return ret;
    }
};