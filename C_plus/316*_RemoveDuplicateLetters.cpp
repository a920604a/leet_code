class Solution {

public:
    string removeDuplicateLetters(string s) {
        
        // option 1 O(N) time and O(N) space
        stack<char> sta;
        vector<bool> instack(256,false);
        vector<int> count(256);
        for(char c:s) count[c]++;
        
        for(char c:s){
            
            count[c]--;
            
            if( instack[c]) continue;
            
             // monotonic stack
            while(!sta.empty() && sta.top() > c){
                // 須先判斷此字元在字串中是否唯一，否則pop掉就完了
                if(count[sta.top()]==0) break;
                instack[sta.top()] = false;
                sta.pop();
            }
            
            
            sta.push(c);
            instack[c] = true;
        }
        
        string ret;
        while(!sta.empty()){
            ret.insert(ret.begin(), sta.top());
            sta.pop();
            
        }
        cout<<ret<<endl;
              
        return ret;
    }
};