class Solution {
public:
    void dfs(vector<vector<int>>graph,vector<int>&visited,int ind){
        visited[ind] = 1;

        for(auto el:graph[ind]){
            if(!visited[el]){
                dfs(graph,visited,el);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>visited(n);
        vector<vector<int>>graph(n);
        for(auto el:edges){
            int el1 = el[0];
            int el2 = el[1];
            graph[el1].push_back(el2);
            graph[el2].push_back(el1);
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                res++;
                dfs(graph,visited,i);
            }
        }
        return res;
    }
};
