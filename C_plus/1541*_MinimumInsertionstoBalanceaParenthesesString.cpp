class Solution {
public:
    int minInsertions(string s) {
        
        // need 變數 紀錄右括號 的需求量
        int ret = 0, need = 0;
        
        for(int i=0;i<s.size() ; ++i){
            // 一個左括號 對應兩個右括號
            if(s[i] =='('){
                need +=2;
                if(need %2 ==1){
                    // 一個左括號 對應兩個右括號，對右括號的需求必須是偶數
                    // 插入一个右括号
                    ret++;
                    // 对右括号的需求减一
                    need--;
                }
            }
            if(s[i] == ')'){
                need--;
                // 说明右括号太多了
                if(need == -1){
                    // 比如遇到單獨一個右括號 ")"，由於一個左括號需要兩個兩個右括號。所以ret ++ , need = 1
                    // 需要插入一个左括号
                    ret++;
                    // 同时，对右括号的需求变为 1
                    need = 1;
                    
                }
            }
        }
        return ret + need;
    }
};