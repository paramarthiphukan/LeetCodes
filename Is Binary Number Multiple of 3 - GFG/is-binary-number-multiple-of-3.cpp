//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    int ans=0;
	    int hlp=1;
	    for(int i=s.length()-1;i>-1;i--){
	        
	        hlp=(hlp*2)%3;
	        if((s[i]-'0')==1)
	         ans=(ans+hlp)%3;
	        
	        
	    }
	    
	    
	    return ans==0;
	    //complete the function here
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends