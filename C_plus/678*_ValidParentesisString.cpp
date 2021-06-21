class Solution
{
public:
    bool checkValidString(string s)
    {
        // record index
        stack<int> sta, star;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                sta.push(i);
            else if (s[i] == '*')
                star.push(i);
            else
            {
                if (sta.empty() && star.empty())
                    return false;
                else if (!sta.empty())
                    sta.pop();
                else
                    star.pop();
            }
        }

        while (!sta.empty() && !star.empty())
        {
            if (sta.top() > star.top())
                return false;
            sta.pop();
            star.pop();
        }
        return sta.empty();
    }
};