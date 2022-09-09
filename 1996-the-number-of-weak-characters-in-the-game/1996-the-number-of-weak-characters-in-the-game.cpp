class Solution {
public:
   static bool cmpfnc(vector<int>& a, vector<int>& b)
   {
        if (a[0] == b[0])
            return a[1] > b[1];
        
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) 
    {
        int count = 0, i, cur_max, size;
        
        sort(properties.begin(), properties.end(), cmpfnc);
        size = properties.size();
        cur_max = properties[size-1][1];
            
        for (i=size-1; i>=0; i--) 
        {
            if (properties[i][1] < cur_max)
                count++;
            else
                cur_max = properties[i][1];
        }
        return count;
    }
};