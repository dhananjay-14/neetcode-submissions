class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       vector<int>result;
       for(auto el:nums) mp[el]++;

       vector<vector<int>>freq(nums.size()+1);
       for(auto el:mp){
          freq[el.second].push_back(el.first);
       }

       for(int i = nums.size();i>=0;i--){
          if(freq[i].size()==0) continue;
          for(auto el:freq[i]) {
            result.push_back(el);
            if(result.size()==k) break;
          }
          if(result.size()==k) break;
       }
       return result;
    }
};
