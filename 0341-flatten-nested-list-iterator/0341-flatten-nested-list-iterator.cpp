/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator 
{
private:
    vector<NestedInteger> v;
    queue<int> q;
    
    void getAllIntegers(vector<NestedInteger> &v, queue<int>& q)
    {
        for(auto& ele: v)
        {
            if(ele.isInteger()) q.push(ele.getInteger());
            else 
            {
                auto listItems = ele.getList();
                getAllIntegers(listItems, q);
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        v = nestedList;
        getAllIntegers(v, q);
    }
    
    int next()
    {
        int ele = q.front();
        q.pop();
        return ele;
    }
    
    bool hasNext()
    {
        return q.size() > 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */