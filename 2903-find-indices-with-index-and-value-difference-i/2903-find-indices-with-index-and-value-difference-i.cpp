class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int ans1 = -1, ans2 = -1;
        for(int i = 0; i < nums.size(); i++){
            for(int j=0; j < nums.size(); j++){
                if(abs(i-j) >= indexDifference and abs(nums[i]-nums[j]) >= valueDifference){
                    ans1 = i; ans2 = j;
                    break;
                }
            }
        }
        return {ans1, ans2};
    }
};