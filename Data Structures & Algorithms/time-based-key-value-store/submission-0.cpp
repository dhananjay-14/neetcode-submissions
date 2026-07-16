class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
       
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>curr = mp[key];
        int st = 0; int en = curr.size()-1;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(curr[mid].first==timestamp) return curr[mid].second;
            else if((mid==en && curr[mid].first<timestamp) ||(curr[mid].first<timestamp && curr[mid+1].first>timestamp)) return curr[mid].second;
            else if(curr[mid].first<timestamp) st = mid+1;
            else en = mid-1;
        }
        return "";
    }
};
