class Solution 
{
public:
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n=rooms.size();
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int curr_room = q.front(); q.pop();
            vis[curr_room] = 1;
            for(auto key:rooms[curr_room])
                if(!vis[key])
                    q.push(key);
        }

        for(int i=0; i<n; i++)
        if(!vis[i]) return false;
    return true;
  }
};