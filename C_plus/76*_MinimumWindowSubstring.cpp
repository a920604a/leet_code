class Solution {
public:
    string minWindow(string s, string t) {
        // option 1 滑動窗口框架 O(N) time
//         int left = 0, right = 0;

//         while (right < s.size()) {`
//             // 增大窗口
//             window.add(s[right]);
//             right++;

//             while (window needs shrink) {
//                 // 缩小窗口
//                 window.remove(s[left]);
//                 left++;
//             }
//         }
        
        /* 滑动窗口算法框架 */
//         void slidingWindow(string s, string t) {
//             unordered_map<char, int> need, window;
//             for (char c : t) need[c]++;

//             int left = 0, right = 0;
//             int valid = 0; 
//             while (right < s.size()) {
//                 // c 是将移入窗口的字符
//                 char c = s[right];
//                 // 右移窗口
//                 right++;
//                 // 进行窗口内数据的一系列更新
//                 ...

//                 /*** debug 输出的位置 ***/
//                 printf("window: [%d, %d)\n", left, right);
//                 /********************/

//                 // 判断左侧窗口是否要收缩
//                 while (window needs shrink) {
//                     // d 是将移出窗口的字符
//                     char d = s[left];
//                     // 左移窗口
//                     left++;
//                     // 进行窗口内数据的一系列更新
//                     ...
//                 }
//             }
//         }
        
        
        // option 1 brute force 
        // O(n^4)  must be timeout
//         if(s.size() < t.size()) return "";
//         string ret="";
//         for(int i=0;i<s.size();++i){
//             string temp;
//             for(int j=i;j<s.size();++j){
//                 temp += s[j];
//                 if(valid(temp, t)){
//                     // update ret
//                     if(ret.empty() || ret.size() > temp.size()) ret = temp;
//                 }
                    
//             }
//         }
        
//         return ret;
        // option 2 slide window  O(N) time
        
        // 因為結果不論順序與否，只要包含即可，所以用hash
        // window 是左閉區間右開區間。
        unordered_map<char, int> need, window;
        for(char c:t) need[c]++;
        int valid = 0;
        int left = 0, right = 0;
        int start = 0, len = INT_MAX;
        while(right <s.size()){
            char c = s[right];
            right++;
            
            // 更新窗口內數據
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]) valid++;
            }
            //判斷窗口左側是否要收縮
            while(valid == need.size()){
                // 说明 T 中所有字符已经被覆盖
                // 符合答案候選條件
                if(right - left <len){
                    start = left;
                    len = right -left;
                }
                char d = s[left];
                left++;

                // 更新窗口內數據
                if(need.count(d)){
                    if(window[d] == need[d]){
                        valid --;
                    }
                    window[d]--;
                }
            }
            
        }
        // 返回最小覆蓋子串
        return len==INT_MAX? "":s.substr(start, len);
        
        
    }
};