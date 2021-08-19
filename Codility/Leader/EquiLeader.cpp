// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int hasDominator(vector<int> &A, int l, int r){
    if(r==l) return A[l];

    bool first = true;
    int count = -1, val = 0;
    for(int i=l;i<=r;++i){
        if(first){
            count = 1;
            val = A[i];
            first = false;
        }
        else{
            if(val!=A[i]){
                count--;
                if(count==0){
                    count = 1;
                    val = A[i];
                }
            }
            else count++;
        }
    }
    count = 0;
    int idx = -1;
    for(int i = l; i<=r ;++i){
        if(A[i]==val){
            count++;
            idx =i;
        }
    }
    if(count>(r-l+1)/2) return A[idx];
    return -1;

}
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // O(n^2) time and O(n) space => time out
    int ret = 0;
    int n = A.size();
    for(int i=0;i<n-1;++i){
        // split
        int left = hasDominator(A, 0, i);
        int right = hasDominator(A, i+1, n-1);
            
        if(left!=-1 && left == right) {
            ret++;
            
        }
    }
    return ret;
}
