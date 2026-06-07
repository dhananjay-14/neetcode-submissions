class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedStr="";
        for(auto el:strs){
            string len = to_string(el.length());
            encodedStr += (len+'#'+el);
        }
        return encodedStr;
    }

    vector<string> decode(string s) {
        vector<string>result;
        int check = 0;
        int i=0;
        while(i<s.length()){
           if(s[i]=='#'){
             int len = stoi(s.substr(check,i-check));
             string str = "";
             for(int j=i+1;j<(i+1+len);j++){
                str+=s[j];
             }
             result.push_back(str);
             i = i + 1 + len;
             check = i;
           } else {
             i++;
           }
        }
        return result;
    }
};
