class Solution {
public:
     int minimumDeviation(vector<int>& nums) {
        set <int> st;
        for(auto i: nums){
            st.insert(i % 2 ? i*2 : i);
        }
        int res = *st.rbegin() - * st.begin();
        while(*st.rbegin() % 2 == 0){
            st.insert(*st.rbegin() / 2);
            st.erase(*st.rbegin());
            res = min(res ,*st.rbegin() - *st.begin());
        }
        return res;
    }
}; 