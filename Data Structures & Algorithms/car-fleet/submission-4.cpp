class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<float,int>>times(speed.size());
        set<float>st;
        for(int i = 0;i<position.size();i++){
            int dis = target - position[i];
            int spd = speed[i];
            float time = float(dis)/float(spd);
            times[i] = {time,position[i]};
        }
        sort(times.begin(),times.end(),[](pair<float,int> a, pair<float,int> b){
            return a.second < b.second;
        });
        int count = 0;
        float prevMax = INT_MIN;
        for(int i = times.size()-1;i>=0;i--){
            if(times[i].first>prevMax){
                count++;
            }
            prevMax = max(prevMax,times[i].first);
        }
        return count;
    }
};
