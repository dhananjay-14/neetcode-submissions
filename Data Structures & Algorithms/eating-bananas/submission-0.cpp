class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxEl = INT_MIN;
        for(auto el:piles){
            maxEl = max(maxEl,el);
        }

        if(h==piles.size()) return maxEl;

        int st = 1;
        int en = maxEl;
        int minSpeed = INT_MAX;

        while(st<=en){
            int mid = st + (en-st)/2;
            int count = 0;
            for(auto el:piles){
                if(el%mid==0){
                   count += el/mid; 
                }else{
                    count += el/mid + 1;
                }
            }
            if(count>h){
                st = mid+1;
            }else{
                minSpeed = min(minSpeed,mid);
                en = mid-1;
            }
        }
        return minSpeed;
    }
};
