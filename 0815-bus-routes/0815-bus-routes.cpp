class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        int n = routes.size();
        unordered_map<int,vector<int>> ump;
        
        for(int i=0;i<n;++i){
            for(auto key : routes[i]){
                ump[key].push_back(i);
            }
        }
        
        unordered_map<int,bool> visStation;
        vector<bool> visBus(n,false);
        queue<pair<int,int>> q;
        q.push({source,0});
        
        while(!q.empty()){
            
            int curNode = q.front().first;
            int curVal = q.front().second;
            if(curNode == target) return curVal;
            
            q.pop();
            visStation[curNode] = true;

            for(auto &busNo : ump[curNode]){
                if(visBus[busNo]) continue;

                for(auto &nextNode : routes[busNo]){
                    if(visStation.find(nextNode) == visStation.end()) q.push({nextNode,curVal+1});
                }

                visBus[busNo] = true;
            }
        }
        
        return -1;
    }
};