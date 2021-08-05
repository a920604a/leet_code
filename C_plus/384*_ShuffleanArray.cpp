class Solution
{
private:
    vector<int> v;

public:
    Solution(vector<int> nums) : v(nums) {}

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return v;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        // knuth-shuffle:
        //https://yjk94.wordpress.com/2017/03/17/%E6%B4%97%E7%89%8C%E7%9A%84%E6%AD%A3%E7%A1%AE%E5%A7%BF%E5%8A%BF-knuth-shuffle%E7%AE%97%E6%B3%95/
        
        vector<int> ret = v;
        int n = ret.size();
        for(int i=0;i<n ;++i){
            int j =  i+ rand() % (n - i);  
            
            swap(ret[i], ret[j]);
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */