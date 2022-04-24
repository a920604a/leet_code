---
title: 535. Encode and Decode TinyURL
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/encode-and-decode-tinyurl/)
## solution
```c++
class Solution {
private:
    unordered_map<string, string> short2long, long2short;
    string dict;
    string BASE = "http://tinyurl.com/";

public:
    Solution() {
        dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        short2long.clear();
        long2short.clear();
        srand(time(NULL));
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        if (long2short.count(longUrl)) {
            return BASE + long2short[longUrl];
        }
        int idx = 0;
        string randStr;
        for (int i = 0; i < 6; ++i) randStr.push_back(dict[rand() % 62]);
        // cout<<randStr<<endl;
        while (short2long.count(randStr)) {
            randStr[idx] = dict[rand() % 62];
            idx = (idx + 1) % 5;
        }
        short2long[randStr] = longUrl;
        long2short[longUrl] = randStr;
        return BASE + randStr;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string randStr = shortUrl.substr(shortUrl.find_last_of("/") + 1);
        return short2long.count(randStr) ? short2long[randStr] : shortUrl;
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```
