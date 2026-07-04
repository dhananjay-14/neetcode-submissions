class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>prefixHt(height.size());
        vector<int>postfixHt(height.size());
        int result = 0;
        int maxHt = 0;
        for(int i=0;i<height.size();i++){
            prefixHt[i] = max(maxHt,height[i]);
            if(prefixHt[i]>maxHt)maxHt = prefixHt[i];
        }

        maxHt = 0;
        for(int i = height.size()-1;i>=0;i--){
            postfixHt[i] = max(maxHt,height[i]);
            if(postfixHt[i]>maxHt) maxHt = postfixHt[i];
        }

        for(int i = 1;i<height.size()-1;i++){
            int ht = height[i];
            int prevMax = prefixHt[i-1];
            int postMax = postfixHt[i+1];

            int minHt = min(prevMax,postMax);
            if(minHt < ht) continue;
            int cap = minHt-ht;
            result += cap;
        }
        return result;
    }
};
