class Solution {
public:
    long long diff = INT_MAX, nLong;
    string result;
    void update(const string& curr) {
        long long temp = stoll(curr);
        if (temp != nLong && diff > abs(temp - nLong)) {
            result = curr;
            diff = abs(temp - nLong);
        }
    };
    string nearestPalindromic(string n) {
        int len = n.length();
        if (len == 1)
            return to_string(n[0] - '0' - 1);
        nLong = stoll(n);
        update("1" + string(len - 1, '0') + "1");
        update(string(len - 1, '9'));
        int firstHalf = stoi(n.substr(0, (len + 1) / 2));
        for (int i = -1; i <= 1; i++) {
            string prefix = to_string(firstHalf + i);
            update(prefix + string(prefix.rbegin() + (len & 1), prefix.rend()));
        }
        return result;
    }
};