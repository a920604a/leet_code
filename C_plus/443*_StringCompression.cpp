class Solution {
public:
    int compress(vector<char>& chars) {
        // At each iteration, check if the current character is the same as the next character. If not, add its compressed version to the result.
        int ret = 0;
        string str = "";
        int countConsecutive = 0;
        for(int i=0;i<chars.size();++i){
            countConsecutive++;
            
            if( i+1 >=chars.size() || chars[i]!=chars[i+1]){
                if(countConsecutive>1) str += chars[i] + to_string(countConsecutive);
                else str += chars[i];
                
                countConsecutive = 0;
            }
                
        }
        cout<<str<<endl;
        chars = vector<char>(str.begin(), str.end());
        return str.size();
    }
};