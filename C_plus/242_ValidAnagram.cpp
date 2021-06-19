class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> vec(26, 0);
        if (s.size() != t.size())
            return false;
        int n = s.size();
        for (int i = 0; i < n; ++i)
            vec[s[i] - 'a']++;

        for (int i = 0; i < n; ++i)
            vec[t[i] - 'a']--;

        vector<int> b(26, 0);
        return vec == b;
    }
};