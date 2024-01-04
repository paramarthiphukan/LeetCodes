class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }

        int ans = 0;
        for(auto it : mp){
            if(it.second == 1){
                return -1;
            }
            if(it.second % 3 == 0){
                ans += it.second/3;
            }
            else if(it.second % 3 == 2){
                ans += it.second/3;
                ans++;
            }
            else if(it.second % 3 == 1){
                if(it.second/3 == 1){
                    ans += it.second/2;
                }
                else{
                    int temp = it.second/3;
                    temp--;
                    ans = ans + temp;
                    ans += 2;
                }
            }
        }

        return ans;
    }
};