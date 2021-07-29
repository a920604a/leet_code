class Solution {
public:
    bool canWinNim(int n) {
        // 假設雙方一樣聰明，並且我方先起手
        // n =      1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
        // result=  t   t   t   f   t   t   t   f   t   t   t   f   t   t   t
        
        return n%4 !=0;
    }
};