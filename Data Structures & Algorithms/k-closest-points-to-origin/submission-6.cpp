class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_map<long long, vector<pair<int, int>>> mp;
        for (auto el : points) {
            int x = el[0];
            int y = el[1];
            long long dist = 1LL * (el[0] * el[0] + el[1] * el[1]);
            cout << dist << x << y << endl;
            pq.push(dist);
            mp[dist].push_back({x, y});
        }
        vector<vector<int>> result;
        while (k) {
            long long minDis = pq.top();

            vector<pair<int, int>>& vcPr = mp[minDis];

            int times = min((int)vcPr.size(), k);
            int dec = times;

            int ind = 0;

            while (times) {
                result.push_back({vcPr[ind].first, vcPr[ind].second});

                ind++;
                times--;
            }

            k -= dec;

            // Remove duplicate distances
            while (!pq.empty() && pq.top() == minDis) pq.pop();
        }
        return result;
    }
};
