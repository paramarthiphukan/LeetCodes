class Solution {
public:
    string addBinary(string a, string b) 
    {
         int la=a.size();
        int lb=b.size();
        int i=la-1;
        int j=lb-1;
        int carry=0;
        vector<char> res;
        while(i>=0 || j>=0)
        {
            int sum=carry;
            if(i>=0)
            {
                sum+=(a[i]-'0');
                i--;
            }
            if(j>=0)
            {
                sum+=(b[j]-'0');
                j--;
                
            }
            if(sum==0)
            {
                res.push_back('0');
                carry=0;
            }
            else if(sum==1)
            {
                res.push_back('1');
                carry=0;
            }
            else if(sum==2)
            {
                res.push_back('0');
                carry=1;
            }
            else
            {
                res.push_back('1');
                carry =1;
            }
        }
        if(carry>0)
        {
            res.push_back('1');
        }
        reverse(res.begin(),res.end());
        string str(res.begin(),res.end());
        return str;  
    }
};