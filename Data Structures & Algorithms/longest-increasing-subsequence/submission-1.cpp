class Solution {
public:
    int solve(vector<int>&nums,int ind,int prevInd,vector<vector<int>>&dp){
        //base case
        if(ind>=nums.size()) return 0;

        if(dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1];
        int pick = INT_MIN;
        int notPick = INT_MIN;
        //pick
        if(prevInd==-1 || nums[prevInd]<nums[ind])pick = 1 + solve(nums,ind+1,ind,dp);
        //not pick
        notPick = solve(nums,ind+1,prevInd,dp);
        // return max
        return dp[ind][prevInd+1] = max(pick,notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(nums,0,-1,dp);
    }
};
