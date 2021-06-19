class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // option 1 use map
        //         map <char,int> m1, m2;
        //         for(int i=0;i<s.size();++i){
        //             if(m1[s[i]]!=m2[t[i]]) return false;

        //             m1[s[i]] = i+1;
        //             m2[t[i]] = i+1;

        //         }
        //         return true;

        //option 2  use vector, faster
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};