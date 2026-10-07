class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // construct graph
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto el:times){
            int src = el[0];
            int des = el[1];
            int dis = el[2];

            graph[src].push_back({des,dis});
        }

        vector<int>minDis(n+1,INT_MAX);
        minDis[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            pair<int,int>pr = pq.top();
            pq.pop();
            int dis = pr.first;
            int node = pr.second;

            for(auto neigh:graph[node]){
                int nd = neigh.first;
                int d2 = neigh.second;

                if(dis + d2 < minDis[nd]){ 
                    minDis[nd] = dis+d2;
                    pq.push({dis+d2,nd});
                } 
            }
        }
        int maxDis = INT_MIN;
        for(int i = 1;i<n+1;i++){
            if(minDis[i]==INT_MAX) return -1;
            maxDis = max(maxDis,minDis[i]);
        }
        return maxDis;
    }
};
