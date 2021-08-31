class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {

        // option 1
        vector<int> rec(26, INT_MAX);
        vector<string> ret;
        for (string word : words)
        {
            vector<int> t(26);
            for (char c : word)
                t[c - 'a']++;
            for (int i = 0; i < 26; i++)
                rec[i] = min(rec[i], t[i]);
        }

        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < rec[i]; ++j)
            {
                ret.push_back(string(1, 'a' + i));
            }
        }
        return ret;
    }
};