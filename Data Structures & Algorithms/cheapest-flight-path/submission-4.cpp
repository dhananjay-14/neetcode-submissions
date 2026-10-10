
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq;

        for(auto el : flights) {
            int u = el[0], v = el[1], w = el[2];
            graph[u].push_back({v, w});
        }

        // Minimal change: track distance by node AND flights taken
        vector<vector<int>> dis(n, vector<int>(k + 2, INT_MAX));

        dis[src][0] = 0;
        pq.push({0, {src, 0}});

        while(!pq.empty()) {
            auto el = pq.top();
            pq.pop();

            int initdis = el.first;
            int nd = el.second.first;
            int lev = el.second.second;

            if(initdis > dis[nd][lev]) continue;
            if(lev == k + 1) continue;

            for(auto neigh : graph[nd]) {
                int node = neigh.first;
                int dist = neigh.second;

                if(dis[node][lev + 1] > initdis + dist) {
                    dis[node][lev + 1] = initdis + dist;
                    pq.push({initdis + dist, {node, lev + 1}});
                }
            }
        }

        int ans = INT_MAX;
        for(int lev = 0; lev <= k + 1; lev++) {
            ans = min(ans, dis[dst][lev]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
