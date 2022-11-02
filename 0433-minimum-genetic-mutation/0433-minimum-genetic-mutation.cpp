class Solution 
{
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        
        unordered_set<string> visit; 
        unordered_set<string> hash(bank.begin(), bank.end()); 
        unordered_map<string,int> distance; 
        queue<string> q; 
        q.push(start);  
        visit.insert(start);  
        distance[start] = 0; 
        
        if(start == end)
            return 0; 
        
        int dis = 0;
        
        vector<char> characters = {'A', 'C', 'G', 'T'};  
        
        while(!q.empty()) 
        { 
            
            string curr = q.front();q.pop(); 
            
            for(int i = 0; i < 8; ++i) 
            {
                int parent = distance[curr]; 
                char c = curr[i]; 
                for(auto ch : characters) 
                {
                    curr[i] = ch;  
                    if(hash.find(curr) != hash.end() && visit.find(curr) == visit.end()) {
                        
                        visit.insert(curr);  
                        q.push(curr); 
                        distance[curr] = parent + 1; 
                        if(curr == end) 
                        {
                            return distance[curr]; 
                        }
                    }
                }
                curr[i] = c;
            } 
            
        }
        if(visit.find(end) != visit.end()) 
            return distance[end];   
        return -1; 
    }
};
