class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto el:nums){
            int val = pq.top();
            if(pq.size()<k){
                pq.push(el);
            }else if(el>val){
                pq.pop();
                pq.push(el);
            }
        }
        return pq.top();
    }
};
