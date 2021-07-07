class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        //         vector<int> v(26,0);
        //         vector<int >ret;
        //         if(p.size()>s.size()) return ret;
        //         for(char c:p) v[c-'a']++;
        //         for(int i=0;i<=s.size()-p.size();++i){
        //             vector<int> tmp(26,0);
        //             for(int j=0;j<p.size();++j) tmp[s[i+j]-'a'] ++;

        //             if(v==tmp) ret.push_back(i);

        //         }
        //         return ret;

        vector<int> pv(26, 0);
        vector<int> sv(26, 0);
        vector<int> ret;
        if (s.size() < p.size())
            return ret;
        for (int i = 0; i < p.size(); ++i)
        {
            pv[p[i] - 'a']++;
            sv[s[i] - 'a']++;
        }
        // for(int i:sv) cout<<i<<" ";
        // cout<<endl;
        // for(int i:pv) cout<<i<<" ";

        if (sv == pv)
            ret.push_back(0);
        for (int i = p.size(); i < s.size(); ++i)
        {

            sv[s[i] - 'a']++;
            sv[s[i - p.size()] - 'a']--;

            if (sv == pv)
                ret.push_back(i - p.size() + 1);
        }
        return ret;
    }
};