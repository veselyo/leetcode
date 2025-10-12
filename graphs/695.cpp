class Solution {
    public:
        int search(vector<vector<int>>& grid, int row, int col, int m, int n, vector<vector<bool>>& explored) {
            explored[row][col] = true;
            int area = 1;
            
            // right
            if (row + 1 < m && grid[row + 1][col] == 1 && !explored[row + 1][col]) {
                area += search(grid, row + 1, col, m, n, explored);
            }
            
            // down
            if (col + 1 < n && grid[row][col + 1] == 1 && !explored[row][col + 1]) {
                area += search(grid, row, col + 1, m, n, explored);
            }
            
            // left
            if (row - 1 >= 0 && grid[row - 1][col] == 1 && !explored[row - 1][col]) {
                area += search(grid, row - 1, col, m, n, explored);
            }
            
            // up
            if (col - 1 >= 0 && grid[row][col - 1] == 1 && !explored[row][col - 1]) {
                area += search(grid, row, col - 1, m, n, explored);
            }
            
            return area;
        }
    
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<bool>> explored(m, vector<bool>(n, false));
            int maxSize = 0;
            for (int row = 0; row < grid.size(); row++) {
                for (int col = 0; col < grid[0].size(); col++) {
                    if (grid[row][col] == 1) {
                        if (!explored[row][col]) {
                            maxSize = max(maxSize, search(grid, row, col, m, n, explored));
                        }
                    }
                }
            }
            return maxSize;
        }
    };    