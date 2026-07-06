class Solution {
public:
    string minWindow(string s, string t) {
        int st = 0;
        int en = -1;
        unordered_map<char,int>mps;
        unordered_map<char,int>mpt;

        for(auto el:t) mpt[el]++;

        int count = 0;
        int minLen = INT_MAX;
        int startInd;
        
        while(en<int(s.length())){
            if(count<int(t.length())){
                // expand window
                en++;
                char curr = s[en];
                mps[curr]++;
                if(t.contains(curr) && mps[curr]<=mpt[curr]){
                    count++;
                    if(count==t.size()) {
                        minLen = min(minLen,en-st+1);
                        if(minLen==en-st+1) startInd = st;
                    }
                }
            }else{
                //shrink
                char left = s[st];
                mps[left]--;
                st++;
                if(t.contains(left) && mps[left]<mpt[left]){
                    count--;
                }else{
                    minLen = min(minLen,en-st+1);
                    if(minLen==en-st+1) startInd = st;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startInd, minLen);
    }
};
