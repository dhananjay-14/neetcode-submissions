class Solution {
   public:
    void dfs(int r, int c,vector<vector<int>>&visited, vector<vector<int>>&grid,int& count){
        visited[r][c]=1;
        count++;
        // up 
        char ch;
        if(r-1>=0){
            ch = grid[r-1][c];
            if(!visited[r-1][c] && ch==1)dfs(r-1,c,visited,grid,count);
        }

        // down
        if(r+1<=(grid.size()-1)){
            ch = grid[r+1][c];
            if(!visited[r+1][c] && ch==1)dfs(r+1,c,visited,grid,count);
        }

        //left
        if(c-1>=0){
            ch = grid[r][c-1];
            if(!visited[r][c-1] && ch==1)dfs(r,c-1,visited,grid,count);
        }

        //right
        if(c+1<=(grid[0].size()-1)){
            ch = grid[r][c+1];
            if(!visited[r][c+1] && ch==1)dfs(r,c+1,visited,grid,count);
        }

        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int countMax = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int count = 0;
                    dfs(i, j, visited, grid,count);
                    countMax = max(count,countMax);
                }
            }
        }
        return countMax;
    }
};
