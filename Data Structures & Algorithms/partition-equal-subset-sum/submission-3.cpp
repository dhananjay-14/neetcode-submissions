class Solution {
public:
    int total=0; 
    bool solve(vector<int>&nums,int ind, int sum,vector<vector<int>>&dp){
        if(sum==total/2) return true;
        if(ind==nums.size()){
            if(sum==total/2) return true;
            return false;
        }

        if(dp[ind][sum]!=-1) return dp[ind][sum];

        // pick 
        bool pick = solve(nums,ind+1,sum-nums[ind],dp);

        bool notPick = solve(nums,ind+1,sum,dp);

        return dp[ind][sum] = pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        for(auto el:nums) total += el;
        if(total%2!=0) return false;
        vector<vector<int>>dp(nums.size(),vector<int>(total+1,-1));
        return solve(nums,0,total,dp);
    }
};
