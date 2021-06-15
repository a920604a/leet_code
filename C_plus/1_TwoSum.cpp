class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> tmp;
        for (int i = 0; i < nums.size(); i++)
        {

            if (tmp.find(target - nums.at(i)) != tmp.end())
            {
                return {tmp[target - nums.at(i)], i};
            }
            tmp[nums.at(i)] = i;
        }
        return {};
    }
};
