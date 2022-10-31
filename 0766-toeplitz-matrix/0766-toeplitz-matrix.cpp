class Solution {
public:
     bool isToeplitzMatrix(vector<vector<int>>& arr) {
        for(int i=0;i<arr[0].size();i++)
        {
            int ele=arr[0][i];
            if(fun(0,i,ele,arr)==false)
            {
                return false;
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            int ele=arr[i][0];
            if(fun(i,0,ele,arr)==false)
            {
                return false;
            }
        }
        return true;
    }
    bool fun(int i,int j,int &ele,vector<vector<int>>& arr)
    {
        while(i<arr.size() and j<arr[0].size())
        {
            if(arr[i][j]!=ele)
            {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};