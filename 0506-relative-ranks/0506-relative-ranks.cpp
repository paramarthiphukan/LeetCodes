class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=score[i];
        }
        sort(arr, arr+n);
        vector<string>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[j]==score[i]){
                    if(j+1 == n){
                        v.push_back("Gold Medal");
                    }
                    else if(j+1 == n-1){
                        v.push_back("Silver Medal");
                    }
                    else if(j+1 == n-2){
                        v.push_back("Bronze Medal");
                    }
                    else{
                        v.push_back(to_string(n+1 -(j+ 1)));
                    }
                }
            }
        }
        return v;
    }
};