class Solution {
public:
    int solve(string& word1, string& word2, int i, int j,vector<vector<int>>&dp){
        if(j==word2.size()){
            if(i==word1.size()) return 0;
            else return word1.size()-i;
        }
        if(i==word1.size()){
            return word2.size()-j;
        }

        if(dp[i][j]!=-1) return dp[i][j];
        int res = INT_MAX;
        if(word1[i]==word2[j]) res = min(res,solve(word1,word2,i+1,j+1,dp));
        else{
            // insert
            res = min(res,1+solve(word1,word2,i,j+1,dp));

            //delete
            res = min(res,1+solve(word1,word2,i+1,j,dp));

            //replace
            res = min(res,1+solve(word1,word2,i+1,j+1,dp));
        }

        return dp[i][j] =  res;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return solve(word1,word2,0,0,dp);
    }
};
