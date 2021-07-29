class Solution {
public:
    unordered_map<string, bool> memo;
    
    bool dp(string &s, int i , string &p, int j){
        int m = s.size(), n = p.size();
        // base case 
        if(j==n) return i==m;
        
        if(i== m){
            if( (n-j) %2==1) return false;
            
            for(;j+0<n ;j+=2){
                if(p[j+1] != '*'){
                    return false;
                }
            }
            return true;
        }
        
        
        // 紀錄 狀態 (i, j)，消除重疊子問題
        string key = to_string(i) + "," + to_string(j);
        
        if(memo.count(key)) return memo[key];
        
        bool ret = false;
        if(s[i] == p[j] || p[j] =='.'){
            // 匹配
            if(j < n-1 && p[j+1] == '*'){
                // 通配符匹配0次 或多次
                ret = dp(s, i, p, j+2) || dp(s, i+1, p, j);
            }
            else{
                // 常規匹配1 次
                ret = dp(s, i+1, p, j+1);
            }
        }
        else{
            // 不匹配
            if(j< n-1 && p[j+1] == '*'){
                // 通配符匹配0 次
                ret = dp(s, i, p, j+2);
            }
            else{
                // 無法繼續匹配
                ret = false;
            }
        }
        memo[key] =ret;
        return ret;
        
    }
    
    bool isMatch(string s, string p) {
        
        // int i = 0, j = 0;
        // while (i < s.size() && j < p.size()) {
        //     // 「.」通配符就是万金油
        //     if (s[i] == p[j] || p[j] == '.') {
        //         // 匹配，接着匹配 s[i+1..] 和 p[j+1..]
        //         i++; j++;
        //     } else {
        //         // 不匹配
        //         return false;
        //     }
        // }
        // return i == j;
        
        return dp(s, 0, p, 0);
        
    }
};