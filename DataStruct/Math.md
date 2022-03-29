---
title: Math
categories: 
    - CS
    - Algorithm
comments: false
---


## 觀念

a^a = 0, a^0 = a 滿足交換性

n & (n-1) 

## 題目

- 191 Number of 1 Bits (Easy)
- 231 Power of Two (Easy)
- 172 Factorial Trailing Zeroes (Easy)
- 793 Preimage Size of Factorial Zeroes Function (Hard)
- 204 Count Primes (Easy)
- 372 Super Pow (Medium)
- 448 Find All Numbers Disappeared in an Array (Easy)
- 654 Maximum Binary Tree (Medium)
- 382 Linked List Random Node (Medium)
- 398 Random Pick Index (Medium)
- 26 Remove Duplicates from Sorted Array (Easy)
- 83 Remove Duplicates from Sorted List (Easy)
- 27 Remove Element (Easy)
- 283 Move Zeroes (Easy)
- 292 Nim Game (Easy)
- 877 Stone Game (Medium)
- 319 Bulb Switcher (Medium) 


[補充]
- 263 Ugly Number
- 264 Ugly Number II
- 1201 Ugly Number III
- 313 Super Ugly Number
- 279 Perfect Squares

## Bit manipulation
### 191 Number of 1 Bits (Easy)

```cpp
int hammingWeight(uint32_t n) {

    int ret =0;
    while(n){
        ret++;
        n = n&(n-1);
    }
    return ret;
}
```

### 190 Reverse Bits (Easy)
```c
uint32_t reverseBits(uint32_t n) {  
    uint32_t ret = 0;
    int cnt = 32;
    while(cnt){
        ret <<=1;
        cnt-=1;
        ret += n&1;
        n>>=1;        
    }
    return ret;
}
```
### 231 Power of Two (Easy)
```cpp
bool isPowerOfTwo(int n){
    if(n<1) return false;
    return (n&(n-1)) ==0;
}
```
### 338 Counting Bits (Easy)
```c
class Solution {
public:
    vector<int> countBits(int n) {
        //  0       ->  0
        //  1(00)   ->  1
        //  2(01)   ->  1
        //  3(10)   ->  2
        //  4(011)  ->  1
        //  5(100)  ->  2
        vector<int> ret(n+1,0);
        for(int i=1;i<=n;++i){
            ret[i] = ret[i&(i-1)]+1;
        }
        return ret;
    }
};
```
## Duplicates and Unique


### 136 Single Number (Easy)

```cpp
int singleNumber(vector<int>& nums) {
        // option 1 bit manipulation
        // a ^ a = 0 a ^ 0 = a，^有交換率，成對的數字變成０
        // int ret = 0;
        // for(int n:nums) ret^= n;
        // return ret;
        
        // optnio 2 general case 
        int ret = 0;
        for(int i=0;i<32;++i){
            int sum = 0;
            for(int n:nums){
                sum += (n>>i)&1;
            }
            ret += (sum%2)<<i;
        }
        return ret;
    }
```

### 137 Single Number II (Medium)
```cpp
int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i=0;i<32;++i){
            int sum = 0;
            for(int n:nums){
                sum += (n>>i)&1;
            }
            ret += (sum%3)<<i;
        }
        return ret;
        
    }
```


### 260 Single Number III (Medium)
```cpp
vector<int> singleNumber(vector<int>& nums) {
        unsigned int diff = 0; // 0 到 4,294,967,295
        for(int n:nums) diff ^=n;
        diff &= -diff;
        //-diff 110 => reverse bit and + 1 => 001 -> 010       
        vector<int> ret(2,0);
        for(int a:nums){
            if(a&diff) ret[0]^=a;
            else ret[1]^=a;
        }   
        return ret;        
    }
```

### 268 Missing Number (Easy)

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // math
        // int n = nums.size();
        // int total = (n+1)*n/2;        
        // for(int n:nums) total -= n;        
        // return total;
        
        // bit manipulation
        int n = nums.size();
        int ret = n;
        for(int i=0;i<n;++i) ret ^= (i^nums[i]);
        return ret;
        
    }
};
```



### 287 Find the Duplicate Number (Medium) Two pointer and cycle 

```cpp
int findDuplicate(vector<int>& nums) {
        int slow =0, fast =0;
        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast) break;
        }
        fast = 0;
        while(1){
            fast = nums[fast];
            slow = nums[slow]; 
            if(slow==fast) break;
        }
        return slow;
    }
```

### 389 Find the Difference
```cpp
char findTheDifference(string s, string t) {
        // char ret =0;
        // for(char c:t) ret+=c;
        // for(char c:s) ret-=c;
        // return ret;
        
        
        int ret = 0;
        for(char c:t) ret^= c-'a';
        for(char c:s) ret^= c-'a';
        return char(ret+'a');
    }
```


### 448 Find All Numbers Disappeared in an Array (Easy)

```cpp
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ret;
    int n = nums.size();
    for(int i=0;i<n;++i){
        int idx = abs(nums[i])-1;            
        if(nums[idx]>0) nums[idx] *=-1;            
    }
    
    for(int i=0;i<n;++i){
        if(nums[i]>0) ret.push_back(i+1);
    }
    return ret;
}

```



### 442 Find All Duplicates in an Array (Medium)

```cpp
vector<int> findDuplicates(vector<int>& nums) {
        vector<int>  ret;
        for(int i=0;i<nums.size();++i){
            int idx = abs(nums[i])-1;
            if(nums[idx]>0) nums[idx] *= -1;
            else ret.push_back(abs(nums[i]));
        }
        return ret;
    }
```


## Two pointer 
### 26 Remove Duplicates from Sorted Array (Easy)
```cpp
int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int slow = 0, fast = 0, n = nums.size();        
        for(int i=0;i<n;++i){
            if(nums[fast] != nums[slow]){
                nums[++slow] = nums[fast];
            }
            fast++;
        }
        return slow+1;
```

### 80 Remove Duplicates from Sorted Array II (Medium)
```cpp
int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int slow = 0, count = 1, fast = 1, n = nums.size();
        while(fast<n){
            if(nums[fast] == nums[slow] && count==0) fast++;
            else{
                if(nums[fast] == nums[slow]) count--;
                else count =1;
                nums[++slow] = nums[fast++];
            }
        }
        return slow+1;
    }
```
### 27 Remove Element (Easy)
```cpp
int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0, n = nums.size();
        for(int i=0;i<n;++i){
            if(nums[fast]!=val) nums[slow++] = nums[fast];
            fast++;
        }
        return slow;
    }
```


### 283 Move Zeroes (Easy)
```cpp
int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size(), slow = 0, fast = 0;
        while(fast<n){
            if(nums[fast] != val) nums[slow++] = nums[fast];
            fast++;
        }
        return slow;
    }
void moveZeroes(vector<int>& nums) {
    int p = removeElement(nums, 0);
    int n=nums.size();
    for(int i=p ;i<n;++i) nums[i]=0;        
}
```

### 203 Remove Linked List Elements (Easy)
```cpp
ListNode* removeElements(ListNode* head, int val) {
        ListNode *slow = new ListNode(-1), *fast = head, *ans = slow;
        slow->next = head;
        while(fast){
            if(fast->val != val){
                slow->next= fast ;
                slow =slow->next;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return ans->next;
        
    }
```


### 83 Remove Duplicates from Sorted List (Easy)
```cpp
 ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *slow = head, *fast = head;
        while(fast){
            if(fast->val != slow->val){
                slow->next = fast;
                slow= slow->next;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;   
    }
```
