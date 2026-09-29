class Solution {
public:
    int solve(int i, int j, int m, int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1) return 1;
        // left

        if(dp[i][j]!=-1) return dp[i][j];
        int left = 0; int down = 0;
        if(j+1<=n-1) left = solve(i,j+1,m,n,dp);

        if(i+1<=m-1) down = solve(i+1,j,m,n,dp);

        return dp[i][j] = left + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};
