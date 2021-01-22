## Leetcode 169 - 多数元素

给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1：
```
输入：[3,2,3]
输出：3
```

示例 2：
```
输入：[2,2,1,1,1,2,2]
输出：2
```
 
进阶：

尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。


### C++
- 1
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        const int n = nums.size();
        for(const int num : nums) {
            if(++count[num] > n/2) return num;
        }
        return -1;
    }
};
```

- 2 Randomization
这种思路就是我随机选取一个数字然后再去检验，因为多数元素大于n/2次数，所以被随机选到的概率还是比较高的。
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        srand(time(nullptr));
        const int n = nums.size();
        while(true) {
            const int index = rand()%n;
            const int maj = nums[index];
            int count = 0;
            for(const int num : nums) {
                if(num == maj && ++count > n/2) return num;
            }
        }
        return -1;
    }
};
```

- 3 bit
这是对数字每一位的bit进行统计检测。如果多数元素i位置是1那么count就会超过n/2从而使得最终返回的元素maj该位置可以为1.同理对于其他位置的元素.
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int n = nums.size();
        
        int maj = 0;
        for(int i = 0; i < 32; i++) {
            int mask = 1 << i;
            int count = 0;
            for(const int num : nums) {
                if(num & mask) ++count;
            }
            if(count > n/2) maj |= mask;
        }
        return maj;
    }
};
```

- 4
这种方式非常有意思。就是假设第一个数是最多那个，然后遇到一样的就递增。如果遇到不一样的，就减少计数。如果最后这个数字变成了0说明这个数字不是最多的。最后留下来的那个就是不会被其他不同元素消减完个数的那个多数元素。
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums.front();
        int count = 0;
        for(const int num:nums) {
            if(num==maj) ++count;
            else if(--count==0) {
                count=1;
                maj = num;
            }
        }
        return maj;
    }
};
```

- 5 Sort
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
```

- 6 Partial sort
`nth_element`也是一种排序算法，但是他不是让整个数组都顺序完备而是确保选取的位置左边都小于选取位置的值。同理让右边大于那个位置的值。但是左边和右边都可以是无序的。
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
        return nums[nums.size()/2];
    }
};
```

- 7 Divide&Conquer
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size()-1);
    }
private:
    int majorityElement(vector<int>& nums, int l, int r) {
        if(l==r) return nums[l];
        const int m = l + (r - l)/2;
        const int ml = majorityElement(nums, l, m);
        const int mr = majorityElement(nums, m+1, r);
        if(ml == mr) return ml;
        return count(nums.begin()+l, nums.begin()+r+1, ml) > count(nums.begin()+l, nums.begin()+r+1, mr) ? ml : mr;

    }

};
```

- 8 
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size()-1).first;
    }
private:
    pair<int, int> majorityElement(const vector<int>& nums, int l, int r) {
        if(l==r) return {nums[l], 1};
        const int m = l + (r - l)/2;
        auto ml = majorityElement(nums, l, m);
        auto mr = majorityElement(nums, m+1, r);
        if(ml.first == mr.first) return {ml.first, ml.second+mr.second};
        if(ml.second > mr.second) {
            return {ml.first, ml.second + count(nums.begin()+m+1, nums.begin()+ r+ 1, ml.first)};            
        } else {
            return {mr.first, mr.second + count(nums.begin()+l, nums.begin()+ m + 1, mr.first)};            
        }
    }

};
```