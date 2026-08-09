class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        
        do{
            int nextPtrSlow = nums[slow];
            int nextPtrFast = nums[nums[fast]];

            slow = nextPtrSlow;
            fast = nextPtrFast;
        }while(slow!=fast);

        slow = 0;

        while(slow!=fast){
            int nextSlowPtr = nums[slow];
            int nextPtrFast = nums[fast];

            slow = nextSlowPtr;
            fast = nextPtrFast;
        }

        return slow;
    }
};
