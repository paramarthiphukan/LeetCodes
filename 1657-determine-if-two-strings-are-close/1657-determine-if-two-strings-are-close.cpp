class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<int, int> arr1, arr2;
        set<char> w1,w2;
        if(word1.size()!=word2.size()){
            return false;
        }
        for(auto x:word1){
            arr1[x]++;
            w1.insert(x);
        }
        for(auto x:word2){
            arr2[x]++;
            w2.insert(x);
        }
        vector<int> a1,a2;
        for(auto x:arr1){
            a1.push_back(x.second);
        }
        for(auto x:arr2){
            a2.push_back(x.second);
        }
        sort(a2.begin(), a2.end());
        sort(a1.begin(), a1.end());
        if(a1==a2 and w1==w2){
            return true;
        }
        return false;
    }
};