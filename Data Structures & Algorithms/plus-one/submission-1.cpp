class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int p = digits.size()-1;
        vector<int>ans;
        long long res = 0;
        for(int i = 0;i<digits.size();i++){
            res += digits[i] * pow(10,p);
            p--;
        }
        res ++;
        while(res){
            int dig = res % 10;
            ans.insert(ans.begin(),dig);
            res = res/10;
        }
        return ans;
    }
};
