class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> ret;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                ret.push(c);
            }
            else
            {
                if (ret.empty())
                    return false;
                else if (c == ')' && ret.top() == '(')
                    ret.pop();
                else if (c == ']' && ret.top() == '[')
                    ret.pop();
                else if (c == '}' && ret.top() == '{')
                    ret.pop();
                else
                    return false;
            }
        }
        return ret.empty() ? true : false;
    }
};