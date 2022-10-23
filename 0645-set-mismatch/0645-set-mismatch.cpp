class Solution {
public:
     vector<int> findErrorNums(vector<int>& nums) 
     {
        
        unordered_map<int,int>m;
        
        vector<int>results;
        
        int temp=0;
        
        for(auto x : nums)
        {
            
            if(m.find(x)!=m.end())
            {
                
                temp=x;
            }
            
            m[x]++;
        }
        
        results.push_back(temp);
        
        for(int i=1;i<=nums.size();i++)
        {
            
            if(m.find(i)==m.end())
            {
                
                results.push_back(i);
                
                break;
            }
        }
        
        return results;
        
    }
};