## Leetcode 300 - Longest Increasing Subsequence
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
Example 1:
```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```

Example 2:
```
Input: nums = [0,1,0,3,2,3]
Output: 4
```
Example 3:
```
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```
### C++
#### 1 O(n^2)
```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        if(length == 0) return 0;
        int dp[length];
        
        dp[0] = 1;
        int rtn = 1;
        
        for(int i = 1; i < length; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[i] < dp[j]+1) {
                    dp[i] = dp[j] + 1;
                }
                if(dp[i] > rtn) {
                    rtn = dp[i];
                }
            }
        }
        
        return rtn;
        
    }
};
```
#### 2 O(n^2)
```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        if(length == 0) return 0;
        vector<int> stack;
        stack.push_back(nums[0]);
        
        for(int i = 1; i < length; i++) {
            if(nums[i] > stack.back()) {
                stack.push_back(nums[i]);
            } else {
                for(int j = 0; j < stack.size(); j++) {
                    if(nums[i] <= stack[j]) {
                        stack[j] = nums[i];
                        break;
                    }
                }
            }
        }        
        return stack.size();        
    }
};
```
#### 3 O(nlogn)
```c++
class Solution {
private:
int binary_search(vector<int> nums, int target) {
    int index = -1;
    int begin = 0;
    int end = nums.size()-1;
    
    while(index == -1) {
        int mid = (end+begin)/2;
        if(target==nums[mid]) {
            index = mid;
        } else if(target < nums[mid]) {
            if(mid==0 || target>nums[mid-1]) {
                index= mid;
            }
            end = mid-1;
        } else if(target>nums[mid]) {
            if(mid==nums.size()-1 || target < nums[mid+1]) {
                index = mid+1;
            }
            begin = mid+1;
        }
    }
    
    return index;
    
};
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        if(length == 0) return 0;
        vector<int> stack;
        stack.push_back(nums[0]);
        
        for(int i = 1; i < length; i++) {
            if(nums[i] > stack.back()) {
                stack.push_back(nums[i]);
            } else {
                int target = binary_search(stack, nums[i]);
                stack[target] = nums[i];
            }
        }        
        return stack.size();        
    }
};
```
### Java
```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int len = nums.length;
        if(len==0) return 0;
        ArrayList<Integer> stack = new ArrayList<>();
        stack.add(nums[0]);
        
        for(int i=1; i<len; i++) {
            if(nums[i] > stack.get(stack.size()-1)) {
                stack.add(nums[i]);
            } else {
                for(int j=0; j<stack.size(); j++) {
                    if(stack.get(j)>=nums[i]) {
                        stack.set(j, nums[i]);
                        break;
                    }
                }
            }
        }
        
        return stack.size();
    }
}
```
