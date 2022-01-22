class Solution
{
public:
    bool isValid(string word)
    {
        vector<int> his(5, 0);
        for (char c : word)
        {
            if (c == 'a')
                his[0]++;
            else if (c == 'e')
                his[1]++;
            else if (c =1306. Jump Game III= 'i')
                his[2]++;
            else if (c == 'o')
                his[3]++;
            else if (c == 'u')
                his[4]++;
            else
                return false;
        }
        for (int h : his)
        {
            if (h == 0)
                return false;
        }
        return true;
    }
    int countVowelSubstrings(string word)
    {
        // O(n^2*m) time
        int cnt = 0;
        int n = word.size();
        for (int i = 0; i < n; ++i)
        {
            bool first = true;
            for (int j = i; j < n; ++j)
            {
                string temp = word.substr(i, j - i + 1);
                if (isValid(temp))
                    cnt++;
            }
        }
        return cnt;
    }
};