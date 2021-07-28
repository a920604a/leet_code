class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> ret;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int t = -1;
            for (int j = i + 1; j < i + n; j++)
            {
                if (nums[j % n] > nums[i])
                {
                    t = nums[j % n];
                    break;
                }
            }
            ret.push_back(t);
        }
        return ret;



        //option 2 monotonic stack
        
        int n = nums.size();
        vector<int> ret(n);
        stack<int> sta;
        // 數組翻倍
        for(int i=2*n -1;i>-1;i--){
            
            while(!sta.empty() && sta.top() <= nums[i%n]){
                sta.pop();
            }
            
            ret[i%n] = sta.empty()?-1:sta.top();
            
            sta.push(nums[i%n]);
        }
        return ret;
        
    }
};