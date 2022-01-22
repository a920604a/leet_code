class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        
        int cnt = 0;
        int n = word1.size();
        vector<int> his1(26,0), his2(26,0);
        for(int i=0;i<n;++i){
            his1[word1[i]-'a']++;
            his2[word2[i]-'a']++;
        }
        for(int i=0;i<26;++i){
            if(abs(his1[i] -his2[i]) >3) return false;
        }
        return true;
    }
};