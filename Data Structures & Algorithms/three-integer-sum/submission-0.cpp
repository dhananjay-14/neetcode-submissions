class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int>lst = nums;
        set<tuple<int,int,int>>stp;
        sort(lst.begin(),lst.end());

        for(int i = 0;i<lst.size();i++){
            int target = 0-lst[i];
            int st = i+1;
            int en = lst.size()-1;
            while(st<en){
                if(lst[st]+lst[en]==target){
                    tuple<int,int,int> tp = {lst[i],lst[st],lst[en]};
                    stp.insert(tp);
                    st++;
                    en--;
                }else if(lst[st]+lst[en]<target){
                    st++;
                }else{
                    en--;
                }
            }
        }

        vector<vector<int>>result;
        for(auto el:stp){
            int el1 = get<0>(el);
            int el2 = get<1>(el);
            int el3 = get<2>(el);
            vector<int>finalEl = {el1,el2,el3};
            result.push_back(finalEl);
        }
        return result;
    }
};
