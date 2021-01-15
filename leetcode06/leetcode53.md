## Leetcode 52 - 最大子序和

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:
```
输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```

进阶:
```
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解
```

### C++
- 1
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> f(size);
        f[0] = nums[0];        
        for(int i = 1; i < size; i++) {
            f[i] = max(f[i-1]+nums[i], nums[i]);                       
        }
        return *max_element(f.begin(), f.end());
    }
};
```
- 2
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        
        int ans = nums[0];
        int sum = nums[0];        
        for(int i = 1; i < size; i++) {
            sum = max(sum+nums[i], nums[i]);
            ans = max(sum, ans);                       
        }
        return ans;
    }
};
```