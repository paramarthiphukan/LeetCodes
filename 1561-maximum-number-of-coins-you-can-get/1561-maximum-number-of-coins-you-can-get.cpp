class Solution {
public:
    int maxCoins(vector<int>& piles)
    {
      sort(piles.begin() , piles.end());
      int n  = piles.size();
      int total_coins = n/3;  // Number of coins can be picked by each 
      int j = n-2;
      int ans = 0;
      while(total_coins--)
      {
        ans += piles[j];
        j = j-2;
      }
      return ans;
    }
};