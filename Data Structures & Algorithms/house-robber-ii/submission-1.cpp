class Solution {
public:
    int solve(vector<int>&nums,int ind,vector<vector<int>>&dp,int first){
        if(ind>=nums.size()) return 0;

        if(dp[ind][first]!=-1) return dp[ind][first];

        //pick 
        int firstPick = first;
        if(ind==0) firstPick = 1;
        int ret1 = nums[ind] + solve(nums,ind+2,dp,firstPick);
        if(ind==nums.size()-1 && first ==1) ret1 = -1;
        if(ind==0) firstPick = 0;

        // notPick
        int ret2 = solve(nums,ind+1,dp,firstPick);

        return dp[ind][first] = max(ret1,ret2);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        return solve(nums,0,dp,0);
    }
};
