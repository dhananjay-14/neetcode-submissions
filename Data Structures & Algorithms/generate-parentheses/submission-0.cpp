class Solution {
public:
    int initLen;
    void solve(string curr,int open,int close,vector<string>&res){
        if(curr.length()==(2*initLen)){
            res.push_back(curr);
            return;
        } 

        // open
        if(open>0){
            string newCurr = curr+"(";
            open--;
            solve(newCurr,open,close,res);
            open++;
        }

        //close
        if(open<close){
            string closeCurr = curr+")";
            close--;
            solve(closeCurr,open,close,res);
        }
    }
    vector<string> generateParenthesis(int n) {
        initLen = n;
        vector<string>result;
        string curr = "";
        solve(curr,n,n,result);
        return result;
    }
};
