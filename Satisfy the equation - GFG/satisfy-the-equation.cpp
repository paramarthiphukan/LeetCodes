//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
vector<int> satisfyEqn(int input[], int N)
{
	int n=N;
	int a=-1;
	int b=-1;int c=-1;
	int d=-1;

	vector<int>ans;

	vector<vector<int> >v;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			vector<int>vec;
			vec.push_back(i);
			vec.push_back(j);
			vec.push_back(input[i]+input[j]);
			v.push_back(vec);
		}
	}
	for(int i=0;i<v.size();i++)
	{
		for(int j=i+1;j<v.size();j++)
		{
			if(v[i][2]==v[j][2])
			{
				a=v[i][0];
				b=v[i][1];
				c=v[j][0];
				d=v[j][1];
				if(a!=c && a!=d && b!=c && b!=d)
				{
				goto end;
				    
				}
			}
		}
	}
	end:
	ans.push_back(a);
	ans.push_back(b);
	ans.push_back(c);
	ans.push_back(d);
	return ans;
}
  };

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends