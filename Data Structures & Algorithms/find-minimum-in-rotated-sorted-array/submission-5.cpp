class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size()==1) return nums[0];
        int st = 0;
        int en = nums.size()-1;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(mid != 0 && nums[mid-1]>nums[mid]) return nums[mid];
            if(mid != nums.size()-1 && nums[mid+1]<nums[mid]) return nums[mid+1];
            else if(nums[mid]<nums[0]){
                // to left
                en = mid-1;
            }else if(nums[mid]>nums[0]){
                // to right 
                st = mid + 1;
            }
            else if(mid==0) return nums[mid];
        }
        return nums[1]>nums[0]? nums[0]: nums[nums.size()-1];
    }
};
