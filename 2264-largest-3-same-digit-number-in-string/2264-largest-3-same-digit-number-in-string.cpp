class Solution {
public:
    // time/space: O(n)/O(1)
    string largestGoodInteger(string num) {
        int n = num.size();
        string result = "";
        for (int i = 0; i < n; i++) {
            if (!isGood(num, i)) continue;
            if ((result == "") || (num[i] > result[0])) result = num.substr(i, 3);\
        }
        return result;
    }
private:
    bool isGood(const string& num, int i) {
        // base case
        if ((i + 2) >= num.size()) return false;

        // check the substring consists of only one unique digit
        return ((num[i] == num[i + 1]) && (num[i] == num[i + 2]));
    }
};