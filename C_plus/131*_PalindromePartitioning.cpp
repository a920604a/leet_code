class Solution {
public:
    bool isPalindrome(string v, int l, int r ){
        while(l<=r){
            if(v[l]!=v[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void helper(string s, int start , vector<string> out, vector<vector<string>> &ret){
        
        if(start>=s.size()){
            ret.push_back(out); 
            return ;
        }
        
        for(int i=start;i<s.size();++i){
            if(!isPalindrome(s, start, i)) continue;
            out.push_back(s.substr(start, i-start+1));
            helper(s, i+1, out, ret);
            out.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> out;
        helper(s, 0, out, ret);
        return ret;
    }
};