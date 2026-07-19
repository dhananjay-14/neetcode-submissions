class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>nextMax;
        vector<int>result(temperatures.size());
        for(int i = temperatures.size()-1;i>=0;i--){
            if(nextMax.empty()){
                result[i] = 0;
            }
            else if(temperatures[i]>=nextMax.top().first){
                while(!nextMax.empty() && nextMax.top().first<=temperatures[i]){
                    nextMax.pop();
                }
                if(!nextMax.empty()) result[i] = nextMax.top().second - i;
                else result[i]=0;
            }else if(temperatures[i]<nextMax.top().first){
                result[i] = nextMax.top().second - i;
            }
            nextMax.push({temperatures[i],i});
        }
        return result;
    }
};
