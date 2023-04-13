class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> st;
        int pos1 = 0, pos2 = 0, size1 = pushed.size(), size2 = popped.size();
        while(pos1 < size1){
            if(!st.empty()){
                if(st.top() == popped[pos2]){
                    st.pop();
                    pos2++;
                }
                else{
                    st.push(pushed[pos1]);
                    pos1++;
                }
            }
            else{
                st.push(pushed[pos1]);
                pos1++;
            }
        }
        while(!st.empty()){
            if(st.top() != popped[pos2]) return false;
            else{
                st.pop();
                pos2++;
            }
        }
        if(pos2 != size2) return false;
        return true;
    }
};