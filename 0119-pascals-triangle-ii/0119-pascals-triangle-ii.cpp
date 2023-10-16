class Solution {
public:
      vector<int> getRow(int rowIndex) 
      {
        vector <int> v;
        v.push_back(1);
        if(rowIndex==0)
        {
            return v;
        }
        v.push_back(1);
        if(rowIndex==1)
        {
            return v;
        }
        while(rowIndex>1)
        {
            vector <int> temp(v.begin(),v.end());
            for(int i=1; i<temp.size(); i++)
            {
                v[i] = temp[i]+temp[i-1];
            }
            v.push_back(1);
            rowIndex--;
        }
        return v;
    }
};