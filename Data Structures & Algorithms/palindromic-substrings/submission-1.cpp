class Solution {
public:
    int cntOdd(string& s, int i){
        int u=i; int v = i;
        int count = 0;
        while(u>=0 && v<s.length()){
            if(s[u]==s[v]){
                count++;
                u--;
                v++;
            }else break;
        }
        return count;
    }
    int cntEvn(string& s, int i){
        int u =i; int v = i + 1;
        if(v==s.length())return 0;

        int count = 0;
        while(u>=0 && v<s.length()){
            if(s[u]==s[v]){
                count++;
                u--;
                v++;
            }else{
                break;
            }
        }
        return count;
    }
    int countSubstrings(string s) {
       int result = 0;
       for(int i=0;i<s.length();i++){
          int oddPalindromes = cntOdd(s,i);
          int evenPalindromes = cntEvn(s,i);
          int sum = oddPalindromes+evenPalindromes;
          result+=sum;
       }
       return result;
    }
};
