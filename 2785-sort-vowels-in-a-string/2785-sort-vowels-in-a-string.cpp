class Solution {
public:
    string sortVowels(string s) {
        int n=s.length();
        vector<char> help;
        for(int i=0;i<n;i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            help.push_back(s[i]);
        }
        sort(help.begin(), help.end());
        int x=0;
        for(int i=0;i<n;i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                swap(s[i],help[x]);
                x++;
            }
        }
        return s;
    }
};