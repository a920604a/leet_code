class Solution {
public:
    int trap(vector<int>& height) {
        
        // option 1  brute force  O(n^2) time, O(1) space 
        // water[i] = min(
        //        # 左边最高的柱子
        //        max(height[0..i]),  
        //        # 右边最高的柱子
        //        max(height[i..end]) 
        //     ) - height[i]
        
//         int ret = 0;
//         int n = height.size();
//         for(int i=1;i<n-1;++i){
//             int l_max = 0, r_max = 0;
//             // 找右邊最高的柱子
//             for(int j=i;j<n ; ++j){
//                 r_max = max(r_max, height[j]);
//             }
//             // 找左邊最高的柱子
//             for(int j=i;j>-1 ; j--){
//                 l_max = max(l_max, height[j]);
//             }
            
//             ret += min(l_max, r_max ) - height[i];
            
//         }
//         return ret;
        
        
        // option 2  memo pattern O(n) space
        // 提前計算l_max  r_max
//         if(height.empty()) return 0;
//         int n = height.size();
//         vector<int> l_max(n, 0) , r_max(n,0);
//         l_max[0] = height[0], r_max[n-1]= height[n-1];
//         for(int i=1;i<n-1;++i){
//             l_max[i] = max(l_max[i-1] , height[i]);
//         }
//         cout<<endl;
//         for(int i = n-2;i>=1;--i){
//             r_max[i] = max(r_max[i+1], height[i]);
//         }
        
//         int ret = 0;
//         for(int i=1;i<n-1;++i){
//             ret += min(l_max[i] , r_max[i] )- height[i];
        
//         }
//         return ret;
        
        // option 3 two pointer O(1) space
        if (height.empty()) return 0;
        int n = height.size();
        int left = 0, right = n-1;
        int ret = 0;
        int l_max = height[0], r_max = height[n-1];
        while(left <= right){
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);
            // res += min(l_max, r_max) - height[i]
            if (l_max < r_max) {
                ret += l_max - height[left];
                left++; 
            } else {
                ret += r_max - height[right];
                right--;
            }
        }
        return ret;
        
        
        // optnio 4 stack
        
//         stack<int> sta; //存索引 單調堆疊
//         int ret=0;
//         for(int i=0;i<height.size();){
//             if( sta.empty() || height[i] <= height[sta.top()] ){
//                 sta.push(i++);               
//             }
//             else{ // the current height 比 sta.top 大
//                 int t = sta.top(); // 坑的底 
//                 sta.pop();
//                 if(sta.empty()) continue; // 不夠形成坑 
//                 ret +=    (min(height[i], height[sta.top()]) - height[t]) * (i - sta.top() -1 );
//                 // ret +=    (min(height[i], height[sta.top()]) - height[t]) * (i - sta.top() - 1);
//                 // 高(剪掉坑的高度) 乘 寬(索引相剪)         
//                 cout<<ret<<endl;
                
//             }
//         }
//         return ret;
        
        
    }
};