class Solution {
public:
    int calculate(string s)
    {
        stack<int> number;
        stack<char> sign;
        
        int num = 0, n = s.length(), current = 0;
        char pre = '+';
        
        for(int i=0; i<=n; i++)
        {
            char c;
            
            if(i == n)
                c = '+';
            else
                c = s[i];
            
            if(c == ' ')
                continue;
            
            if( c == '(')
            {
                number.push(current);
                sign.push(pre);
                
                current = 0;
                num = 0;
                
                pre = '+';
                
                continue;
            }
            else if(s[i] == ')')
            {
                if(pre == '+')
                    current += num;
                
                if(pre == '-')
                    current -= num;
                
                if(sign.top() == '-')
                    current = -current;
                
                current += number.top();
                
                num = 0;
                
                sign.pop();
                number.pop();
            }
            else if(s[i] >= '0' and s[i] <= '9')
                num = (num * 10) + (s[i] - '0');
            else
            {
                if(pre == '+')
                    current += num;
                
                if(pre == '-')
                    current -= num;
                
                num = 0;
                pre = s[i];
            }
        }
        
        while(!number.empty())
        {
            current += number.top();
            number.pop();
        }
        return current;
    }
};