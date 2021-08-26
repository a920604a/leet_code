class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        if(nums.size() ==1) return {to_string(nums[0])};
        
        int n = nums.size();
        vector<string> ret = {to_string(nums[0])};
        string out ;
        for(int i =1;i<n;++i){
            if(nums[i] != nums[i-1] +1){
                if(!out.empty() && out!=ret.back()  ){
                    ret.back() += "->";
                    ret.back() += out;
                }
                out = to_string(nums[i]);
                ret.push_back(out);
            }
            else if(nums[i] == nums[i-1] +1){
                out = to_string(nums[i]);
            }
        }
        if(!out.empty() && out!=ret.back()  ){
            ret.back() += "->";
            ret.back() += out;
        }
        return ret;
    }
};