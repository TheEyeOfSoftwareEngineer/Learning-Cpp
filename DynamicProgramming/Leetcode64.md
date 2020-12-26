## Leetcode 64 - Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
```
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
```
Example 2:
```
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
```
Constraints:
```
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
```
### C++
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int row = grid.size();
        int col = grid[0].size();
        
        // vector<vector<int>> dp(row, vector<int>(col, 0));
        int dp[row][col];
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j ++) {
                dp[i][j] = 0;
            }
        }
        
        dp[0][0] = grid[0][0];
        
        for(int i = 1; i < col; i++) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        
        for(int i = 1; i < row; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
            for(int j = 1; j < col; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[row-1][col-1];
    }
};
```
### Java
```java
class Solution {
    public int minPathSum(int[][] grid) {
        int row = grid.length;
        if(row==0) return 0;
        int col = grid[0].length;
        
        int dp[][] = new int[row][col];
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = grid[0][0];
        
        for(int i = 1; i < col; i++) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        
        for(int i = 1; i < row; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
            for(int j = 1; j < col; j++) {
                dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[row-1][col-1];
    }
}
```
