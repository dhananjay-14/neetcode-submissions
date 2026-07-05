class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int l = 0;
        int r = 0;
        unordered_map<char,int>position;
        while(r<s.length()){
            position[s[r]]= r;
            int len = r - l + 1;
            result = max(result, len);
            r++;
            if(r==s.length())break;

            if(position.contains(s[r]) && position[s[r]]>=l){
                // exist
                l = position[s[r]]+1;
            }
        }
        return result;
    }
};
