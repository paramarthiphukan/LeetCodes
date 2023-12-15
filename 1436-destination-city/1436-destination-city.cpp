class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
    string d = paths[0][1]; 

    for(int i = 0; i < paths.size(); ++i)
        if (d == paths[i][0])   
            d = paths[i][1],    
            i = -1;

    return d;   
}
};