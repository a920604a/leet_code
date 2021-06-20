class Solution
{
public:
    int firstUniqChar(string s)
    {

        // option 1
        // map<char , int> m;
        // for(int i=0;i<s.size();++i){
        //     if(m.find(s[i])==m.end()) m[s[i]] = i;
        //     else m[s[i]] = s.size();
        // }
        // for(char a:s){
        //     if(m.find(a)!=m.end() && m[a]!=s.size()) return m[a];
        // }
        // return -1;

        // option 1 v2
        // map<char, int> m;
        // for(char c:s) m[c]++;
        // for(int i=0;i<s.size();++i){
        //     if(m[s[i]]==1) return i;
        // }
        // return -1;

        // option 2
        vector<int> v(26, 0);
        for (char c : s)
            v[c - 'a']++;
        for (int i = 0; i < s.size(); ++i)
        {
            if (v[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};