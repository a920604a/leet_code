class TwoSum
{
private:
    set<int> freq;
    list<int> nums;

public:
    void add(int number)
    {
        // 紀錄所有可能組了的和
        for (int n : nums)
        {
            freq.insert(n + number);
        }
        nums.push_back(number);
    }
    // 設計API，應該考慮find可能被運行多次，不可能每次都要O(N)，優化成O(1)
    bool find(int value)
    {
        return freq.count(value);
    }
};

class Solution
{

public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // https://web.stanford.edu/class/cs9/sample_probs/TwoSum.pdf

        // option 1 brute O(n^2) time and O(1) space
        // int n = nums.size();
        // for(int i=0;i<n;++i){
        //     for(int j=i+1;j<n;++j){
        //         if(nums[i]+nums[j]==target) return {i,j};
        //     }
        // }
        // return {};

        // option 2 Hashing O(n) time and O(n) space
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {

            if (m.count(target - nums.at(i)))
            {
                return {m[target - nums.at(i)], i};
            }
            m[nums.at(i)] = i;
        }
        return {};

        // option 3 API interface
        // 170. Two Sum III - Data structure design
    }
};