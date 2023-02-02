class Solution {
public:
    
    unordered_map<char, int> mp;
    
    bool cmp(string a, string b){
        if(a == b) return true;
        int i=0;
        while(a[i] == b[i]) i++;
        return mp[a[i]] < mp[b[i]];
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i < order.size(); i++) mp[order[i]] = i;
        int i=1; 
        while(i<words.size() && cmp(words[i-1],words[i])) i++;
        return i<words.size()?false:true;
    }
};