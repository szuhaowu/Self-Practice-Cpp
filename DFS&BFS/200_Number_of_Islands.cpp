//Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//
//Input:
//11110
//11010
//11000
//00000
//
//Output: 1
//Example 2:
//
//Input:
//11000
//11000
//00100
//00011
//
//Output: 3



// DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        int num = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j] == '1') {
                    num++;
                    visit(i, j, grid);
                }
            }
        }
        return num;
    }
private:
    void visit(int i, int j, vector<vector<char>>& grid){
        if(i<0 || i==grid.size() || j<0 || j==grid[0].size() || grid[i][j] == '0'){ return;}
        else{
            grid[i][j] = '0';
            visit(i-1,j,grid);
            visit(i+1,j,grid);
            visit(i,j-1,grid);
            visit(i,j+1,grid);
        }
    }
};

//BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        int num = 0;
        queue<pair<int, int>> q;
        vector<int> dirX{ -1,0,1,0 }, dirY{ 0,1,0,-1 };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;
                num++;
                q.push({ i,j });
                while (!q.empty()) {
                    pair<int, int> index = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int x = index.first + dirX[k], y = index.second + dirY[k];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
                            grid[x][y] = '0';
                            q.push({ x,y });
                        }
                    }
                }
            }
        }
        return num;
    }
};