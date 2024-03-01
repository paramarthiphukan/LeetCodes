class Solution {
public:
    string maximumOddBinaryNumber(string s) {

        string ans = "1";
        int cnt=0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '0') ans = '0' + ans;
            else cnt++;
        }cnt--;

        while(cnt--) ans = '1' + ans;

        return ans;
    }
};