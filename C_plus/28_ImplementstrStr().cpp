class KMP{
private:
    vector<vector<int>>  dp;
    string pat;
public:
    KMP(string pat){
        this->pat = pat;
        // 通過pat 建構 dp 需要O(M) 時間
        
        int M = pat.size();
        // dp[狀態][字符] = 下個狀態
        dp = vector<vector<int>>(M, vector<int>(256,0));
        
        // base case
        dp[0][pat[0 ]] =1;
        
        int x = 0;
        
        for(int j = 1;j<M ;++j){
            for(int c = 0;c<256 ; ++c){
                dp[j][c] = dp[x][c];
            }
            dp[j][pat[j]] = j+1;
            x = dp[x][pat[j]];
        }
    }
    int search(string txt){
        // 借助dp 去匹配txt，需要O(N) 時間
        
        int m = this->pat.size();
        int n = txt.size();
        int j = 0;
        
        for(int i=0;i<n ;++i){
            j = dp[j][txt[i]];
            if(j == m) return i-m+1;
        }
        // 到達終止狀態，匹配失敗
        return -1;
    }
    
};
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        
        
        // option 1 brute force O(MN) time and O(1) space
        
//         if(haystack.size()==0 && needle.size()==0 ) return 0;
//         if(needle.size()>haystack.size()) return -1;
        
//         int ret = -1;
//         for(int i=0;i<=haystack.size()-needle.size();++i){
            
//             int tmp = 0;
//             for(int j=0;j<needle.size();++j){
//                 if(haystack[i+j]!=needle[j]) break;
//                 tmp++;
//             }
//             if(tmp==needle.size()) return i;
        
//         }
        
//         return -1;
        
        
        
        // Knuth-Morris-Pratt 不會重複掃描 原始字串，會利用一些空間紀錄訊息
        // O(N) time, 空間換時間
        
        if(haystack.empty() && needle.empty()) return 0;
        if(needle.empty()) return 0;
        
        KMP kmp = KMP(needle);
        return kmp.search(haystack);
        
        
    }
};