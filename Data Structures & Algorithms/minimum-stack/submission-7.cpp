class MinStack {
public:
    vector<int>arr;
    stack<int>st;
    int tp;
    MinStack() {
        tp = -1;
    }
    
    void push(int val) {
        if(st.empty() || val<=st.top()){
            st.push(val);
        }
        arr.push_back(val);
        tp++;
    }
    
    void pop() {
        int no = arr[arr.size()-1];
        if(!st.empty() && st.top()==no){
            st.pop();
        }
        arr.pop_back();
        tp--;
    }
    
    int top() {
        return arr[tp];
    }
    
    int getMin() {
        return st.top();
    }
};
