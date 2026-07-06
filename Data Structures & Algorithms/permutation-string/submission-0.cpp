class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();

        if(l1>l2) return false;

        int st = 0;
        int en = 0 + l1 - 1;
        string str1 = s1;
        sort(str1.begin(),str1.end());
        while(en<l2){
            string str2 = s2.substr(st,l1);
            sort(str2.begin(),str2.end());
            if(str1 == str2){
                return true;
            }else{
                st++;
                en++;
            }
        }
        return false;
    }
};
