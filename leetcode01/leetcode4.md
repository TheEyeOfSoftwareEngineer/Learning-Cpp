## Leetcode 4 - 寻找两个正序数组的中位数
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。

进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

示例 1：
```
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
```
示例 2：
```
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
```
示例 3：
```
输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000
```
示例 4：
```
输入：nums1 = [], nums2 = [1]
输出：1.00000
```
示例 5：
```
输入：nums1 = [2], nums2 = []
输出：2.00000
```

### C++
- 1
```c++
class Solution {    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int i = 0; i < nums1.size(); i++) {
            v.push_back(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            v.push_back(nums2[i]);
        }
        sort(v.begin(), v.end());
        if(v.size()%2!=0) {
            return (double) v[v.size()/2];
        } else {
            return ((double) v[v.size()/2] + (double) v[v.size()/2-1]) / double(2);
        }
    }
};
```
- 2
```c++
class Solution {    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        const int k = (n1+n2+1)/2;
        int l = 0;
        int r = n1;
        while(l<r) {
            const int m1 = l+(r-l)/2;
            const int m2 = k - m1;
            if(nums1[m1] < nums2[m2-1]) {
                l = m1+1;
            } else {
                r = m1;
            }            
        }
        const int m1 = l;
        const int m2 = k - l;
        const int c1 = max(m1<=0 ? INT_MIN : nums1[m1-1], m2 <=0? INT_MIN : nums2[m2-1]);
        if((n1+n2)%2 == 1) {
            return c1;
        }
        const int c2 = min(m1>=n1 ? INT_MAX : nums1[m1], m2 >= n2 ? INT_MAX : nums2[m2]);
        return (c1+c2)*0.5;
    }
};
```