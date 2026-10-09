class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<int> des = points[j];
                vector<int> src = points[i];

                int dis = abs(des[0] - src[0]) + abs(des[1] - src[1]);
                graph[i].push_back({j, dis});
                graph[j].push_back({i, dis});
            }
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        vector<int> visited(n);
        int sum = 0;
        pq.push({0, 0, -1});
        while (!pq.empty()) {
            tuple<int, int, int> t = pq.top();
            pq.pop();
            int dis = get<0>(t);
            int srcNd = get<1>(t);
            int parNd = get<2>(t);

            if (visited[srcNd]) continue;

            visited[srcNd] = 1;
            sum += dis;

            for (auto el : graph[srcNd]) {
                int node = el.first;
                int dis = el.second;
                pq.push({dis, node, srcNd});
            }
        }
        return sum;
    }
};
