class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int index ;
    vector<int>num;
    KthLargest(int k, vector<int>& nums) {
       index = k;
       num = nums;
       for(auto el:num){
           pq.push(el);
           if(pq.size()>index) pq.pop();
       }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>index) pq.pop();
        return pq.top();
    }
};
