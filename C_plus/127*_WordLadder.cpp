class Solution
{
public:
    int dist(string s, string t)
    {
        int n = s.size();
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != t[i])
                ret++;
        }
        return ret;
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        // BFS  O(n^4) time out
        //         if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        //         int n = wordList.size();
        //         queue<string> q;
        //         q.push(beginWord);
        //         int step = 1; // 本身也算在長度
        //         while(!q.empty()){
        //             int size = q.size();

        //             for(int i=0;i<size;++i){
        //                 string p= q.front();
        //                 q.pop();
        //                 if(p == endWord) return step;

        //                 for(auto v:wordList){
        //                     if(dist(v, p) == 1) q.push(v);
        //                 }
        //             }
        //             step ++;
        //         }
        //         return 0;

        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord))
            return 0;
        queue<string> q{{beginWord}};
        int step = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                string p = q.front();
                q.pop();
                if (p == endWord)
                    return step;
                for (int i = 0; i < p.size(); ++i)
                {
                    string word = p;
                    for (char ch = 'a'; ch <= 'z'; ++ch)
                    {
                        word[i] = ch;
                        if (wordSet.count(word) && word != p)
                        {
                            q.push(word);
                            wordSet.erase(word);
                        }
                    }
                }
            }
            step++;
        }

        return 0;
    }
};