class KthLargest {
public:
    int kLar;
    vector<int>num;
    priority_queue<int>pq;
    KthLargest(int k, vector<int>& nums) {
        kLar = k;
        num = nums;
        for(auto el:num) pq.push(el);
    }
    
    int add(int val) {
        pq.push(val);
        int cnt = kLar-1;
        stack<int>st;
        while(cnt){
            int el = pq.top();
            st.push(el);
            pq.pop();
            cnt--;
        }
        int res = pq.top();
        while(!st.empty()){
            int el = st.top();
            st.pop();
            pq.push(el);
        } 
        return res;
    }
};
