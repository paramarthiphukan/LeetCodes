class Solution {
public:
    int minimumOneBitOperations(int n) {
        int curr_index = 1;
        int res = 0;
        while (n > 0) {
            if (n % 2 == 1) res = pow(2, curr_index) - res - 1;
            curr_index += 1;
            n /= 2;
        }
        return res;
    }
};