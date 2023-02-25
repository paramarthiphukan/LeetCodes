class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
int max_profit = INT_MIN;
int leasttillnow = INT_MAX;
for(int i=0;i<prices.size();i++)
{
leasttillnow = min(leasttillnow,prices[i]);
profit = prices[i] - leasttillnow;
max_profit = max(max_profit,profit);
}
return max_profit;
        
    }
};
 