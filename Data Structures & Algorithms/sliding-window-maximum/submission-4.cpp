class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int>pq;
        vector<int>result;
        unordered_map<int,int>mp;
        int start = 0;
        int end = k-1;
        for(int i = 0;i<k;i++){
            pq.push(nums[i]);
            mp[nums[i]]++;
        }
        while(end<nums.size()){
            int maxEl = pq.top();
            while(mp[maxEl]<1){
                pq.pop();
                maxEl = pq.top();
            }
            result.push_back(maxEl);
            mp[nums[start]]--;
            start++;
            end++;
            if(end<nums.size()){
                mp[nums[end]]++;
                pq.push(nums[end]);
            }
        }
        return result;
    }
};
