class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // https://web.stanford.edu/class/cs9/sample_probs/Anagrams.pdf

        // option 1 sorted O(nlogn)

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s==t;

        // option 2 Counting O(n^2) time out
        // if(s.size()!=t.size()) return false;
        // for(char c:s){
        //     if( countchar(c,s) != countchar(c,t)) return false;
        // }
        // return true;

        // improved option 2 Counting O(n)
        if (s.size() != t.size())
            return false;
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (countchar(c, s) != countchar(c, t))
                return false;
        }
        return true;

        // option 3  Histogramming
        // O(n) time and O(1) space
        //         vector<int> vec(26,0);
        //         if(s.size()!=t.size()) return false;
        //         int n = s.size();
        //         for(int i=0;i<n;++i) vec[ s[i] - 'a' ]++;
        //         for(int i=0;i<n;++i) vec[t[i] -'a']--;
        //         return vec==vector<int>(26,0);
    }
    int countchar(char c, string s)
    {
        int ret = 0;
        for (char cc : s)
            ret += (c == cc) ? 1 : 0;
        return ret;
    }
};