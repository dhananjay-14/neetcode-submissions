class Solution {
public:
    void swap(vector<int>&nums,int ind1,int ind2){
        int temp = nums[ind1];
        nums[ind1] = nums[ind2];
        nums[ind2] = temp;
        return;
    }
    void cal(vector<int>nums,int ind,vector<vector<int>>&res){
        if(ind==nums.size()-1){
            res.push_back(nums);
            return;
        }

        for(int i =ind;i<nums.size();i++){
            swap(nums,ind,i);
            cal(nums,ind+1,res);
            swap(nums,ind,i);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        cal(nums,0,res);
        return res;
    }
};
