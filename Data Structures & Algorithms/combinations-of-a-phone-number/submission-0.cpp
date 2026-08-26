class Solution {
public:
    unordered_map<char,string>charMap;
    void init(){
    charMap['2'] = "abc";
    charMap['3'] = "def";
    charMap['4'] = "ghi";
    charMap['5'] = "jkl";
    charMap['6'] = "mno";
    charMap['7'] = "pqrs";
    charMap['8'] = "tuv";
    charMap['9'] = "wxyz";
    }

    void solve(string& digits,int ind, string curr,vector<string>&res){
        if(ind==digits.length()){
            res.push_back(curr);
            return;
        }
        string chars = charMap[digits[ind]];
        for(auto el:chars){
            string tempCurr = curr+el;
            solve(digits,ind+1,tempCurr,res);
        }
    }
    vector<string> letterCombinations(string digits) {
       vector<string>res;
       if(digits.length()==0) return res;
       init();
       solve(digits,0,"",res);
       return res;
    }
};
