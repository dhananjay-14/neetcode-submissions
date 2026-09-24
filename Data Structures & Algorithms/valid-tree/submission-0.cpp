class Solution {
public:
    bool solve(vector<vector<int>>&graph,vector<int>&visited,int node,int prev){
        visited[node] = 1;

        for(auto neigh : graph[node]){
            if(neigh!=prev){
                if(!visited[neigh]){
                    bool res = solve(graph,visited,neigh,node);
                    if(res) return true;
                } 
                else return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<int>visited(n);
        for(auto el:edges){
            int f = el[0];
            int s = el[1];
            graph[f].push_back(s);
            graph[s].push_back(f);
        }

        bool res = solve(graph,visited,0,-1);
        if(res) return false;

        for(int i = 0;i<n;i++){
            if(!visited[i]){
                return false;
            }   
        }
        return true;
    }
};
