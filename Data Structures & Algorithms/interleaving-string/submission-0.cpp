class Solution {
public:
    int n;
    int m;
    int o;
    bool solve(string& s1, string& s2, string& s3, int i , int j, int k,vector<vector<vector<int>>>&dp){
        if(i==n && j==m && k == o)return true;
        if(k>=o) return false;

        if(dp[i][j][k]!=-1)return dp[i][j][k];
        bool res = false;

        if(s1[i]==s3[k]) res = solve(s1,s2,s3,i+1,j,k+1,dp);
        if(s2[j]==s3[k]) res = res || solve(s1,s2,s3,i,j+1,k+1,dp);
        return dp[i][j][k] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n= s1.length();
        m = s2.length();
        o = s3.length();

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(o+1,-1)));
        return solve(s1,s2,s3,0,0,0,dp); 
    }
};
