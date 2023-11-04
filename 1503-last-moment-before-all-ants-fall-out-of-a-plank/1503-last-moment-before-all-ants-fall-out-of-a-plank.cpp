class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int lastMoment = 0;

        for(auto x : left) 
            lastMoment = max(lastMoment,x);
        
        for(auto x : right)
            lastMoment = max(lastMoment,n - x);
        
        return lastMoment;
    }
};