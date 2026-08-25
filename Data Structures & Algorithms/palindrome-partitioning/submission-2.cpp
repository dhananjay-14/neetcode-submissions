class Solution {
public:
    unordered_map<string, bool> mp;

    bool isPalindrome(string s) {
        int len = s.length();
        for(int i = 0; i < len / 2; i++) {
            if(s[i] != s[len - 1 - i]) return false;
        }
        return true;
    }

    void solve(int ind, string s, vector<int> curr,
               vector<vector<string>>& res, int start) {

        if(ind == s.length() - 1) {
            string temp = s.substr(start);

            bool palval;
            if(mp.find(temp) != mp.end())
                palval = mp[temp];
            else {
                palval = isPalindrome(temp);
                mp[temp] = palval;
            }

            if(!palval) return;

            vector<string> val;

            int prev = 0;
            for(int pos : curr) {
                val.push_back(s.substr(prev, pos - prev + 1));
                prev = pos + 1;
            }

            val.push_back(temp);
            res.push_back(val);
            return;
        }

        // Don't split after ind
        solve(ind + 1, s, curr, res, start);

        // Split after ind
        string temp = s.substr(start, ind - start + 1);

        bool palval;
        if(mp.find(temp) != mp.end())
            palval = mp[temp];
        else {
            palval = isPalindrome(temp);
            mp[temp] = palval;
        }

        // Only continue if current partition is valid
        if(palval) {
            curr.push_back(ind);
            solve(ind + 1, s, curr, res, ind + 1);
            curr.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<int> curr;

        solve(0, s, curr, result, 0);

        return result;
    }
};