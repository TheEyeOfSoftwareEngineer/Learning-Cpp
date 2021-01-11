## Leetcode 9 - 回文数

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:
```
输入: 121
输出: true
```
示例 2:
```
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
```
示例 3:
```
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
```
进阶:
```
你能不将整数转为字符串来解决这个问题吗？
```

### C++
- 1
```c++
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int size = s.length();
        for(int i = 0; i < size/2; ++i) {
            if(s[i] != s[size-1-i]) {
                return false;
            }
        }
        return true;
    }
};
```
- 2
```c++
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        return s == string(rbegin(s), rend(s));
    }
};
```
- 3
```c++
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if(x == 0) return true;
        int d = static_cast<int>(log10(x) + 1);
        int t = pow(10, d - 1);
        for (int i = 0; i < d / 2; ++i) {     
            if (x / t != x % 10) return false;
            x = (x - x / t * t) / 10;
            t /= 100;     
        }
        return true;
    }
};
```