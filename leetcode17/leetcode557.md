## Leetcode 557 -  反转字符串中的单词III

给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例：
```
输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
``` 

提示：
```
在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
```

### C++
```c++
class Solution {
public:
    string reverseWords(string s) {
        int index = 0;  
        for (int i = 0; i <= s.length(); ++i) {
            if (i == s.length() || s[i] == ' ') {
                reverse(s.begin() + index, s.begin() + i);
                index = i + 1;
            }
        }
        return s;
    }
   
};
```