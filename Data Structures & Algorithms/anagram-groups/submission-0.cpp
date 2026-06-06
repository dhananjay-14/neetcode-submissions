class Solution {
public:
    bool isAnagram(string s1, string s2){
        if(s1.length()!=s2.length()) return false;

        map<int,int>mp;
        for(auto el:s1){
            mp[el]++;
        }
        for(auto el:s2){
            mp[el]--;
        }
        for(auto el:mp){
            if(el.second !=0) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<int,int>marked;
        vector<vector<string>>result;
        for(int i = 0;i<strs.size();i++){
            if(marked[i]==1) continue;
            string curr = strs[i];
            vector<string>currGrp;
            currGrp.push_back(curr);
            marked[i]=1;
            for(int j= i+1;j<strs.size();j++){
                bool anagram = isAnagram(strs[i],strs[j]);
                if(anagram) {
                    currGrp.push_back(strs[j]);
                    marked[j]=1;
                }
            }
            result.push_back(currGrp);
        }
        return result;
    }
};
