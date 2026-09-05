#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Edge cases: start or end cell is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        // 8-directional offsets
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        // Queue stores {row, col, current_path_length}
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1; // Mark as visited

        while (!q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();

            // Reached destination
            if (r == n - 1 && c == n - 1) {
                return dist;
            }

            for (auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // Check bounds and if cell is unvisited (0)
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1; // Mark visited immediately
                    q.push({nr, nc, dist + 1});
                }
            }
        }

        return -1;
    }
};