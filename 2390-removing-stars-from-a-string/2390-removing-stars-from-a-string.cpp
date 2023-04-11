class Solution {
public:
  string removeStars(string S) 
  {
      stack <int> s1;
         string str=""; 
         
        
         for(int i = 0; i < S.size(); i++)
         {  
                 
                 if(S[i] == '*' && !s1.empty()) 
                         s1.pop();
                 
                 else if(S[i] != '*')  
                         s1.push(S[i]);
                 
         }
        
         while(!s1.empty())
         {
                
                 str.push_back(s1.top());
                 s1.pop(); 
                 
         }
      
      int i = 0, j = str.size() - 1;
	while (i < j) swap(str[i++], str[j--]);   
        
        
        return str;  
    }
};
