class Solution {
public:
    int solve(vector<int>&nums,int ind, int curr, int tar,map<pair<int,int>,int>&dp){
        if(ind==nums.size()){
            if(curr==tar)return 1;
            else return 0;
        }
        if(dp[{ind,curr}]!=-1) return dp[{ind,curr}];
        //add 
        int add = solve(nums,ind+1,curr+nums[ind],tar,dp);

        //sub
        int sub = solve(nums,ind+1,curr-nums[ind],tar,dp);

        return dp[{ind,curr}] = add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int>dp;
        int sum = 0;
        for(auto el:nums) sum += el;
        for(int i = 0;i<nums.size();i++){
            for(int j = -sum;j<=sum;j++){
                dp[{i,j}] = -1;
            }
        }
        return solve(nums,0,0,target,dp);
    }
};
