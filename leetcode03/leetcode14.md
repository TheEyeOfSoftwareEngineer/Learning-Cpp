## Leetcode 14 - 最长公共前缀

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1：
```
输入：strs = ["flower","flow","flight"]
输出："fl"
```
示例 2：
```
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
```

提示：
```
0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成
```


### C++
- 1
```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {                 
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        int i = 0, len = min(strs[0].size(), strs.back().size());
        while (i < len && strs[0][i] == strs.back()[i]) ++i;
        return strs[0].substr(0, i);
    }
};
```
- 2
```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {                 
        if (strs.empty()) return "";
        string res = "";
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return res;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};
```