class Solution 
{
public:
    string intToRoman(int num) 
    {
        string ans;
        int i=0;
        while (num) 
        {
            int x=num%10;
            if (i==0) 
            {
                if (x==4) ans+="VI";
                else if (x==9) ans+="XI";
                else if (x<5) 
                {
                    while (x--) ans+="I";
                }
                else 
                {
                    x-=5;
                    while (x--) ans+="I";
                    ans+="V";
                }
            }
            if (i==1) 
            {
                if (x==4) ans+="LX";
                else if (x==9) ans+="CX";
                else if (x<5)
                {
                    while (x--) ans+="X";
                }
                else 
                {
                    x-=5;
                    while (x--) ans+="X";
                    ans+="L";
                }
            }
            if (i==2)
            {
                if (x==4) ans+="DC";
                else if (x==9) ans+="MC";
                else if (x<5) 
                {
                    while (x--) ans+="C";
                }
                else 
                {
                    x-=5;
                    while (x--) ans+="C";
                    ans+="D";
                }
            }
            if (i==3) while (x--) ans+="M";
            num=num/10;
            i++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
