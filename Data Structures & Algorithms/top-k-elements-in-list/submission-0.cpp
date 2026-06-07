class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>result;
        vector<vector<int>>freq;
        for(auto el:nums){
            mp[el]++;
        }

        for(auto el:mp){
            vector<int> vec;
            vec.push_back(el.first);
            vec.push_back(el.second);
            freq.push_back(vec);
        }

        sort(freq.begin(),freq.end(),[](vector<int>a,vector<int>b){
            return a[1] > b[1];
        });

        for(int i = 0;i<k;i++){
            result.push_back(freq[i][0]);
        }
        return result;
    }
};
