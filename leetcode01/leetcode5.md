## Leetcode 5 - 最长回文字符串

给你一个字符串 s，找到 s 中最长的回文子串。

示例 1：
```
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
```
示例 2：
```
输入：s = "cbbd"
输出："bb"
```
示例 3：
```
输入：s = "a"
输出："a"
```
示例 4：
```
输入：s = "ac"
输出："a"
```
### C++
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.length();
        auto getLen = [&](int l , int r) {
            while(l >=0 && r < n && s[l]==s[r]) {
                --l;
                ++r;
            }
            return r-l-1;
        };
        int len = 0;
        int start = 0;
        for(int i = 0; i < n; i++) {
            int cur = max(getLen(i,i), getLen(i, i+1));
            if(cur>len) {
                len = cur;
                start = i - (len-1)/2;
            }
        }
        return s.substr(start, len);
    }
};
```