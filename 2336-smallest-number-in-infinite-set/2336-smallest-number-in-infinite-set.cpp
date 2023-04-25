class SmallestInfiniteSet 
{
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> mp;
public:
    SmallestInfiniteSet()
    {
        //priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < 1000; i++) 
        {
            pq.push(i + 1);
            mp[i + 1]++;
        }
    }
    
    int popSmallest() 
    {
        int temp = pq.top();
        pq.pop();
        mp.erase(temp);
        return temp;
    }
    
    void addBack(int num) 
    {
        if(mp.find(num) == mp.end())
        {
            pq.push(num);
            mp[num]++;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */