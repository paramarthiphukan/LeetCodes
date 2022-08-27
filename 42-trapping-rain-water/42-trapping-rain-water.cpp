class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        vector<int> left(height.size());
        vector<int> right(height.size());
        left[0]=-1;
        for(int i=1;i<height.size();i++)
        {
            left[i]=max(left[i-1],height[i-1]);
        }
        right[height.size()-1]=-1;
        for(int i=height.size()-2;i>=0;i--)
        {
            right[i]=max(right[i+1],height[i+1]);
        }
        int sum=0;
        
        for(int i=0;i<height.size();i++)
        {
            int a=min(left[i],right[i])-height[i];
            if(a<0)a=0;
            sum+=a;
        }
        return sum;
    }
};