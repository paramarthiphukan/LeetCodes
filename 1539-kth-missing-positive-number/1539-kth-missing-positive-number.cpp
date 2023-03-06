class Solution 
{
public:
    int findKthPositive(vector<int>& v, int k) 
    {
    for(int i=1;;++i)
    {
        auto it = find(v.begin(), v.end(), i);
        if(it==v.end()) k--;
        if(k==0){
            return i;
            break;
        }
    } return 0;
    }
};