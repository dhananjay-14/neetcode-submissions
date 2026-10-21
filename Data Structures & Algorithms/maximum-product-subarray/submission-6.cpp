class Solution {
public:
    int maxProductWithoutZero(vector<int>& nums){
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==0) return 0;
        vector<int>prefixProduct(n);
        vector<int>postfixProduct(n);

        int num = 1;
        int negInt = 0;
        vector<int>negInd;
        for(int i = 0;i<n;i++){
            if(nums[i]<0) {
                negInt++;
                negInd.push_back(i);
            }
            num = num * nums[i];
            prefixProduct[i] = num;
        }
        if(negInt % 2 == 0) return num;

        num = 1;
        for(int i=n-1;i>=0;i--){
            num = num * nums[i];
            postfixProduct[i] = num;
        }

        int maxProduct = INT_MIN;
        for(auto el:negInd){
            int left = INT_MIN; int right = INT_MIN;
            if(el>0) left = prefixProduct[el-1];
            if(el<n-1) right = postfixProduct[el+1];
            int maxEl = max(left,right);
            maxProduct = max(maxProduct,maxEl);
        }
        return maxProduct;
    }
    int maxProduct(vector<int>& nums) {
        vector<int>zeroInd;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0) zeroInd.push_back(i);
        }

        if(zeroInd.size()==0) return maxProductWithoutZero(nums);

        int maxEl = 0;

        vector<int>temp;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }else{
                maxEl = max(maxEl,maxProductWithoutZero(temp));
                temp = {};
            }
        }

        maxEl = max(maxEl, maxProductWithoutZero(temp));
        return maxEl;
    }
};
