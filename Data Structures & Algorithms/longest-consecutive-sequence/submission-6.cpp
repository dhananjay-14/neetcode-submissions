class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());

        int result = 0;
        for(auto el:st){
            if(st.contains(el-1)){
                continue;
            }else{
                int curr =el;
                int count = 0;
                while(st.contains(curr)){
                    count++;
                    curr +=1;
                }
                result = max(result,count);
            }
        }
        return result;
    }
};