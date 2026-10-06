class DSU{
    vector<int>parent;
    vector<int>rank;

    public: DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i){
        if(parent[i]==i) return i;

        return parent[i] = find(parent[i]);
    }

    void Union(int i, int j){
        int parI = find(i);
        int parJ = find(j);

        if(parI==parJ) return;

        if(rank[parI]>rank[parJ]){
            parent[parJ] = parI;
        }else if(rank[parI]<rank[parJ]){
            parent[parI] = parJ;
        }else{
            parent[parI] = parJ;
            rank[parJ]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       DSU* dsu = new DSU(edges.size()+1);
       for(auto ed:edges){
          int u = ed[0];
          int v = ed[1];

          int parU = dsu->find(u);
          int parV = dsu->find(v);

          if(parU==parV){
            return ed;
          }else{
            dsu->Union(u,v);
          }
       }
       return {};
    }
};
