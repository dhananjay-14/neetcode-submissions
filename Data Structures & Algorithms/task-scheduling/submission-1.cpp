class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        priority_queue<pair<int,char>>pq;
        int count=0;
        for(auto el:tasks)freq[el]++;
        for(auto el:freq){
            pair<int,int>pr = {el.second,el.first};
            pq.push(pr);
        }

        while(!pq.empty()){
            int size = pq.size();
            int elRemove = n+1;
            if(size<n+1) elRemove = size;
            vector<pair<int,char>>temp;
            while(elRemove){
                pair<int,char>pr = pq.top();
                pr.first--;
                temp.push_back(pr);
                pq.pop();
                elRemove--;
            }
            int elAddedBack = 0;
            for(auto it:temp){
                if(it.first>0) {
                    pq.push(it);
                    elAddedBack++;
                }
            }
            int tempSiz = temp.size();
            if(elAddedBack) count+= n+1;
            else count+=tempSiz;
        }
        return count;
    }
};
