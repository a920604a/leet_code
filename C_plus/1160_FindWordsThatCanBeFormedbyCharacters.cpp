class Solution
{
public:
    bool isGood(string &word, vector<int> dict)
    {

        for (char w : word)
        {
            if (dict[w - 'a'] < 1)
                return false;
            dict[w - 'a']--;
        }
        return true;
    }
    int countCharacters(vector<string> &words, string chars)
    {
        int ret = 0;
        vector<int> dict(26, 0);
        for (char c : chars)
            dict[c - 'a']++;

        // O(n^2)
        for (string word : words)
        {
            if (isGood(word, dict))
            {
                ret += word.size();
            }
        }
        return ret;
    }
};