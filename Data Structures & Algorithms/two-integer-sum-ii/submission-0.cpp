class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size()-1;
        vector<int>result;

        while(low<high){
            int sum = numbers[low]+numbers[high];
            if(sum==target){
                result.push_back(low+1);
                result.push_back(high+1);
                return result;
            }else if(sum>target){
                high--;
            }else{
                low++;
            }
        }
        return result;
    }
};
