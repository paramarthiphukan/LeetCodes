class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int cnt = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                cnt += customers[i];
            }
            customers[i] *= grumpy[i];
        }
        int maxi=0;
        int temp=0;
        for(int i=0;i<minutes;i++){
            temp+=customers[i];
        }
        if(maxi<temp) maxi=temp;
        for(int i=minutes;i<customers.size();i++){
            temp-=customers[i-minutes];
            temp+=customers[i];
            if(maxi<temp) maxi=temp;
        }
        return cnt+maxi;
    }
};