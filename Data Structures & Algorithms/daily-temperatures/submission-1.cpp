class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int>result(len);
        stack<pair<int,int>>st;
        for(int i = len-1;i>=0;i--){
            while(!st.empty() && temperatures[i]>=st.top().first){
                st.pop();
            }
            if(st.empty()) result[i] = 0;
            else{
                int ind = st.top().second;
                result[i] = ind - i;
            }

            st.push({temperatures[i],i});

        }
        return result;
    }
};
