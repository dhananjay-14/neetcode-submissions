class Solution {
public:
    bool dfs(vector<vector<int>>&graph,vector<int>&visited,int node,int prevNode){
        visited[node] = 1;

        for(auto neig:graph[node]){
            if(neig!=prevNode && visited[neig]) return true;
            if(!visited[neig]){
                bool res = dfs(graph,visited,neig,node);
                if(res) return true;
            } 
        }
        return false;
    }
    bool checkCycle(vector<vector<int>>&graph){
        int nodes = graph.size();
        vector<int>visited(nodes);
        for(int i = 1;i<nodes;i++){
            if(!visited[i]){
                bool res = dfs(graph,visited,i,-1);
                if(res) return true;
            }
        }
          
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodes = edges.size();
        vector<vector<int>>graph(nodes+1);
        for(auto el:edges){
            int src = el[0];
            int dest = el[1];
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }

        for(int i=nodes-1;i>=0;i--){
            vector<int>edge = edges[i];
            int src = edge[0];
            int des = edge[1];

            vector<int>neigSrc = graph[src];
            vector<int>neigDes = graph[des];

            int srcInd = -1; int disInd = -1;
            for(int i = 0;i<neigSrc.size();i++) if(neigSrc[i]==des) srcInd = i;
            for(int i = 0;i<neigDes.size();i++) if(neigDes[i]==src) disInd = i;

            graph[src].erase(graph[src].begin()+srcInd);
            graph[des].erase(graph[des].begin()+disInd);

            bool res = checkCycle(graph);
            if(!res) return edge;

            graph[src].push_back(des);
            graph[des].push_back(src);
        }

        return vector<int>();
    }
};
