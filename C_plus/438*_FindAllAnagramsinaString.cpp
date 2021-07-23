class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // option 1 滑動窗口
//         vector<int> ret;
//         unordered_map<char, int> need, window;
//         for(char c:p) need[c]++;
        
//         int left =0, right = 0, valid = 0;
//         while(right < s.size()){
//             char c = s[right];
//             right++;
//             // update sliding window info.
//             if(need.count(c)){
//                 window[c]++;
//                 if(window[c] == need[c]) valid++;
//             }
            
//             while(right - left >= p.size()){
                
//                 // 找到子串p的anagram
//                 if(valid == need.size() && right-left == p.size()){
//                     ret.push_back(left);
//                 }
                
//                 char d = s[left];
//                 left ++;
                
//                 // update sliding window info.
//                 if(need.count(d)){
                    
//                     if(window[d] == need[d]) valid--;
//                     window[d]--;
//                 }
//             }
//         }
//         return ret;
        
        // option 2 improved sliding window
        vector<int> ret;
        vector<int> need(26,0), window(26,0);
        for(char c:p) need[c-'a']++;
        
        for(int i=0;i<s.size();++i){
            window[s[i]-'a']++;
            // 要做左側窗口裁減
            if(i >=p.size()) {
                window[s[i-p.size()] -'a'] --;
            }
            if(window == need) ret.push_back(i-p.size()+1);
        }
        return ret;
        
    }
};
