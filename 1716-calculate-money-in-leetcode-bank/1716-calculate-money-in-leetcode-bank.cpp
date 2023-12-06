class Solution {
public:
    int totalMoney(int n) {
        int initial = 1;
        int st =1;
        int sum = 0;
        int cnt = 0;
        
        while(n--){
            
            sum+=initial;
            initial++;
            cnt++;
            if(cnt==7){
                initial = st+1;
                st = initial;
                cnt = 0;
            }

        }
        return sum;
    }
};