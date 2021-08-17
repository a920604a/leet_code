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
        
        
        
      
        // KMP BM        
        // option 2 Sunday 匹配
        if(needle.empty() ) return 0;
        if(needle.size() > haystack.size()) return -1;
        
        
        int n =haystack.size(), m = needle.size();
        
        vector<int> shift(128, m + 1);
        // 位移表
        // 模式串P中每个字母出现的最后的下标
        // 所对应的主串参与匹配的最末位字符的下一位字符移动到该位，所需要的移动位数
        for(int i = 0; i < m; i++) {
            shift[needle[i]] = m - i;
        }
        
        // 模式串開始位置
        int s =0;
        // 模式串已經匹配到的位置
        int j;
        while(s <= n-m){
            j = 0;
            while(haystack[s +j] == needle[j]){
                j++;
                if(j>=m){
                    //  匹配成功
                    return s;
                }
            }
            // 匹配不成功
             s += shift[haystack[s + m]];
            
        }
        return -1;
        
        
    }
};