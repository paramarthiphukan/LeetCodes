class Solution
{
public:
     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
     {
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> ans;
        for(int i = 0; i < nums1.size(); i++) 
        {
            for(int j = 0; j < nums2.size(); j++) 
            {
     pair<int, pair<int,int>> temp(nums1[i] + nums2[j], {nums1[i], nums2[j]});
                if(pq.size() < k)
                {
                    pq.push(temp);
                }
                else 
                {
                    if(pq.top().first > temp.first) 
                    {
                        pq.pop();
                        pq.push(temp);
                    }
                    else 
                    {
                        break;
                    }
                }
            }
        }
         
        int size = pq.size();
        cout << size << endl;
        for(int i = 0; i < size; i++) 
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};