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


        // option 3
        // vector to recorder last index
         // O(n) time and O(1)  space
        int n = s.size();
        vector<int> vec(26,0);
        for(int i=0;i<n;++i){
            vec[s[i] - 'a'] = i;
        }
        for(int i=0;i<n;++i){
            if(vec[s[i]-'a'] == i){
                return i;
            }
            else{
                vec[s[i] - 'a'] = -1;
            }
        }
        return -1 ;

    }
};