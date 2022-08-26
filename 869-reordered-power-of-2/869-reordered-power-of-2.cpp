class Solution {
public:
        bool reorderedPowerOf2(int n) {
        int arr[10];
        memset(arr,0,sizeof(arr));
        
        int x =n;
        for(;x>0;){
            int rem = x%10;
            arr[rem]++;
            x = x/10;
        }
        for(int i=0; i<31; i++){
            int check[10];
            memset(check,0,sizeof(check));
            int y = pow(2,i);
            while(y>0){
                int rem = y%10;
                check[rem]++;
                y = y/10;
            }
            bool flag = true;
            for(int j=0; j<10; j++){
                if(arr[j]!=check[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};