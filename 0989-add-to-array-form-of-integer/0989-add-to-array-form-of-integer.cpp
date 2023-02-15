class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        vector<int> ans;
        int i = num.size()-1, c = 0;
        for( ; i >= 0; i--)
        {
            int temp = c+k%10+num[i];
            ans.push_back(temp%10);
            k /= 10;
            c = temp > 9 ? 1 : 0;
        }
        while(k>0)
        {
            int temp = c+k%10;
            ans.push_back(temp%10);
            k /= 10;
            c = temp > 9 ? 1 : 0;
        }
        if(c==1)    ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};