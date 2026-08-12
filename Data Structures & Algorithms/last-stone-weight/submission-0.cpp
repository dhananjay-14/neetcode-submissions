class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>lar;
        for(auto el:stones) lar.push(el);

        while(lar.size()>=2){
            int f = lar.top();
            lar.pop();
            int s = lar.top();
            lar.pop();
            if(s!=f) lar.push(abs(f-s));
        }

        if(lar.empty()) return 0;
        else return lar.top();
    }
};
