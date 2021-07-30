class Solution
{
public:
    int helper(vector<char> &s)
    {
        stack<int> stack;

        int rs = 0;
        int sign = 1;
        stack.push(1);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;
            else if (s[i] == '(')
            {
                stack.push(stack.top() * sign);
                sign = 1;
            }
            else if (s[i] == ')')
                stack.pop();
            else if (s[i] == '+')
                sign = 1;
            else if (s[i] == '-')
                sign = -1;
            else
            {
                int temp = s[i] - '0';
                // while (i + 1 < s.size() && isdigit(s[i + 1] ))
                while (i < s.size() && s[i] >= '0')
                    temp = 10 * temp + s[i++] - '0';
                rs += sign * stack.top() * temp;
            }
        }
        return rs;
    }
    int calculate(string s)
    {

        // convert string to int
        // int n = 0;
        // for(char c:s){
        //     n = 10* n + (c-'0');
        // }

        //         vector<char> ret(s.begin(), s.end());

        //         return helper(ret);
        stack<int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s)
        {
            if (isdigit(c))
            {
                if (num >= (INT_MAX) / 10)
                    num = INT_MAX;
                else
                    num = num * 10 + c - '0';
            }
            else
            {
                rst += sign * num;
                num = 0;
                if (c == '+')
                    sign = 1;
                if (c == '-')
                    sign = -1;
                if (c == '(')
                {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size())
                {
                    rst = ops.top() * rst + nums.top();
                    ops.pop();
                    nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};