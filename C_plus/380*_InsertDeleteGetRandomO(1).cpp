class RandomizedSet {
private:
    //  藉由hash 插入刪除都為O(1)的特性，紀錄索引
    unordered_map<int,int> valToIndex;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // O(1)
        if(valToIndex.count(val)) return false;
        
        nums.push_back(val);
        valToIndex[val] = nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // O(1)，在數組中，要刪除元素與末端元素 先進行交換下進行刪除
        if(valToIndex.find(val) ==valToIndex.end() ) return false;
        // 取得 val 的索引
        int i = valToIndex[val];
        // 修改 nums.back() 的索引成 val 的索引，因為稍後會對調
        valToIndex[nums.back()] = i;
        
        swap(nums[i] , nums.back());
        
        nums.pop_back();
        // 刪除 val 對應的索引
        valToIndex.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        // O(1)
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */