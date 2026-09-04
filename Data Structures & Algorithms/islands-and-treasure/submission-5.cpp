class Solution {
public:
    int inf = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>>q;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i = 0;i<grid.size();i++){
            for(int j= 0; j<grid[0].size();j++){
                if(grid[i][j]==0){
                   tuple<int,int,int>t1(0,i,j);
                   visited[i][j]=1;
                   q.push(t1);
                }
            }
        }

        while(!q.empty()){
            tuple<int,int,int>t1 = q.front();
            q.pop();
            int lev = get<0>(t1);
            int i = get<1>(t1);
            int j = get<2>(t1);
            grid[i][j] = lev;

            // left -> i,j+1
            if(j+1<grid[0].size() && !visited[i][j+1] && grid[i][j+1]==inf){
                tuple<int,int,int>t(lev+1,i,j+1);
                visited[i][j+1] = 1;
                q.push(t);
            }

            // right -> i, j-1
            if(j>0 && !visited[i][j-1] && grid[i][j-1]==inf){
                tuple<int,int,int>t(lev+1,i,j-1);
                visited[i][j-1] = 1;
                q.push(t);
            }
            // up -> i-1,j
            if(i>0 && !visited[i-1][j] && grid[i-1][j]==inf){
                tuple<int,int,int>t(lev+1,i-1,j);
                visited[i-1][j] = 1;
                q.push(t);
            }
            // down -> i+1,j
            if(i+1<grid.size() && !visited[i+1][j] && grid[i+1][j]==inf){
                tuple<int,int,int>t(lev+1,i+1,j);
                visited[i+1][j] = 1;
                q.push(t);
            }
        }

        return;

    }
};