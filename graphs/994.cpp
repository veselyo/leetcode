class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            queue<pair<int, int>> rottenQ;
            unordered_set<int> rotten;
            int numFruit = 0;
            int numRotten = 0;
            int time = 0;
    
            // add currently rotten and count fruit
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    if (grid[i][j] == 2) {
                        rottenQ.push({i, j});
                        numFruit++;
                    }
                    else if (grid[i][j] == 1) numFruit ++;
                }
            }
    
            while (true) {
                queue<pair<int, int>> tempQ;
                
                // add new fruit that will rot on the next minute
                while (!rottenQ.empty()) {
                    pair<int, int> cordinates = rottenQ.front();
                    rottenQ.pop();
                    numRotten++;
    
                    int i = cordinates.first;
                    int j = cordinates.second;
    
                    // add right
                    if (j + 1 < grid[i].size() && grid[i][j + 1] == 1) {
                        tempQ.push({i, j + 1});
                        grid[i][j + 1] = 2;
                    }
    
                    // add left
                    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                        tempQ.push({i, j - 1});
                        grid[i][j - 1] = 2;
                    }
    
                    // add down
                    if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
                        tempQ.push({i + 1, j});
                        grid[i + 1][j] = 2;
                    }
    
                    // add up
                    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                        tempQ.push({i - 1, j});
                        grid[i - 1][j] = 2;
                    }
                }
    
                // check if we're done
                if (tempQ.empty()) {
                    if (numRotten != numFruit) {
                        return -1;
                    }
                    else return time;
                }
    
                rottenQ.swap(tempQ);
                time++;
            }
        }
    };