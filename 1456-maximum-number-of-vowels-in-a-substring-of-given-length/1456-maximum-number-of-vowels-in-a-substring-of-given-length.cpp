class Solution {
public:
    int maxVowels(string s, int k) {
    int n = s.size();
    int i = 0,j = 0,x = 0,c = 0;
    while(j<n){
        if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
            x++;
        }
        if(j-i+1<k) j++;
        else if(j-i+1==k){
            c = max(c,x);
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                x--;
            }
            i++;
            j++;
        }
    }
    return c;
}
};
