class Solution {
public:
    bool solve(vector<vector<int>>& graph,
               vector<int>& visited,
               vector<int>& pathVisited,
               int num) {

        visited[num] = 1;
        pathVisited[num] = 1;

        for (auto el : graph[num]) {

            if (!visited[el]) {
                if (solve(graph, visited, pathVisited, el))
                    return true;
            }
            else if (pathVisited[el]) {
                return true;  // cycle
            }
        }

        pathVisited[num] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        for (auto el : prerequisites) {
            int nxt = el[0];
            int fst = el[1];

            graph[fst].push_back(nxt);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (solve(graph, visited, pathVisited, i))
                    return false;
            }
        }

        return true;
    }
};