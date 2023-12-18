class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
    priority_queue<int, vector<int>, less<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    for(auto num: nums) {
        pq1.push(num);
        if(pq1.size()>2) { pq1.pop(); }

        pq2.push(num);
        if(pq2.size()>2) { pq2.pop(); }            
    }

    auto a=pq1.top(); pq1.pop();
    auto b=pq2.top(); pq2.pop();
    return pq2.top()*b-pq1.top()*a;
}
};