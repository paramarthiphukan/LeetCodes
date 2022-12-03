class Solution {
public:
    string frequencySort(string s) {
      unordered_map<char,int>y;
        for(auto it:s){
            y[it]++;
        }
        vector<pair<int,char>>vc;
        for(auto it:y){
           vc.push_back({it.second,it.first}); 
        }
        sort(vc.begin(),vc.end(),greater<pair<int,char>>());
        string res;
        for(int i=0;i<vc.size();i++){
            int val=vc[i].first;
            while(val--){
                res+=vc[i].second;
            }
        }
   return res; }
};