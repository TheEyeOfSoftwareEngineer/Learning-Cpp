## Leetcode 238 - 除自身以外数组的乘积

给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:
```
输入: [1,2,3,4]
输出: [24,12,8,6]

提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。

说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
```

进阶：
```
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
```

### C++
- 1
```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> l(n, 1); // l[i] = prod(nums[0] ~ nums[i - 1])
        vector<int> r(n, 1); // l[i] = prod(nums[i + 1] ~ nums[n - 1])
        vector<int> ans(n);    

        for (int i = 1; i < n; ++i)
            l[i] = l[i - 1] * nums[i - 1];

        for (int i = n - 2; i >= 0; --i)
            r[i] = r[i + 1] * nums[i + 1];
            
        for (int i = 0; i < n; ++i)
            ans[i] = l[i] * r[i];

        return ans;
    }
};
```

- 2
```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        int l = 1; // l = prod(nums[0] ~ nums[i - 1])
        int r = 1; // r = prod(nums[i + 1] ~ nums[n - 1])
        vector<int> ans(n, 1);
            
        for (int i = 0; i < n; ++i) {
            ans[i] *= l;
            ans[n - i - 1] *= r;
            l *= nums[i];
            r *= nums[n - i - 1];
        }
        
        return ans;
    }
};
```