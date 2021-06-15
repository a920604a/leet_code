class Solution
{
public:
    int myAtoi(string s)
    {
        int l = 0;
        int ret = 0;
        while (s[l] == ' ')
            l++;
        int flag = 1;
        if (s[l] == '-' || s[l] == '+')
        {
            flag = (s[l++] == '+') ? 1 : -1;
        }
        while (s[l] >= '0' && s[l] <= '9')
        {
            if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && s[l] - '0' > INT_MAX % 10))
            {
                return flag == 1 ? INT_MAX : INT_MIN;
            }
            ret = 10 * ret + (s[l++] - '0');
        }
        return flag * ret;
    }
};