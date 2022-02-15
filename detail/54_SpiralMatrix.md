# 54. Spiral Matrix

###### tags: `leetcode` 

## [problem](https://leetcode.com/problems/spiral-matrix/)

## solution 
維護一組陣列，控制下一步要走的方向

```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> path;
        set<pair<int,int>> visited;
        vector<int> acts = {0,1,0,-1};
        int n = matrix.size(), m = matrix[0].size();
        int times = n*m;
        int i=0,j=-1, a=0;
        while(times-- >0){
            int x = i+acts[a%4], y = j+acts[(a+1)%4];
            while(x< 0 || x>n-1 || y<0 || y>m-1 || visited.find(make_pair(x,y))!=visited.end()){
                a++;
                x = i + acts[a%4];
                y = j + acts[(a+1)%4];
            }
            
            path.push_back(matrix[x][y]);
            visited.insert(make_pair(x,y));
            i=x, j=y;
        }
        return path;
    }
};
```
## analysis
- time complexity `O(*m)`
- space complexity `O(n*m)`