class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto el:nums){
            mp[el]++;
            if(mp[el]==2) return el;
        }
        return 0;
    }
};
