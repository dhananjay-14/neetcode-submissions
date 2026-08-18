class Solution {
public:
    void solve(vector<int>nums,int lev,vector<vector<int>>&res){
        if(nums.size()==lev){
            res.push_back(nums);
            return;
        }
        //include
        solve(nums,lev+1,res);
        //exclude
        vector<int>newNum;
        for(int i =0;i<nums.size();i++){
            if(i!=lev) newNum.push_back(nums[i]); 
        }
        solve(newNum,lev,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        solve(nums,0,result);
        return result;
    }
};
