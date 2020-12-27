## Leetcode 200 - Number of Islands

Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```
Example 2:
```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```
Constraints:
```
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
```

### C++
#### 1 DFS
```c++
class Solution {
private:
    void DFS(vector<vector<int>> &mark, vector<vector<char>> &grid, int x, int y) {
        
        mark[x][y] = 1;
        
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        
        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX < 0 || newX >= mark.size() || newY < 0 || newY >= mark[newX].size()) {
                continue;
            }
            if(mark[newX][newY]==0 && grid[newX][newY]=='1') {
                DFS(mark, grid, newX, newY);
            }
        }
        
    }
    
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row==0) return 0;
        int col = grid[0].size();
        
        int num = 0;
        
        vector<vector<int>> mark;
        
        for(int i = 0; i < row; i++) {
            mark.push_back(vector<int>());
            for(int j = 0; j < col; j++) {
                mark[i].push_back(0);
            }
        }
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(mark[i][j] == 0 && grid[i][j] == '1') {
                    DFS(mark, grid, i, j);
                    num ++;
                }
            }
        }
        return num;
        
    }
};
```
#### 2 BFS
```c++
class Solution {
private:
    void BFS(vector<vector<int>> &mark, vector<vector<char>> &grid, int x, int y) {
        
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        
        queue<pair<int, int>> Q;
        Q.push(make_pair(x, y));
        mark[x][y] = 1;
        while(!Q.empty()) {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            for(int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX < 0 || newY < 0 || newX >= mark.size() || newY >= mark[newX].size()) {
                    continue;
                }
                if(mark[newX][newY]==0 && grid[newX][newY]=='1') {
                    Q.push(make_pair(newX, newY));
                    mark[newX][newY] = 1;
                }
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int num = 0;
        
        vector<vector<int>> mark;
        for(int i = 0; i < row; i++) {
            mark.push_back(vector<int>());
            for(int j = 0; j < col; j++) {
                mark[i].push_back(0);
            }
        }
        
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(mark[i][j]==0 && grid[i][j]=='1') {
                    BFS(mark, grid, i, j);
                    num ++;
                }
            }
        }
        
        return num;
    }
};
```
### Java
#### 1 DFS
```java
class Solution {
    public int numIslands(char[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        
        int num = 0;
        
        int[][] mark = new int[row][col];
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                mark[i][j] = 0;
            }
        }
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(mark[i][j]==0 && grid[i][j]=='1') {
                    DFS(mark, grid, i, j);
                    num ++;
                }
            }
        }
            
        return num;
    }
    
    private void DFS(int[][] mark, char[][] grid, int x, int y) {
        
        mark[x][y] = 1;
        
        final int dx[] = {-1, 1, 0, 0};
        final int dy[] = {0, 0, -1, 1};
        
        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if(newX < 0 || newY < 0 || newX >= mark.length || newY >= mark[newX].length) {
                continue;
            }
            
            if(mark[newX][newY] == 0 && grid[newX][newY] == '1') {
                DFS(mark, grid, newX, newY);
            }
        }
    }
}
```
#### 2 BFS
```java
class Solution {
    
    static final int[] dx = {-1, 1, 0, 0};
    static final int[] dy = {0, 0, -1, 1};
    
    public int numIslands(char[][] grid) {
        int num = 0;
        int row = grid.length;
        int col = grid[0].length;
        int[][] mark = new int[row][col];
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                mark[i][j] = 0;
            }
        }
        
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(mark[i][j]==0 && grid[i][j]=='1') {
                    BFS(mark, grid, i, j);
                    num ++;
                }
            }
        }
        
        return num;
    }
    
    private void BFS(int[][] mark, char[][] grid, int x, int y) {
        Queue<QEntity> q = new LinkedList<QEntity>();
        q.add(new QEntity(x, y));
        mark[x][y] = 1;
        
        while(!q.isEmpty()) {
            x = q.peek().getX();
            y = q.peek().getY();
            q.poll();
            for(int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if(newX < 0 || newY < 0 || newX >= mark.length || newY >= mark[newX].length) {
                    continue;
                }
                
                if(mark[newX][newY]==0 && grid[newX][newY]=='1') {
                    q.add(new QEntity(newX, newY));
                    mark[newX][newY] = 1;
                }
                
            }
        }
        
    }
    
    
    class QEntity {
        Integer x;
        Integer y;
        
        public QEntity(Integer x, Integer y) {
            this.x = x;
            this.y = y;
        }
        
        Integer getX() {
            return this.x;
        }
        
        Integer getY() {
            return this.y;
        }
        
    }
}
```
