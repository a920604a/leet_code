class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        // option  O(n^2)
        // vector<int> vec(26,0);
        // int n = s1.size(), n2 = s2.size();
        // if(n>n2) return false;
        // for(char c:s1) vec[c-'a']++;
        // for(int i=0;i<=s2.size()-n;++i){
        //     vector<int> tmp(26,0);
        //     for(int j=i;j<i+n;++j)    tmp[s2[j]-'a']++;
        //     if(tmp==vec) return true;
        // }
        // return false;

        // option2 O(n ^ 2) simplify version option 1 
        vector<int> v(26, 0);
        vector<int> ret(26, 0);
        for (char c : s1)
            ret[c - 'a']++;
        for (int i = 0; i < s2.size(); ++i)
        {
            v[s2[i] - 'a']++;
            if (i >= s1.size())
                v[s2[i - s1.size()] - 'a']--;
            if (v == ret)
                return true;
        }
        return false;
    }
};