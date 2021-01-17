## Leetcode 78 - 子集

给你一个整数数组 nums ，返回该数组所有可能的子集（幂集）。解集不能包含重复的子集。

示例 1：
```
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

示例 2：
```
输入：nums = [0]
输出：[[],[0]]
```

提示：
```
1 <= nums.length <= 10
-10 <= nums[i] <= 10
```

### C++
```c++
class Solution {

private:
    void dfs(vector<int>& nums, int n, int s, vector<int>& path, vector<vector<int>>& ans) {
        if(n==path.size()) {
            ans.push_back(path);
            return;
        }
        for(int i = s; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums, n, i+1, path, ans);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        for(int i = 0; i <= nums.size(); i++) {
            dfs(nums, i, 0, path, ans);
        }
        return ans;
    }
};
```