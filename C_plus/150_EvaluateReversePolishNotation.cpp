class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        // O(n)
        stack<int> sta;
        for (string str : tokens)
        {
            if (!(str == "+" || str == "-" || str == "*" || str == "/"))
                sta.push(stoi(str));

            else
            {
                int b = sta.top();
                sta.pop();
                int a = sta.top();
                sta.pop();
                int tmp;
                if (str == "+")
                    tmp = a + b;
                else if (str == "-")
                    tmp = a - b;
                else if (str == "*")
                    tmp = a * b;
                else if (str == "/")
                    tmp = a / b;
                sta.push(tmp);
            }
        }

        return sta.top();
    }
};