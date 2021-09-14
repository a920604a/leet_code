class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> his(26,0);
        // balloon 
        for(char c:text) his[c-'a']++;
        int ret = 0;
        //a:0 , b:1 , 
        
        int b = INT_MAX, l = INT_MAX;
        for(int i=0;i<26;++i){
            char c = (char)(i+'a');
            if(c== 'a' || c=='n' || c=='b') b = min(b,his[i]);
            else if(c=='o' || c=='l') l = min(l, his[i]);
        }
        ret = min(l/2, b);
        return ret;
    }
};