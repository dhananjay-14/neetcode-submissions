class Solution {
public:
    int solve(vector<int>&coins,int ind,int curr, int tar,vector<vector<int>>&dp){
        if(curr==tar) return 1;
        if(ind==coins.size()) return 0;

        if(dp[ind][curr]!=-1) return dp[ind][curr];
        // pick
        int pick = 0;
        if(curr+coins[ind]<=tar) pick = solve(coins,ind,curr+coins[ind],tar,dp);

        //not pick
        int notPick = solve(coins,ind+1,curr,tar,dp);

        return dp[ind][curr] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins,0,0,amount,dp);
    }
};
