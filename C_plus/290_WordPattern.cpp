class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {

        vector<string> words;
        int j = 0;
        s += ' ';
        while (s[j] == ' ')
            j++;
        for (int i = j; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                words.push_back(s.substr(j, i - j));
                while (i < s.size() && s[i] == ' ')
                    i++;
                j = i;
            }
        }
        // for(string w:words) cout<<w<<endl;
        if (pattern.size() != words.size())
            return false;

        j = 0;
        unordered_map<char, string> mp;
        unordered_map<string, char> mpi;

        for (int i = 0; i < pattern.size(); ++i)
        {
            if (mp.count(pattern[i]) || mpi.count(words[i]))
            {
                if (mpi[words[i]] != pattern[i])
                    return false;
                if (mp[pattern[i]] != words[i])
                    return false;
            }
            else
            {

                mp[pattern[i]] = words[i];
                mpi[words[i]] = pattern[i];
            }
        }
        return true;
    }
};