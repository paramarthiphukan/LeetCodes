class Solution {
public:
     int timeRequiredToBuy(vector<int>& arr, int k)
     {
    queue<int>q;
        for(int i=0;i<arr.size();i++)q.push(i);
        int cnt=0;
        while(!q.empty())
        {
            cnt++;
            int temp = q.front();
            q.pop();
            if(arr[temp]>=1)arr[temp]-=1;
            if(arr[temp]==0 && temp!=k)continue;
            if(arr[temp]==0 && temp==k)break;
            q.push(temp);
        }
         return cnt;
        
    }
};
