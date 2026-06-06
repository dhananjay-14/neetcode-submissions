class Solution {
public:
    bool isAnagram(string s, string t) {
        // check the length of strings to be equal, if not throw
        if(s.length() != t.length()) return false;

        map<char,int>mp1;
        map<char,int>mp2;
        // count the frequency of each character
        for(int i = 0;i<s.length();i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }

        // compare and match; if any one does not match, throw
        for(int i = 0;i<s.length();i++){
            char c = char(s[i]);
            if(mp1[c] != mp2[c]) return false;
        }

        return true;
    }
};
