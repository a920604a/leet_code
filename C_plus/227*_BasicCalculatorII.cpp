class Solution
{
public:
    int helper(vector<char> &s)
    {
        // O(N) time O(1) space

        stack<int> sta;

        int num = 0;
        char sign = '+';
        int idx = 0;
        // while(s.size() > 0){

        // char c = s.front();
        // s.erase(s.begin());
        while (idx < s.size())
        {
            char c = s[idx++];

            if (isdigit(c))
            {
                num = 10 * num + int(c - '0');
            }

            // if( (!isdigit(c) && c!=' ') || (s.size()==0) ){
            if ((!isdigit(c) && c != ' ') || (s.size() == idx))
            {

                if (sign == '+')
                {
                    sta.push(num);
                }
                else if (sign == '-')
                {
                    sta.push(-num);
                }
                else if (sign == '*')
                {
                    sta.top() = sta.top() * num;
                }
                else if (sign == '/')
                {
                    sta.top() = (int)(sta.top() / float(num));
                }
                num = 0;
                sign = c;
            }
        }

        int sum_of_elems = 0;
        while (!sta.empty())
        {
            sum_of_elems += sta.top();
            sta.pop();
        }

        return sum_of_elems;
    }

    int calculate(string s)
    {
        vector<char> ret(s.begin(), s.end());

        return helper(ret);
    }
};