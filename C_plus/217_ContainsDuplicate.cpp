class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // option 1 
        // O(nlogn )
        // set<int> s;
        // for(int i:nums){
        //     if(s.find(i)!=s.end()) return true;
        //     s.insert(i);
        // }
        // return false;
        
        // option 2 
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();++i){
            
            if(nums[i] ==nums[i-1])   return true; 
        }       
        return false;
    }
};