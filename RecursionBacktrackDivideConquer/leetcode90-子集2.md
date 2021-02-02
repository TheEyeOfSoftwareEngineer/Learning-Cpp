## Leetcode - 子集2

### Java
```java
class Solution {

    List<List<Integer>> ans;

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        ans = new ArrayList<>();
        Arrays.sort(nums);
        List<Integer> path = new ArrayList<>();
        dfs(nums, 0, path);
        return ans;
    }

    private void dfs(int[] nums, int index, List<Integer> path) {
        if(!ans.contains(path)) {
            ans.add(new ArrayList<>(path));
        }
        for(int i = index; i < nums.length; i++) {
            path.add(nums[i]);
            dfs(nums, i+1, path);
            path.remove(path.size()-1);
        }
    }
}
```

### C++
```c++
class Solution {
public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        const int n = nums.size();
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        vector<int> cur;
        function<void(int)> dfs = [&](int s) {
            ans.push_back(cur);
            if (cur.size() == n)
                return;      
            for (int i = s; i < n; ++i) {
                if (i > s && nums[i] == nums[i - 1]) continue;
                cur.push_back(nums[i]);
                dfs(i + 1);
                cur.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
```