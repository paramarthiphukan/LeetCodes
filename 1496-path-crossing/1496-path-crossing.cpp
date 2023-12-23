class Solution {
public:
    bool isPathCrossing(string path) 
    {
        
        set<pair<int, int>> coordinates;
        int x =0;
        int y=0;
        coordinates.insert({x,y});
        for(auto ch: path)
        {
            if(ch == 'N') y += 1;
            else if(ch == 'E') x += 1;
            else if(ch == 'W') x-= 1;
            else y -= 1;
            
            if(coordinates.count({x,y}))
            {
                return true;
            }
            coordinates.insert({x,y});
        }
        return false;
    }
};