class Solution {
public:
    bool isPalindrome(string& s, int i, int j,vector<vector<int>>&dp){
        if(i>=j) return true;

        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = s[i]==s[j] && isPalindrome(s,i+1,j-1,dp);
    }
    string longestPalindrome(string s) {
        int len = s.length();
        int maxLen = 0;
        string maxStr;
        vector<vector<int>>dp(len+1,vector<int>(len+1,-1));
        for(int i = 0;i<len;i++){
            for(int j = i;j<len;j++){
                bool res = isPalindrome(s,i,j,dp);
                if(res){   
                    if(j-i+1>maxLen){
                        string subStr = s.substr(i,j-i+1);
                        maxLen = j-i+1;
                        maxStr = subStr;
                    }
                }
            }
        }
        return maxStr;
    }
};