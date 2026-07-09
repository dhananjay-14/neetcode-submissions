class MinStack {
public:
    vector<int>arr;
    int tp;
    MinStack() {
        tp = -1;
    }
    
    void push(int val) {
        arr.push_back(val);
        tp++;
    }
    
    void pop() {
        int no = arr[arr.size()-1];
        arr.pop_back();
        tp--;
    }
    
    int top() {
        return arr[tp];
    }
    
    int getMin() {
        vector<int>sample = arr;
        sort(sample.begin(),sample.end());
        return sample[0];
    }
};
