## Leetcode 16 - 最接近三数之和

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

示例：
```
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
``` 
提示：
```
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
```

### C++
```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) {
            return INT_MIN;
        }
        sort(nums.begin(), nums.end());
        
        int res = 1000;
        for(int i = 0; i < nums.size()-2; i++) {
            int l = i+1;
            int r = nums.size()-1;
            while(l < r) {
                int val = nums[i] + nums[l] + nums[r];
                if(val==target) {
                    return target;
                } else if(val > target) {
                    if(abs(val-target) < abs(res-target)) {
                        res = val;
                    }
                    r--;
                    while(l < r && nums[r]==nums[r+1]) r--;
                } else if(val < target) {
                    if(abs(val-target) < abs(res-target)) {
                        res = val;
                    }
                    l++;
                    while(l < r && nums[l]==nums[l-1]) l++;
                }
            }
        }
        return res;
    }
};
```