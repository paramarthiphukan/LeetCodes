class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0, ans = INT_MIN;
        for(int i = 0; i < s.size(); i++) {
            (s[i] == '0') ? zeros++ : ones++;
            if(i != s.size()-1) ans = max(ans, zeros - ones);
        }
        return ans + ones;
    }
};