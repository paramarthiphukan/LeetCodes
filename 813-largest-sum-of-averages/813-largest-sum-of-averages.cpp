class Solution 
{
public:
    double arr[101][101]={};
    vector<int> num;
    double fun(int l,int k)
    {
        if(l>num.size()) return 0;
        if(k==0)
        {
            double sum=0;
            int i=l;
            for(;i<num.size();i++)
                sum+=num[i];
            return arr[l][k]=sum/(i-l);
        }
        if(arr[l][k]) return arr[l][k];
        
        double sum=0;
        double mx=0;
        for(int i=l;i<num.size();i++)
        {
            sum+=num[i];
            mx=max(mx,sum/(i-l+1)+fun(i+1,k-1));
        }
        return arr[l][k]=mx;
    }
    double largestSumOfAverages(vector<int>& nums, int k) 
    {
        num=nums;
        return fun(0,k-1); 
    }
};