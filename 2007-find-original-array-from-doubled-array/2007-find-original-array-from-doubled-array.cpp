class Solution
{
public:
    vector<int> findOriginalArray(vector<int>& changed)
    {
          vector<int> original = {};
        unordered_map<int, int> waiting;
        sort(changed.begin(), changed.end());
        
        for(int i = 0; i < changed.size(); i++)
        {
            if(waiting.find(changed[i]) != waiting.end() && waiting[changed[i]] > 0) waiting[changed[i]]--;
            else
            {
                original.push_back(changed[i]);
                waiting[changed[i]*2]++;
            }
        }
        if(original.size() * 2 == changed.size()) return original;
        else return {};
    }
};