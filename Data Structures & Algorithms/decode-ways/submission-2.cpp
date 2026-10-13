class Solution {
public:
    int solve(string& s, int ind, int prev,vector<vector<int>>&dp){
        string sub = s.substr(prev+1,ind-prev);
        int num = sub.length()>2 ? 99: stoi(sub);
        if(ind==s.length()-1){
            if(num>0 && num<=26) return 1;
            else return 0;
        } 

        if(dp[prev+1][ind]!=-1) return dp[prev+1][ind];
        // partition
        int part = 0;
        
        if(s[ind+1]!='0' && num>0 && num<=26) part = solve(s,ind+1,ind,dp);

        // no partition
        int noPart = solve(s,ind+1,prev,dp);

        return dp[prev+1][ind] = part+noPart;
    }
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        return solve(s, 0,-1,dp);
    }
};
