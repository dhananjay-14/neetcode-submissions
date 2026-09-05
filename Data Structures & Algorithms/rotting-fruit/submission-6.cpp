class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Put ALL rotten oranges initially
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({0, {i, j}});
                    visited[i][j] = 1;
                }
            }
        }

        int time = 0;

        while(!q.empty()) {
            int i = q.front().second.first;
            int j = q.front().second.second;
            int t = q.front().first;
            q.pop();

            time = max(time, t);

            // down
            if(i+1 < n && !visited[i+1][j] && grid[i+1][j] == 1) {
                q.push({t+1, {i+1,j}});
                visited[i+1][j] = 1;
                grid[i+1][j] = 2;
            }

            // up
            if(i-1 >= 0 && !visited[i-1][j] && grid[i-1][j] == 1) {
                q.push({t+1, {i-1,j}});
                visited[i-1][j] = 1;
                grid[i-1][j] = 2;
            }

            // left
            if(j-1 >= 0 && !visited[i][j-1] && grid[i][j-1] == 1) {
                q.push({t+1, {i,j-1}});
                visited[i][j-1] = 1;
                grid[i][j-1] = 2;
            }

            // right
            if(j+1 < m && !visited[i][j+1] && grid[i][j+1] == 1) {
                q.push({t+1, {i,j+1}});
                visited[i][j+1] = 1;
                grid[i][j+1] = 2;
            }
        }

        // Check if any fresh orange remains
        for(auto row : grid) {
            for(auto cell : row) {
                if(cell == 1)
                    return -1;
            }
        }

        return time;
    }
};