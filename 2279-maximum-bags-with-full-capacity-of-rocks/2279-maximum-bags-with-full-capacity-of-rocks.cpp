class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
       long long n =rocks.size(),sumc=0;
       for(int i=0;i<n;i++)
           rocks[i]=capacity[i]-rocks[i];

       long long sum=0,ans=0;
       sort(rocks.begin(),rocks.end());
       for(int i=0;i<n;i++)
       {
           sum+=rocks[i];
           if(sum > additionalRocks) break;
           else ans++;
       }
       return ans;
    }
};