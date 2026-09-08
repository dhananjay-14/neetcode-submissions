class Solution {
public:
    int solve(vector<int>&nums,int ind,vector<int>&dp){
        if(ind>=nums.size()) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        //pick
        int ret1 = nums[ind] + solve(nums,ind+2,dp);

        //notPick 
        int ret2 = solve(nums,ind+1,dp);
        return dp[ind] = max(ret1,ret2);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};
