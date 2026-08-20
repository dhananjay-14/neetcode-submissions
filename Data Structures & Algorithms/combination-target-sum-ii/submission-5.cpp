class Solution {
public:
    int tar;
    
    void getUniqueCombinations(vector<int>&nums,int ind,int sum,vector<int>&curr,vector<vector<int>>&res,unordered_map<int,int>&mp){
        bool lsame = false;
        if(sum==tar){
            res.push_back(curr);
            return;
        }else if(sum>tar || ind==nums.size())return;
        //pick 
        curr.push_back(nums[ind]);
        sum+=nums[ind];
        int incValue;
        bool enter = false;
        if(mp[nums[ind]]>1){
            incValue = ind;
            mp[nums[ind]]--;
            enter = true;
        }else{
            incValue = ind+1;
        }
        getUniqueCombinations(nums,incValue,sum,curr,res,mp);
        curr.pop_back();
        sum-=nums[ind];
        if(enter) mp[nums[ind]]++;
        //not pick
        getUniqueCombinations(nums,ind+1,sum,curr,res,mp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        unordered_map<int,int>mp;
        vector<int>uniqCan;
        for(auto el:candidates) mp[el]++;
        for(auto it:mp) uniqCan.push_back(it.first);
        tar = target;
        vector<int>curr = vector<int>();
        getUniqueCombinations(uniqCan,0,0,curr,result,mp);
        return result;
    }
};
