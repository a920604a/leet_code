class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        // option 1
        //         vector<int> v(26,0);
        //         for(char c:s) v[c-'a']++;

        //         for(char c:t){
        //             v[c-'a']--;
        //         }
        //         for(int i=0;i<26;++i){
        //             if(v[i]!=0) {
        //                 return char(i+'a');
        //             }
        //         }
        //         return ' ';

        // option 2 ret ^a;
        // int ret = 0;
        // for(char c:s) ret ^= (c-'a');
        // for(char c:t) ret ^= (c-'a');
        // return char(ret+'a');

        // option 3 用減法，ascii 字母分別代表個字的數字
        char ret = 0;
        for (char c : s)
            ret -= c;
        for (char c : t)
            ret += c;
        return ret;
    }
};