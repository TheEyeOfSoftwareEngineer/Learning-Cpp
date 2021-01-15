## Leetcode 46 - 全排列

给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:
```
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

### C++
```c++
class Solution {

public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> ans;
        vector<int> used(n);
        vector<int> path;
        function<void(int)> dfs = [&](int d) {
            if (d == n) {
                ans.push_back(path);
                return;
            }
            for (int i = 0; i < n; ++i) {
                if (used[i]) continue;
                used[i] = 1;
                path.push_back(nums[i]);
                dfs(d + 1);
                path.pop_back();
                used[i] = 0;
            }
        };
        dfs(0);
        return ans;
    }
};
```