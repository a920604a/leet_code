class Solution
{
public:
    bool isValid(string s)
    {
        
        stack<char> sta;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                sta.push(c);

            else
            {
                if (sta.empty())
                    return false;
                else if (c == ')' && sta.top() == '(')
                    sta.pop();
                else if (c == ']' && sta.top() == '[')
                    sta.pop();
                else if (c == '}' && sta.top() == '{')
                    sta.pop();
                else
                    return false;
            }
        }
        return sta.empty() ? true : false;
    }
};