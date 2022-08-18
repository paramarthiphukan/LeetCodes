class Solution {
public:
   int hIndex(vector<int>& citations)
   {
        int n = citations.size();
        int low=0,high=n,mid;
        int res;
        
        while(low<=high)
        {
            mid = low+(high-low)/2;
            int ub = lower_bound(citations.begin(),citations.end(),mid) - citations.begin();
            
            if(n-ub >= mid)
            {
                res = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return res;
    }
};