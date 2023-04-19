//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) 
    {
        // code here
         int n = arr.size();
        
        int ptr = 0;
        
        for(int i=1; i<n; i++){
            if(ptr < 0){
                ptr++;
                arr[ptr] = arr[i];
                continue;
            }
                
            else if((arr[i] >= 0 && arr[ptr] < 0) || (arr[i] < 0 && arr[ptr] >= 0))
            {
                ptr--;
            }
            else
            {
                ptr++;
                arr[ptr] = arr[i];
            }
        }
        arr.erase(arr.begin()+ptr+1, arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends