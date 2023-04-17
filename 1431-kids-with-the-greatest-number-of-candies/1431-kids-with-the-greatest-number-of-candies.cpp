class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int n = candies.size();
        int max = 0;
        for(int i = 0;i<n;i++){
            if(candies[i]>max) max = candies[i];
        }
        for(int j = 0; j<n; j++){
            if((candies[j] + extraCandies) >= max) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};