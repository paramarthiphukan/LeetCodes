class Solution {
public:
      int solve(vector<int>& days, int index, vector<int>& costs, vector<int>& dp){
        if(index == days.size()) return 0;
        if(dp[index] != -1) return dp[index];    //return the value if it was already calculated
        
        int sum = 0;
        int base = days[index];
        sum = costs[0] + solve(days, index+1, costs, dp);    //first find the sum for 1 day tickets
        auto i = upper_bound(days.begin(), days.end(), base + 7-1);
        sum = min(sum, costs[1] + solve(days, i - days.begin(), costs, dp));  //sum for 7 day tickets. since the array is sorted, i used binary search to find the required index
        auto j = upper_bound(days.begin(), days.end(), base + 30-1);  //find sum for 30 day ticket
        sum = min(sum, costs[2] + solve(days, j - days.begin(), costs, dp));
        return dp[index] = sum;   //store the value in dp and return it.
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int d = days.size();
        vector<int> dp(d, -1);   //dp[i] stores the minimum cost to cover all days from i(inclusive) to n-1.
        int cost = solve(days, 0, costs, dp);
        return cost;
    }
};