class StockSpanner {
public:
     stack<pair<int, int>> s;
    int i=0;
 
    int next(int price) 
    {
       if(s.empty())
       {
           s.push({price, i++});
           return 1;
       }
        else
        {
            
            // now our stack is not empty so we can eleminate smaller element
            
            while(!s.empty() && s.top().first <= price )
            {
                s.pop();
            }
            int ans;
            
            // if our stack is empty so
            if(s.empty()) ans = i+1; // case for 105 in [100, 80, 70, 60, 105]
            else
            {
                ans = i- s.top().second;
            }
            s.push({price, i++});
            return ans;
        }
    
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */