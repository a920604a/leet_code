# 48. Rotate Image

###### tags: `leetcode` `Blind Curated 75`

## [problem](https://leetcode.com/problems/rotate-image/)

## solution 
先對陣列以行為單位做`reverse`，再逐一對角線對調

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        int n = matrix.size(), m=matrix[0].size();
        for(int i = 0;i<n-1;++i){
            for(int j =i+1 ; j<n;++j){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};
```

## analysis
- time complexity `O(n^2)`
- space complexity `O(1)`