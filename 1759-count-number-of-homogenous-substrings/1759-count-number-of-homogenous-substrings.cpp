class Solution {
    long long calc(long long n)
    {
        return ((n*(n+1))/2);
    }   
public:
    int countHomogenous(string s)
    {
        long long ans =0, track = 1;
        for(int i =0; i < s.length(); i++)
        {
            if(i < s.length()-1 && s[i] == s[i+1])
            {
                track++;
            }
            else{
                ans += calc(track);
                track = 1;
            }
        }
        int a = ans % 1000000007;
        return a;
    }
};