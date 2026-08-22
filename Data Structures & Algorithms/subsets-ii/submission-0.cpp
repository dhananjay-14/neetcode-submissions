class Solution {
public:
    unordered_map<int,int>mp;
    void solve(int ind, vector<int>&nums,vector<int>&curr,vector<vector<int>>&res){
        if(ind==nums.size()){
            res.push_back(curr);
            return;
        }

        //pick
        int nextInd = ind;
        curr.push_back(nums[ind]);
        mp[nums[ind]]--;
        if(mp[nums[ind]]==0) nextInd = ind+1;
        solve(nextInd,nums,curr,res);

        //not pick
        curr.pop_back();
        mp[nums[ind]]++;
        solve(ind+1,nums,curr,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        for(auto el:nums) mp[el]++;
        vector<int>newNums;
        for(auto it:mp) newNums.push_back(it.first);
        vector<int>curr;
        solve(0,newNums,curr,res);
        return res;
    }
};
