## Leetcode 34 - Search for a Range
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

### C++
- 1
```c++
class Solution {
private:
    
    void search(vector<int> &nums, int target, int begin, int end, vector<int> &r) {
        if(end<begin) {
            return;
        }
        int mid = begin + (end-begin)/2;
        if(nums[mid] == target) {
            if(r[0]==-1) {
                r[0] = mid;                    
            } 
            if(r[0]==-1) {
                r[1] = mid;
            }
            if(mid<r[0]) {
                r[0] = mid;
            }
            if(mid>r[1]) {
                r[1] = mid;
            }        
        }
        search(nums, target, begin, mid-1, r);
        search(nums, target, mid+1, end, r);
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size()-1;
        vector<int> r;
        r.push_back(-1);
        r.push_back(-1);
        search(nums, target, begin, end, r);
        return r;        
    }
};
```
- 2
```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size()-1;
        vector<int> r;
        r.push_back(-1);
        r.push_back(-1);
        while(begin<=end) {
            if(r[0]==-1 && nums[begin]==target) {
                r[0] = begin;
                r[1] = begin;
            } else if(r[0]!=-1&&nums[begin]==target) {
                r[1] = begin;
            }
            begin ++;
        }
        return r;
    }
};
```
- 3
```c++
class Solution {
private:
    int left_bound(vector<int> &nums, int target) {
        int begin  = 0; 
        int end = nums.size()-1;
        while(begin<=end) {
            int mid = begin+(end-begin)/2;
            if(target == nums[mid]) {
                if(mid==0 || nums[mid-1]<target) {
                    return mid;
                }
                end = mid-1;
            }
            else if(target<nums[mid]) {
                end = mid-1;
            }
            else {
                begin = mid+1;
            }
        }
        
        return -1;
    }
    int right_bound(vector<int> &nums, int target) {
        int begin  = 0; 
        int end = nums.size()-1;
        while(begin<=end) {
            int mid = begin+(end-begin)/2;
            if(target == nums[mid]) {
                if(mid==nums.size()-1 || nums[mid+1]>target) {
                    return mid;
                }
                begin = mid+1;
            }
            else if(target<nums[mid]) {
                end = mid-1;
            }
            else {
                begin = mid+1;
            }
        }      
        return -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> r;
        r.push_back(left_bound(nums, target));
        r.push_back(right_bound(nums, target));
        return r;
    }
};
```

### Java
```java
class Solution {
    private int extremeInsertionIndex(int[] nums, int target, boolean left) {
        int lo = 0;
        int hi = nums.length;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target || (left && target == nums[mid])) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }

        return lo;
    }

    public int[] searchRange(int[] nums, int target) {
        int[] targetRange = {-1, -1};

        int leftIdx = extremeInsertionIndex(nums, target, true);

        if (leftIdx == nums.length || nums[leftIdx] != target) {
            return targetRange;
        }

        targetRange[0] = leftIdx;
        targetRange[1] = extremeInsertionIndex(nums, target, false)-1;

        return targetRange;
    }
}
```