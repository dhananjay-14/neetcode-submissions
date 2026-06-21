class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>preFixProduct;
        vector<int>postFixProduct;
        int num = 1;
        for(auto el:nums){
            num = num * el;
            preFixProduct.push_back(num);
        }
        num = 1;
        for(int i = nums.size()-1;i>=0;i--){
            num = num * nums[i];
            postFixProduct.insert(postFixProduct.begin(),num);
        }

        vector<int>result;
        for(int i = 0;i<nums.size();i++){
            if(i==0) result.push_back(postFixProduct[i+1]);
            else if(i==nums.size()-1) result.push_back(preFixProduct[i-1]);
            else result.push_back(preFixProduct[i-1]*postFixProduct[i+1]);
        }
        return result;
    }
};