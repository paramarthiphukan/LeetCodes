class Solution {
public:
    vector<string> commonChars(vector<string>& A) {        
        string s = A[0];
        vector<string> res;
        int j=0, k;
        char search;
        while(j != s.length()) {
            search = s[j];
            k = 0;
             for(int i=1; i<A.size(); i++) {
                 if(A[i].find(search) != -1) {
                     A[i].erase(A[i].find(search),1);
                     k++;
                 }         
             }
            if(k == A.size()-1)
                res.push_back(string(1, search));
            j++;
        }
    return res;
  }
};