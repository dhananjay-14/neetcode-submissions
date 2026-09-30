class Solution {
public:
    int solve(string txt1, string txt2, int ind1, int ind2,vector<vector<int>>&dp){
        if(ind1<0 || ind2 <0) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int pick = 0;int f2 = 0; int f3 = 0;
        if(txt1[ind1]==txt2[ind2]){
           pick = 1+ solve(txt1,txt2,ind1-1,ind2-1,dp);
        }else{
            f2 = solve(txt1,txt2,ind1-1,ind2,dp);
            f3 = solve(txt1,txt2,ind1,ind2-1,dp);
        }

        return dp[ind1][ind2] = max(pick,max(f2,f3));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        vector<vector<int>>dp(l1,vector<int>(l2,-1));
        return solve(text1,text2,text1.length()-1, text2.length()-1,dp);
    }
};
