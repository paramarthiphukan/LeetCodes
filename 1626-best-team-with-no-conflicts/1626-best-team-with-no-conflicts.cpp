class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int ans=INT_MIN;
        vector<vector<int>>arr;
        int n=ages.size();
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            arr.push_back({ages[i],scores[i]});
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int mx=INT_MIN;
            for(int j=0;j<i;j++){
                if(arr[j][1]<=arr[i][1]){
                    mx=max(mx,dp[j]+arr[i][1]);
                }
            } 
            dp[i]=max(mx,arr[i][1]);
            ans=max(ans,dp[i]);
        }
        return ans;
        
    }
};