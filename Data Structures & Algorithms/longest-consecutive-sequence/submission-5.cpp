class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int result = 0;
        for(auto el:nums){
            int count = 0;
            int curr = el;
            if(st.find(curr-1)==st.end()){
                //start of seq
                count++;
                while(st.find(curr+1)!=st.end()){
                    count++;
                    curr++;
                }
            }
            result = max(result,count);
        }
        return result;
    }
};