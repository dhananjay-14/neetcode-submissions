class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string str = "+-*/";
        stack<int>st;
        int ans=0;
        for(auto el:tokens){
           if(str.contains(el)){
              int no1 = st.top();
              st.pop();
              int no2 = st.top();
              st.pop();
              if(el=="+")ans = no1 + no2;
              if(el=="-")ans = no2-no1;
              if(el=="*")ans = no1 * no2;
              if(el=="/" && no1!=0)ans = no2 / no1;
              st.push(ans);
           }else{
                int no = stoi(el);
                st.push(no);
                ans = no;
            }
        }
        return ans;
    }
};
