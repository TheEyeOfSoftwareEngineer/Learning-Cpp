## Leetcode 121 - 买卖股票的最佳时机

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。

示例 1:
```
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
```

示例 2:
```
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
```

### C++
- 1
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {        
        int ans = 0;
        if(prices.size() <= 1) {
            return ans;
        }
        int l = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            l = min(l, prices[i]);
            ans = max(ans, prices[i]-l);
        }

        return ans;
    }
};
```

- 2
```c++
class Solution {
private:
    int maxSubArray(vector<int>& nums) {
        vector<int> f(nums.size());
        f[0] = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            f[i] = max(f[i-1] + nums[i], nums[i]);
        }
        return *max_element(f.begin(), f.end());
    }

public:
    int maxProfit(vector<int>& prices) {        
        int n = prices.size();
        if( n < 2) return 0;
        vector<int> gains(n-1, 0);
        for(int i = 1; i < n; i++) {
            gains[i-1] = prices[i] - prices[i-1];
        }        
        return max(0, maxSubArray(gains));
    }
};
```