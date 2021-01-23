## Leetcode 215 - 数组中的第K个最大值

在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:
```
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
```

示例 2:
```
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
```

说明:
```
你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
```

### C++
- 1
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < nums.size(); ++ i ) {
            if( q.size() < k)
                q.push(nums[i]);
            else if ( q.top() < nums[i] ) {
                q.pop();
                q.push(nums[i]);
            } 
        }
        return q.top();
    }
};
```

- 2
```c++
class Solution {

public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int> q(nums.begin(), nums.end());
      for (int i = 0; i < k - 1; ++i) {
          q.pop();
      }
      return q.top();
    }    
};
```

- 3
```c++
/// Based on Quick Sort Partition.
/// Time Complexity:  O(n)
/// Space Complexity: O(logn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return findKthLargest(nums, 0, nums.size()-1 , k - 1 );
    }

private:
    int findKthLargest(vector<int>& nums, int l, int r, int k){
        if( l == r )
            return nums[l];
        int p = partition(nums, l, r);
        if( p == k )
            return nums[p];
        else if( k < p )
            return findKthLargest(nums, l, p-1, k);
        else // k > p
            return findKthLargest(nums, p+1 , r, k);
    }
    int partition( vector<int>& nums, int l, int r ){
        int p = rand()%(r-l+1) + l;
        swap( nums[l] , nums[p] );
        int lt = l + 1; //[l+1...lt) > p ; [lt..i) < p
        for( int i = l + 1 ; i <= r ; i ++ )
            if( nums[i] > nums[l] )
                swap(nums[i], nums[lt++]);
        swap(nums[l], nums[lt-1]);
        return lt-1;
    }
};
```