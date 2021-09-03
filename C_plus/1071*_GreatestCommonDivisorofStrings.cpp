class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a == b)
            return a;
        if (a > b)
            return gcd(a - b, a);
        return gcd(a, b - a);
    }
    string gcdOfStrings(string str1, string str2)
    {
        // 找 兩字串長度的最大公因數

        // option 1 iterative
        if (str1 + str2 != str2 + str1)
            return "";
        int a = str1.size(), b = str2.size();

        while (a != b)
        {
            if (a < b)
            {
                b = b - a;
            }
            else if (a > b)
            {
                int tmp = a;
                a = a - b;
                b = tmp;
            }
        }

        return str1.substr(0, a);

        // option 2 recursive
        // if(str1 + str2 != str2 + str1) return "";
        // int a = str1.size(), b = str2.size();
        // int g = gcd(a, b);
        // return str1.substr(0,g);
    }
};