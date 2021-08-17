class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        int ret = 0;
        int n = heaters.size();
        sort(heaters.begin(), heaters.end());
        
        for(auto h:houses){
            // binary search 
            int l =0, r =n;
            while(l<r){
                // binary search 找不小於h 的第一個值
                int mid = l + (r-l)/2;
                
                if(h > heaters[mid]) l = mid+1;
                else r = mid;
            }
            cout<<l<<" "<<r<<endl;
            
            int dist1 = (r==0)?INT_MAX : abs(h - heaters[r-1]);
            int dist2 = (r==n)?INT_MAX: abs(h - heaters[r]);
            
            ret = max(ret, min(dist1, dist2));
        }
        return ret;
    }
};