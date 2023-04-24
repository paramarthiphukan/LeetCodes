class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int> q;
        int ans = 0;
        for(auto it:nums){
            q.push(it);
        }
        while(true){
            if(q.size()==1 || q.size()==0) break;
            int v1 = q.top(); q.pop();
            int v2 = q.top(); q.pop();
            if(v1 != v2){
                q.push(v1-v2);
            }
        }
        if(q.size()) ans = q.top();
        return ans;
    }
};