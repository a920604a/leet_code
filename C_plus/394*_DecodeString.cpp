class Solution
{
public:
    string decodeString(string s)
    {
        // option 1
        // iterative + stack
        stack<int> nums;
        stack<string> strs;
        string t = "";
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                cnt = 10 * cnt + s[i] - '0';
            }
            else if (s[i] == '[')
            {
                nums.push(cnt);
                strs.push(t);
                t.clear();
                cnt = 0;
            }
            else if (s[i] == ']')
            {
                int k = nums.top();
                nums.pop();
                for (int j = 0; j < k; ++j)
                {
                    strs.top() += t;
                }
                t = strs.top();
                strs.pop();
            }
            else
            {
                // char
                t += s[i];
            }
        }

        return strs.empty() ? t : strs.top();

        // recursive + 自帶 stack
    }
};