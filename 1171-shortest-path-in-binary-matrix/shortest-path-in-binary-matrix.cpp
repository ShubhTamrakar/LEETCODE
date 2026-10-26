
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        int dir[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},            {0, 1},
            {1, -1},  {1, 0},   {1, 1}
        };

        grid[0][0] = 1;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int dist = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            if (r == n-1 && c == n-1)
                return dist;

            for (auto &d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 0) {

                    grid[nr][nc] = 1;
                    q.push({dist + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};
