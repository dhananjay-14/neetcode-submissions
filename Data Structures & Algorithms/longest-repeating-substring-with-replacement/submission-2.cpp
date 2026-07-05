class Solution {
   public:
    bool verifyCondition(string s, int k, int maxFreq) { return s.length() - maxFreq <= k; }
    int cal(unordered_map<char, int> mp) {
        int res = 0;
        for (auto el : mp) {
            res = max(res, el.second);
        }
        return res;
    }
    int characterReplacement(string s, int k) {
        if (s.length() == 0) return 0;
        int result = 0;
        int st = 0;
        int en = 0;
        int maxFreq = 0;
        unordered_map<char, int> mp;
        while (en < s.length()) {
            int len = en - st + 1;
            mp[s[en]]++;
            maxFreq = max(maxFreq, mp[s[en]]);
            string str = s.substr(st, len);
            while (!verifyCondition(s.substr(st, en - st + 1), k, maxFreq)) {
                mp[s[st]]--;
                st++;
                // maxFreq = cal(mp);
            }

            result = max(result, en - st + 1);
            en++;
        }
        return result;
    }
};
