class Solution {
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        if(k >= n)return "0";
        stack<char> stk; 
        stk.push(num[0]);
        int i = 1; 
        while(i < n)
        {
	    
            while(!stk.empty() && stk.top() > num[i] && k > 0){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
            i++;
        }
        while(k--){
            stk.pop();
        }
        
        string ans = "";
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        int ind = -1; 
        for(int i = 0; i < ans.size(); ++i){
            if(ans[i] != '0'){
                ind = i; 
                break; 
            }
        }
        if(ind == -1)return "0";
        return ans.substr(ind, ans.size() - ind); 
    }
};