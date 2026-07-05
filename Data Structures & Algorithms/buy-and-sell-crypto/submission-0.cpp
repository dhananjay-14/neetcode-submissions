class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minAmt = INT_MAX;
        vector<int>minTillInd(prices.size());
        for(int i = 0;i<prices.size();i++){
            minTillInd[i] = min(minAmt,prices[i]);
            if(minTillInd[i]<minAmt) minAmt = minTillInd[i];
        }

        int maxProfit = 0;
        for(int i = 1;i<prices.size();i++){
            int profit = prices[i] - minTillInd[i-1];
            if(profit>maxProfit) maxProfit = profit;
        }
        return maxProfit;
    }
};
