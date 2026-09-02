class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int st = nums[0];
        for(int i =1;i<nums.size();i++){
            st = st ^ nums[i];
        }
        return st;
    }
};
