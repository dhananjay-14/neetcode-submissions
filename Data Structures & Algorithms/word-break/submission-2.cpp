class Solution {
public:
    bool solve(string s,int st, int len, vector<string>& wordDict,vector<int>&dp){
        string str = "";
        if(dp[st]!=-1)return dp[st];
        bool res = false;
        for(int i =st;i<len;i++){
            str += s[i];
            for(auto el:wordDict){
                if(el==str){
                    if(i==s.length()-1) return true;
                    res = res || solve(s,i+1,s.length(),wordDict,dp);
                }
            }
        }
        return dp[st] = res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length(),-1);
        return solve(s,0,s.length(),wordDict,dp);
    }
};
