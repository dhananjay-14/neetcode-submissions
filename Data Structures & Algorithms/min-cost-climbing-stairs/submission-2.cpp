class Solution {
public:
    int solve(int ind,int sum,vector<int>&cost,vector<vector<int>>&dp){
        if(ind>=cost.size())return sum;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        sum += cost[ind];
        return dp[ind][sum]= min(solve(ind+1,sum,cost,dp),solve(ind+2,sum,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int tot = 0;
        for(auto el:cost) tot+=el;
        vector<vector<int>>dp(cost.size(),vector<int>(tot+1,-1));
        return min(solve(0,0,cost,dp),solve(1,0,cost,dp));
    }
};
