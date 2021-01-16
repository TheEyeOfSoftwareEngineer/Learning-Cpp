## Leetcode 54 - 螺旋矩阵

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:
```
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
```

示例 2:
```
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
```

### C++
```c++
class Solution {

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int l = 0;
        int t = 0;
        int r = matrix[0].size(); // height
        int b = matrix.size();    // width
        const int total = (r--) * (b--);      
        int d = 0;
        int x = 0;
        int y = 0;
        vector<int> ans;
        while (ans.size() < total - 1) {      
            if (d == 0) {
                while (x < r) ans.push_back(matrix[y][x++]);
                ++t;
            } else if (d == 1) {
                while (y < b) ans.push_back(matrix[y++][x]);
                --r;
            } else if (d == 2) {
                while (x > l) ans.push_back(matrix[y][x--]);
                --b;
            } else if (d == 3) {
                while (y > t) ans.push_back(matrix[y--][x]);
                ++l;
            }
            d = (d + 1) % 4;
        }
        if (ans.size() != total) ans.push_back(matrix[y][x]);
        return ans;
    }
};
```