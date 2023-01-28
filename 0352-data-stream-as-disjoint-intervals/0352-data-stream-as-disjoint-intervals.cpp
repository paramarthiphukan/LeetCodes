class SummaryRanges
{
    set<int> vals;
public:
    SummaryRanges() 
    {
        
    }
    
    void addNum(int val) 
    {
        vals.insert(val);
    }
    
    vector<vector<int>> getIntervals() 
    { 
        vector<vector<int>> ans;
        
        if (vals.size() == 0)
            return ans;
        
        ans.push_back({*vals.begin(), *vals.begin()});

        for (auto it = next(vals.begin()); it != vals.end(); it++)
        {
            if (*it == ans.back()[1] + 1)
                ans.back()[1] = *it;
            else
                ans.push_back({*it, *it});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */