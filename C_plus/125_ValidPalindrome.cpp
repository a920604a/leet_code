class Solution
{
public:
    bool isPalindrome(string s)
    {
        string tmp = "";
        for (char c : s)
        {
            if (isalnum(c))
            {
                tmp += tolower(c);
            }
        }
        for (int i = 0; i < tmp.size(); ++i)
            cout << tmp[i];
        cout << endl;
        if (tmp.size() == 1)
            return true;
        int stop = tmp.size() / 2;
        for (int i = 0, j = tmp.size() - 1; i<stop, j> 0; i++, j--)
        {
            if (tmp[i] != tmp[j])
                return false;
        }
        return true;
    }
};