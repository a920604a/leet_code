class Solution
{
public:
    bool isPalindrome(string s)
    {
        // option 1 
        // string tmp = "";
        // for (char c : s)
        // {
        //     if (isalnum(c))
        //     {
        //         tmp += tolower(c);
        //     }
        // }
        // for (int i = 0; i < tmp.size(); ++i)
        //     cout << tmp[i];
        // cout << endl;
        // if (tmp.size() == 1)
        //     return true;
        // int stop = tmp.size() / 2;
        // for (int i = 0, j = tmp.size() - 1; i<stop, j> 0; i++, j--)
        // {
        //     if (tmp[i] != tmp[j])
        //         return false;
        // }
        // return true;

        // option 2
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if( !Isdigits(s[l]) ) l++;
            else if( !Isdigits(s[r]) ) r--;
            else if( (s[l]-'a' + 32)%32 !=(s[r]-'a' +32)%32  ) return false;
            else 
            {
                l++;
                r--;
            }
        }
        return true;
    }
    bool Isdigits(char c)
    {
        if(c>='0' && c<='9') return true;
        else if(c-'a' >= 0 && c-'a'<26 ) return true;
        else if(c-'A' >=0 && c-'A'<26) return true;
        else return false;
    }

};