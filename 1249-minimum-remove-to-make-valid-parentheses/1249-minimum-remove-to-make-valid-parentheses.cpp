class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            }
            else if(s[i] == ')') {
               if( !st.empty() ) {
                    st.pop();
               }
               else {
                   continue;
               }
            }
            ans.push_back(s[i]);
        }
        int i=ans.size()-1;
        while(!st.empty() && i>=0) {
            if(ans[i] == '(') {
                ans.erase(ans.begin()+i);
                st.pop();
            }
            i--;
        }
        return ans;
    }
};