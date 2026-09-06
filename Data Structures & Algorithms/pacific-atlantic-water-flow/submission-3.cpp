class Solution {
   public:
    void solve(vector<vector<int>>&heights,int i, int j,vector<vector<int>>&visited,vector<vector<int>>&mp){
        int currVal = heights[i][j];
        int rLen = heights.size();
        int cLen = heights[0].size();

        mp[i][j] = true;
        visited[i][j]=1;
       
        // up  i-1,j
        if(i>0 && heights[i-1][j]>=currVal && !visited[i-1][j]){
           solve(heights,i-1,j,visited,mp);
        }
        // down i+1,j
        if(i+1<rLen && heights[i+1][j]>=currVal && !visited[i+1][j]){
            solve(heights,i+1,j,visited,mp);
        }
        //left i,j-1
         if(j>0 && heights[i][j-1]>=currVal && !visited[i][j-1]){
            solve(heights,i,j-1,visited,mp);
        }
        //right i,j+1
        if(j+1<cLen && heights[i][j+1]>=currVal && !visited[i][j+1]){
            solve(heights,i,j+1,visited,mp);
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>visited1(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>>visited2(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>>result;
        vector<vector<int>>reachP(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>>reachA(heights.size(),vector<int>(heights[0].size(),0));

        // mark pacific reachable cells
        for(int i = 0;i<heights[0].size();i++)solve(heights,0,i,visited1,reachP);
        for(int i = 0;i<heights.size();i++) solve(heights,i,0,visited1,reachP);

        // mark atlantic reachable cells
        for(int i = 0;i<heights[0].size();i++) solve(heights,heights.size()-1,i,visited2,reachA);
        for(int i = 0;i<heights.size();i++) solve(heights,i,heights[0].size()-1,visited2,reachA);

        // add both reachable in result
        for(int i = 0;i<heights.size();i++){
            for(int j =0;j<heights[0].size();j++){
                if(reachA[i][j] && reachP[i][j]) {
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    result.push_back(temp);
                }
            }
        }

        return result;
    }
};

