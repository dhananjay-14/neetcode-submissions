class Solution {
public:
    bool isAlphaNumeric(char ch){
        if(isalpha(ch) || (isdigit(ch) && ch-'0'>=0 && ch-'0'<=9)) return true;
        return false;
    }
    bool isPalindrome(string s) {
        string newStr = "";
        for(auto ch:s){
            if(isAlphaNumeric(ch)) newStr += ch;
        }
        int len = newStr.length()/2;
        for(int i = 0 ;i<len;i++){
            if(tolower(newStr[i])!=tolower(newStr[newStr.length()-i-1])) return false;
        }
        return true;
    }
};
