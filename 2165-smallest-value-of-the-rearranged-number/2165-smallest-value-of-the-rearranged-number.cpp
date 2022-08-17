class Solution {
public:
    long long smallestNumber(long long num)
    {
        bool flag=num>0;
        num=abs(num);
        if(flag)
        {
            string s=to_string(num);
            sort(s.begin(), s.end());
            int i = 0;
            while (s[i] == '0')
                i++;
            swap(s[0], s[i]);
            num=stoll(s);
        }
        else
        {
            string s=to_string(num);
            sort(s.begin(), s.end(),greater());
            s='-'+s;
            num=stoll(s);
        }
        return num;
    }
};