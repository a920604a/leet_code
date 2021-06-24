class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ret ; 
        
        int l=0, r=0;
        int m =firstList.size(), n=secondList.size();
        while(l<m && r<n){
            if(firstList[l][1] < secondList[r][0]) l++;
            else if(secondList[r][1] < firstList[l][0]) r++;
            else{
                ret.push_back({ max(firstList[l][0],secondList[r][0]),min(firstList[l][1],secondList[r][1]) });
                if (firstList[l][1] < secondList[r][1]) ++l;
                else if (secondList[r][1] < firstList[l][1]) ++r;
                else {++l; ++r;}
                
            }
            
            
        }
        return ret;
        
    }
};