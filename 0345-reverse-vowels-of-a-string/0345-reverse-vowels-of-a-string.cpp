class Solution {
public:
      string reverseVowels(string s)
      {
        stack<char> vowel;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || 
              s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                vowel.push(s[i]);
                s[i]='$';
            }
        }
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='$')
            {
                s[i]=vowel.top();
                vowel.pop();
            }
        }
        return s;
    }
};