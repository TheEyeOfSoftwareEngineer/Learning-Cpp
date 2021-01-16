## Leetcode 59 - 螺旋矩阵 II

给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:
```
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```

### C++
```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int dir = 2, x = 0, y = 0;
        int max_x = n - 1, max_y = n - 1;
        int min_x = 0, min_y = 1;
        int i = 0;
    
        while (++i <= n*n) {
            ans[y][x] = i;
            switch (dir) {
                // up
                case 1: if (--y == min_y) { dir = 2; ++min_y; } break;
                // right
                case 2: if (++x == max_x) { dir = 3; --max_x; } break;
                // down
                case 3: if (++y == max_y) { dir = 4; --max_y; } break;
                // left
                case 4: if (--x == min_x) { dir = 1; ++min_x; } break;
            }
        }
    
        return ans;
    }
};
```