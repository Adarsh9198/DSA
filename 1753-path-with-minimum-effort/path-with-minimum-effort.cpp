class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> efforts(rows, vector<int>(cols, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        efforts[0][0] = 0;
        pq.push({0, 0, 0}); // {effort, row, col}

        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty()) {
            auto [current_effort, r, c] = pq.top();
            pq.pop();

            if (current_effort > efforts[r][c]) {
                continue;
            }

            if (r == rows - 1 && c == cols - 1) {
                return current_effort;
            }

            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int path_effort = abs(heights[r][c] - heights[nr][nc]);
                    int new_max_effort = max(current_effort, path_effort);

                    if (new_max_effort < efforts[nr][nc]) {
                        efforts[nr][nc] = new_max_effort;
                        pq.push({new_max_effort, nr, nc});
                    }
                }
            }
        }
        
        return 0; // Unreachable code for a valid grid
    }
};