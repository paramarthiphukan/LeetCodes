class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";

        stack<char> st;

        for (char ch : s){
            if (ch != ')'){
                st.push(ch);
            }
            else{
                string w = "";
                while (st.top() != '('){
                    w += st.top();
                    st.pop();
                }
                st.pop();

                for (char i : w)
                    st.push(i);
            }
        } 

        while (!st.empty()){
            ans = st.top() + ans;
            st.pop();
        } 

        return ans;
    }
};