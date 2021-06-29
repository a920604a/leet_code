class Solution
{
public:
    string removeDuplicates(string s)
    {
        // option 1 use stack to store O(n)
        //         stack<char> c;

        //         for(int i=0;i<s.size();i++){
        //             if(c.empty() || c.top()!=s[i]) c.push(s[i]);
        //             else if(c.top()==s[i]) c.pop();
        //         }
        //         string ret;
        //         while(!c.empty()){
        //             ret = c.top()+ret;
        //             c.pop();
        //         }
        //         return ret;

        // option 2 simplify option 1 without stack
        //         string ret = "";
        for (char c : s)
        {
            if (ret.empty() || ret.back() != c)
                ret += c;
            else if (ret.back() == c)
                ret.pop_back();
        }

        return ret;

        // option 3 two point
        // int n = s.size(), i = 0;
        // for (int j = 0; j < n; ++j, ++i) {
        //     cout<<j<<" ";
        //     s[i] = s[j];
        //     if (i > 0 && s[i - 1] == s[i]) i -= 2;
        // }
        // return s.substr(0, i);
    }
};