class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         int length = heights.size();
       stack<pair<int,int>>prev;
       stack<pair<int,int>>next;
       vector<int>prevMin(length);
       vector<int>nextMin(length);

       for(int i = 0;i<length;i++){
          if(!prev.empty()){
            while(!prev.empty() && prev.top().first>=heights[i]){
                prev.pop();
            }
            if(prev.empty()) prevMin[i] = -1;
            else prevMin[i] = prev.top().second;
            prev.push({heights[i],i});
          }else {
            prevMin[i] = -1;
            prev.push({heights[i],i});
            }
       }

       for(int i = length-1;i>=0;i--){
          if(!next.empty()){
            while(!next.empty() && next.top().first>=heights[i]){
                next.pop();
            }
            if(next.empty()) nextMin[i] = length;
            else nextMin[i] = next.top().second;
            next.push({heights[i],i});
          }else {
            nextMin[i] = length;
            next.push({heights[i],i});
          }
       }
        int lar = 0;
       for(int i = 0;i<length;i++){
           int curr = heights[i];
           int prevInd = prevMin[i];
           int nextInd = nextMin[i];
           cout<<"prev ind"<<prevInd<<" next ind"<<nextInd<<endl;
           int area = (nextInd-prevInd-1) * curr;
           lar = max(lar,area);
       }
       return lar;
    }
};
