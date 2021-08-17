class Solution
{
public:
    void permuteUniqueDFS(vector<int> &nums, int level, vector<int> &visited, vector<int> &out, set<vector<int> > &ret)
    {

        if (level >= nums.size())
        {
            // ret.push_back(out);
            ret.insert(out);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (visited[i] == 1)
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0)
                continue;
            visited[i] = 1;
            out.push_back(nums[i]);
            permuteUniqueDFS(nums, level + 1, visited, out, ret);
            out.pop_back();
            visited[i] = 0;
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &nums)
    {
        //option 1 
        sort(nums.begin(), nums.end());
        set<vector<int> > ret;
        vector<int> out, visited(nums.size(), 0);
        permuteUniqueDFS(nums, 0, visited, out, ret);
        return vector<vector<int> >(ret.begin(), ret.end());

        // option 2 
        set<vector<int>> res;
        permute(nums, 0, res);
        return vector<vector<int>> (res.begin(), res.end());
    }


    void permute(vector<int>& nums, int start, set<vector<int>>& ret){
        
        if(start >= nums.size()) ret.insert(nums);
        
        for(int i = start ; i<nums.size();++i){
            // prune
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[start], nums[i]);
            permute(nums, start+1, ret);
            swap(nums[start], nums[i]);
            
        }
    }
};