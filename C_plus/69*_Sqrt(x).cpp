class Solution {
public:
    int mySqrt(int x) {
        // return sqrt(x);
        
        
        // option 1 
        // binary search 
        if (x <= 1) return x;
        int left = 0, right = x;
        while (left < right) {
            cout<<left<<" "<<right<<endl;
            int mid =  (right + left) / 2;
            if (x / mid >= mid) left = mid + 1;
            else right = mid;
        }
        return right - 1;
    }
};