class Solution {
public:
    int tar;
    void getUniqueCombinations(vector<int>&nums,int ind,int sum,vector<int>&curr,vector<vector<int>>&res){
        if(sum==tar){
            res.push_back(curr);
            return;
        }else if(sum>tar || ind==nums.size())return;

        //pick 
        curr.push_back(nums[ind]);
        sum+=nums[ind];
        getUniqueCombinations(nums,ind,sum,curr,res);
        curr.pop_back();
        sum-=nums[ind];
        //not pick
        getUniqueCombinations(nums,ind+1,sum,curr,res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        tar = target;
        vector<int>curr = vector<int>();
        int sum = 0;
        getUniqueCombinations(nums,0,0,curr,result);
        return result;
    }
};
