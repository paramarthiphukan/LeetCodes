class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long ans = 0;
        sort(hap.begin(), hap.end(), greater<int>());
        int n = hap.size();
        for(int i = 0; i < n; i++) {
            if(hap[i] <= i) break;
            if(k == 0) break;
            ans += hap[i] - i;
            k--;
        }
        return ans;
    }
};