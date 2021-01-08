## Leetcode 35 - Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
### C++
```c++
class Solution {        
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size()-1;
        while(begin<=end) {
            int mid = begin + (end-begin)/2;
            if(nums[mid]==target) {
                return mid;
            } else if(nums[mid]>target) {
                end = mid-1;
            } else {
                begin = mid+1;
            }            
        }
        
        return begin;
    }
};
```
### Java
```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int begin = 0;
        int end = nums.length-1;
        while(begin<=end) {
            int mid = begin+(end-begin)/2;
            if(nums[mid]==target) {
                return mid;
            } else if(nums[mid]>target) {
                end = mid-1;
            } else {
                begin = mid+1;
            }                
        }
        
        return begin;
    }
}
```

