class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int>mp;
        stack<int>st;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        int counter = 0;
        for(auto el:s){
            if(mp.contains(el)){
                st.push(el);
                counter++;
            }else{
                if(st.empty()) return false;
                char lst = st.top();
                if(mp[lst]!=el){
                    return false;
                }else{
                    st.pop();
                    counter--;
                }
            }
        }
        if(counter==0)return true;
        return false;
    }
};
