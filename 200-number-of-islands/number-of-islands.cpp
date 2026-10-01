class Solution {
public:

    void BFS(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        q.push({r, c});
        grid[r][c] = '0';   // mark visited

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            
            if (x + 1 < m && grid[x + 1][y] == '1') {
                grid[x + 1][y] = '0';
                q.push({x + 1, y});
            }

            
            if (x - 1 >= 0 && grid[x - 1][y] == '1') {
                grid[x - 1][y] = '0';
                q.push({x - 1, y});
            }

            
            if (y + 1 < n && grid[x][y + 1] == '1') {
                grid[x][y + 1] = '0';
                q.push({x, y + 1});
            }

            
            if (y - 1 >= 0 && grid[x][y - 1] == '1') {
                grid[x][y - 1] = '0';
                q.push({x, y - 1});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == '1') {
                    BFS(grid, r, c);
                    count++;
                }
            }
        }

        return count;
    }
};