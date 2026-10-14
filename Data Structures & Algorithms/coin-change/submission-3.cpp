class Solution {
public:
    long long solve(vector<int>& coins, int ind, int curr, int amount,vector<vector<long long>>&dp) {
        if (curr == amount) return 0;
        if (ind >= coins.size()) return LLONG_MAX;

        if(dp[ind][curr]!=-1) return dp[ind][curr];
        // pick
        long long pick = LLONG_MAX;
        if (coins[ind] <= amount - curr){
            long long res = solve(coins, ind, curr + coins[ind], amount,dp);
            if (res != LLONG_MAX)
                pick = 1 + res;
        }

        // not pick
        long long notPick = solve(coins, ind + 1, curr, amount,dp);

        return dp[ind][curr] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int sum = 0;
        // for(auto el:coins) sum+=el;
        vector<vector<long long>>dp(coins.size(),vector<long long>(amount+1,-1));
        long long val = solve(coins, 0, 0, amount,dp);

        if (val != LLONG_MAX)
            return val;
        return -1;
    }
};