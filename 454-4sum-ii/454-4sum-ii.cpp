class Solution {
public:
      int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
      {
        int n=nums1.size();
        vector<int> numfin1;
        vector<int> numfin2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                numfin1.push_back(nums1[i]+nums2[j]);
                numfin2.push_back(nums3[i]+nums4[j]);
            }
        }
        unordered_map<int,int> map;
        int m=numfin1.size();
        for(int i=0;i<m;i++)
        {
            map[numfin1[i]]++;
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            ans+=map[-numfin2[i]];
        }
        return ans;
    }
};