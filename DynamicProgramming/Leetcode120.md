## Leetcode120 - Triangle
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

```
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

### C++
#### 1
```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int row = triangle.size();
        if(row == 0)  return 0;
        if(row == 1)  return triangle[0][0];
        vector<vector<int>> dp(row, vector<int>(row));
        dp[0][0] = triangle[0][0];
        
        for(int r = 1; r < row; r++) {
            int col = triangle[r].size();
            for(int c = 0; c < col; c++) {
                if(c==0) {
                    dp[r][c] = triangle[r][c] + dp[r-1][c];
                }
                else if(c==col-1) {
                    dp[r][c] = triangle[r][c] + dp[r-1][c-1];
                }
                else {
                    dp[r][c] = triangle[r][c] + min(dp[r-1][c-1], dp[r-1][c]);
                }
            }
        }
        
        int minimum = dp[row-1][0];
        
        for(int m = 1; m < row; m++) {
            minimum = min(minimum, dp[row-1][m]); 
        }
        
        return minimum;
        
    }
};
```
#### 2
```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        if(triangle.size() == 0) {
            return 0;
        }
        
        vector<vector<int>> dp;
        for(int i = 0; i < triangle.size(); i++) {
            dp.push_back(vector<int>());
            for(int j = 0; j < triangle[i].size(); j++) {
                dp[i].push_back(0);
            }
        }
        
        
        for(int i = 0; i < dp.size(); i++) {
            dp[dp.size()-1][i] = triangle[dp.size()-1][i];
        }
        
        
        for(int i = dp.size()-2;i >=0; i--) {
            for(int j = 0; j < dp[i].size(); j ++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }
};
```
### Java
```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle.size()==0) {
            return 0;
        }
        
        int[][] dp = new int[triangle.size()][triangle.size()];
        for(int i = 0; i < triangle.size(); i ++) {
            for(int j = 0; j < triangle.size(); j ++) {
                dp[i][j] = 0;
            }
        }
        
        for(int i = 0; i < dp.length; i++) {
            dp[dp.length-1][i] = triangle.get(dp.length-1).get(i);
        }
        
        for(int i = dp.length-2; i >=0 ; i--) {
            for(int j = 0; j < triangle.get(i).size(); j++) {
                System.out.println("j: " + j);
                dp[i][j] = triangle.get(i).get(j) + Math.min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];  
    }
}
```
