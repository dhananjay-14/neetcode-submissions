class Solution {
   public:
    bool isPacific(vector<vector<int>>&heights,int i, int j,vector<vector<int>>&visited,vector<vector<int>>&dp1){
        if(i==0 || j==0) return true;
        int currVal = heights[i][j];
        int rLen = heights.size();
        int cLen = heights[0].size();

        if(dp1[i][j]!=-1)return dp1[i][j];
        visited[i][j]=1;
       
        bool ret = false;
        // up  i-1,j
        if(i>0 && heights[i-1][j]<=currVal && !visited[i-1][j]){
            ret = ret || isPacific(heights,i-1,j,visited,dp1);
        }
        // down i+1,j
        if(i+1<rLen && heights[i+1][j]<=currVal && !visited[i+1][j]){
            ret = ret || isPacific(heights,i+1,j,visited,dp1);
        }
        //left i,j-1
         if(j>0 && heights[i][j-1]<=currVal && !visited[i][j-1]){
            ret = ret || isPacific(heights,i,j-1,visited,dp1);
        }
        //right i,j+1
        if(j+1<cLen && heights[i][j+1]<=currVal && !visited[i][j+1]){
            ret = ret || isPacific(heights,i,j+1,visited,dp1);
        }

        visited[i][j]=0;
        return dp1[i][j] = ret;
    }
    bool isAtlantic(vector<vector<int>>&heights,int i, int j,vector<vector<int>>&visited,vector<vector<int>>&dp){
        int currVal = heights[i][j];
        int rLen = heights.size();
        int cLen = heights[0].size();
        if(i==rLen-1 || j==cLen-1) return true;
        
        if(dp[i][j]!=-1)return dp[i][j];
        visited[i][j]=1;

        bool ret = false;
        // up  i-1,j
        if(i>0 && heights[i-1][j]<=currVal && !visited[i-1][j]){
            ret = ret || isAtlantic(heights,i-1,j,visited,dp);
        }
        // down i+1,j
        if(i+1<rLen && heights[i+1][j]<=currVal && !visited[i+1][j]){
            ret = ret || isAtlantic(heights,i+1,j,visited,dp);
        }
        //left i,j-1
         if(j>0 && heights[i][j-1]<=currVal && !visited[i][j-1]){
            ret = ret || isAtlantic(heights,i,j-1,visited,dp);
        }
        //right i,j+1
        if(j+1<cLen && heights[i][j+1]<=currVal && !visited[i][j+1]){
            ret = ret || isAtlantic(heights,i,j+1,visited,dp);
        }

        visited[i][j]=0;
        return dp[i][j]=ret;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>visited(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>>dp1(heights.size(),vector<int>(heights[0].size(),-1));
        vector<vector<int>>dp2(heights.size(),vector<int>(heights[0].size(),-1));
        vector<vector<int>>result;
        for(int i= 0;i<heights.size();i++){
            for(int j = 0;j<heights[0].size();j++){
                bool atl = isAtlantic(heights,i,j,visited,dp1);
                bool pac = isPacific(heights,i,j,visited,dp2);
                if(atl && pac){
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

