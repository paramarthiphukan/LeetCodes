class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        string s;
        string s2;
         for(auto &i: word1)
           {
         s+=i;
      }
          for(auto &i: word2) 
          {
           s2+=i;
          }
             return s == s2;
      }
};
    