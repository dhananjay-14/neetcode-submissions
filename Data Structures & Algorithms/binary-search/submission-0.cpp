class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int en = nums.size()-1;

        while(st<=en){
            int mid = st + (en-st)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                en--;
            }else{
                st++;
            }
        }
        return -1;
    }
};
