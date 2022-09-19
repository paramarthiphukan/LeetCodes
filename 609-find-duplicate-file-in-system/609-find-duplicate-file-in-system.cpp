class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) 
    {
       vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        int i;
        for(auto path : paths)
        {
           string pt = "";
            for( i = 0 ; i < path.size() && path[i] != ' ' ; i ++)
                pt += path[i];
            pt +='/';
            i++;   
          while( i < path.size())
          {
                string data , file ;
              while( i < path.size() && path[i] != '(')
                  file += path[i++];
                while( i < path.size() && path[i] != ' ')
                 data += path[i++];
          mp[data].push_back(pt+file);
              i++;
          }
         }
        for(auto it : mp)
        {
            if(it.second.size() > 1)
                ans.push_back(it.second);
        }
        return ans;
    }
};