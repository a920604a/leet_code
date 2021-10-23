class Solution
{
public:
    string reverseWords(string s)
    {
        int l = 0, n = s.size();
        while (l < n && s[l] == ' ')
            l++;
        int r = l;
        int last = n - 1;
        while (s[last] == ' ')
            last--;
        vector<string> ret;
        for (int i = r; i <= last; ++i)
        {
            if (s[i] == ' ')
            {
                ret.push_back(s.substr(l, i - l));
                while (s[i] == ' ')
                    i++;
                l = i;
            }
        }
        ret.push_back(s.substr(l, last - l + 1));
        string ans;

        reverse(ret.begin(), ret.end());
        for (string str : ret)
            ans += str + ' ';
        return ans.substr(0, ans.size() - 1);
        


        //option 2 
        int n = s.size();
        reverse(s.begin(), s.end());
        string ret;
        int l=0, r=n-1;
        while(l<r && s[l]==' ') l++;
        while(l<r && s[r]==' ') r--;
        for(int i=l;i<=r;++i){            
            if(s[i]==' '){
                string temp = s.substr(l, i-l);
                reverse(temp.begin(), temp.end());
                ret += temp + ' ';
                while(i<=r && s[i]==' ') i++;
                l=i;
            }
        }
        string temp = s.substr(l, r+1-l);
        
        reverse(temp.begin(), temp.end());
        ret+=temp;
        return ret;

    }
};