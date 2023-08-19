//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        if(s==0L)
        {
            return {-1};
        }
        vector<int>v;
        int i=0;
        int j=1;
        long long sum=0;
        sum=arr[i]+arr[j];
        while(i<n && j<n)
        {
            if(arr[i]==s)
            {
                return {i+1,i+1};
            }
            if(sum==s)
            {
                v.push_back(i+1);
                 v.push_back(j+1);
                 return v;
            }
            if(sum<s)
            {
                j++;
                sum+=arr[j];
            }
            else
            {
                sum-=arr[i];
                i++;
                 if(sum==s)
            {
                v.push_back(i+1);
                 v.push_back(j+1);
                 return v;
            }
                
            }
        }
        v.push_back(-1);
        return v;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends