class Solution {
public:
    void dfs(int r, int c,vector<vector<int>>&visited, vector<vector<char>>&grid){
        visited[r][c]=1;
        // up 
        char ch;
        if(r-1>=0){
            ch = grid[r-1][c];
            if(!visited[r-1][c] && ch=='1')dfs(r-1,c,visited,grid);
        }

        // down
        if(r+1<=(grid.size()-1)){
            ch = grid[r+1][c];
            if(!visited[r+1][c] && ch=='1')dfs(r+1,c,visited,grid);
        }

        //left
        if(c-1>=0){
            ch = grid[r][c-1];
            if(!visited[r][c-1] && ch=='1')dfs(r,c-1,visited,grid);
        }

        //right
        if(c+1<=(grid[0].size()-1)){
            ch = grid[r][c+1];
            if(!visited[r][c+1] && ch=='1')dfs(r,c+1,visited,grid);
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int count=0;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i =0;i<grid.size();i++){
            for(int j= 0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(i,j,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
