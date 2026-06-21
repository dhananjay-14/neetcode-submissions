class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int ans = 1, curr = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1] + 1)
                curr++;
            else
                curr = 1;

            ans = max(ans, curr);
        }

        return ans;
    }
};