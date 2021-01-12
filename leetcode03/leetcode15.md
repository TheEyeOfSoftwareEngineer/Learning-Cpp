## Leetcode 15 - 三数之和

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例 1：
```
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
```
示例 2：
```
输入：nums = []
输出：[]
```
示例 3：
```
输入：nums = [0]
输出：[]
```

### C++
- 1
```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = 0;
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        for(int i = 0; i < nums.size(); i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j < k) {
                if(nums[i]+nums[j]+nums[k]==target) {                     
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[k]==nums[k+1]) k--;
                    while(j < k && nums[j]==nums[j-1]) j++;
                } else if(nums[i]+nums[j]+nums[k]>target){
                    k--;
                    while(j < k && nums[k]==nums[k+1]) k--;
                } else {
                    j++;
                    while(j < k && nums[j]==nums[j-1]) j++;
                }
            }
        }

        return res;
    }
};
```
- 2
```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for (int k = 0; k < (int)nums.size() - 2; ++k) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int target = 0 - nums[k], i = k + 1, j = (int)nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return res;
    }
};
```