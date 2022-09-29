class Solution 
{
    class Comp
    {
        public:
        bool operator()(pair<int,int> &a,pair <int,int> &b)
        {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        }
    };
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        priority_queue <pair<int,int>, vector<pair<int,int>>, Comp> pq;
        for(int i=0;i<arr.size();i++)
        {
            pq.push({abs(x-arr[i]),arr[i]});
            if(pq.size() > k)
                pq.pop();
        }
        vector <int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};