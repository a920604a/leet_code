---
title: 166. Fraction to Recurring Decimal
tags:  
    - Math
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/fraction-to-recurring-decimal/)

## solution

```c++
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int s1 = numerator >= 0 ? 1 : -1;
        int s2 = denominator >= 0 ? 1 : -1;
        long long num = abs( (long long)numerator );
        long long den = abs( (long long)denominator );
        long long out = num / den;
        long long rem = num % den;
        unordered_map<long long, int> m;
        string ret = to_string(out);
        if (s1 * s2 == -1 && (out > 0 || rem > 0)) ret = "-"+ret;
        if(rem ==0) return ret;
        ret+=".";
        
        string s = "";
        int pos = 0;
        while(rem!=0){
            if(m.find(rem) !=m.end()){
                s.insert(m[rem],"(");
                s+=")";
                return ret+s;
            }
            m[rem] = pos;
            cout<<rem<<" "<<pos<<endl;
            s+= to_string((rem*10) / den);
            rem = (rem*10) % den;
            ++pos;
        }
        return ret+s;
    }
};
```

## 