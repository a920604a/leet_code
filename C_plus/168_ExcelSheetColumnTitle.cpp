class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        int n = columnNumber;
        string ret = "";
        while (n)
        {
            n--;
            char c = 'A' + (n % 26);
            ret = c + ret;
            n /= 26;
        }
        return ret;
    }
};