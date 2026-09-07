class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto item: nums){
            mp[item]++;
        }
        for(auto it:mp){
            if(it.second > 1) return true;
        }
        return false;
    }
};