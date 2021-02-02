## Leetcode 78 - 子集

属于排列组合题目

### Java
```java
class Solution {

    List<List<Integer>> ans;

    public List<List<Integer>> subsets(int[] nums) {
        if(nums == null || nums.length == 0) return ans;
        int n = nums.length;        
        ans = new ArrayList<>();
        List<Integer> path = new ArrayList<Integer>();
        for(int i = 0; i <= n; i++) {
            combination(nums, path, 0, i, n);
        }
        return ans;
    }

    private void combination(int[] nums, List<Integer> path, int index, int size, int capacity) {
        if(path.size() == size) {
            ans.add(new ArrayList(path));
            return;
        } else {
            for(int i = index; i < capacity; i++) {
                path.add(nums[i]);
                combination(nums, path, i+1, size, capacity);
                path.remove(path.size()-1);
            }
        }
    }
}
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