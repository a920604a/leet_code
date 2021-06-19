class Solution {
public:
    int countPrimes(int n) {
        int ret=0;
        if(n<=1) return ret;
        vector<bool> visit(n, true);
        visit[0] =false, visit[1] = false;
        for(int i =2;i<=sqrt(n);++i){
            if(visit[i]== true){
                for(int j =i+i; j<n ;j+=i){ 
                    visit[j] = false;
                }
                
            }
        }
        
        for(bool b:visit) ret += b?1:0;
        
        return ret;
    }
};