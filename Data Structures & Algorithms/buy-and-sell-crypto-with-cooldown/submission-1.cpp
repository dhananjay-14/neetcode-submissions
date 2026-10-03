class Solution {
public:
    int solve(vector<int>& prices, int last, int sell, int curr,
              vector<vector<vector<int>>>& dp) {

        if (curr == prices.size())
            return 0;

        if (dp[curr][last + 2][sell] != -1)
            return dp[curr][last + 2][sell];

        int ans = 0;

        if (sell) {
            // buy
            int buy = 0;
            if (last != curr - 1)
                buy = solve(prices, curr, 0, curr + 1, dp);

            // not buy
            int notBuy = solve(prices, last, sell, curr + 1, dp);

            ans = max(buy, notBuy);

        } else {
            // sell
            int sellProfit = 0;

            if (last != -2 && prices[curr] > prices[last]) {
                int prft = prices[curr] - prices[last];

                sellProfit = prft +
                    solve(prices, curr, 1, curr + 1, dp);
            }

            // not sell
            int notSell =
                solve(prices, last, sell, curr + 1, dp);

            ans = max(sellProfit, notSell);
        }

        return dp[curr][last + 2][sell] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // last ranges from -2 to n-1
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n + 2, vector<int>(2, -1))
        );

        return solve(prices, -2, 1, 0, dp);
    }
};