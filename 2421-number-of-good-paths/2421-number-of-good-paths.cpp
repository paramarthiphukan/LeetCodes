class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        unordered_map<int, unordered_map<int,int>> valueFreqMap;
        int n = vals.size(), iFather, jFather, iCount, jCount, currVal, res = n;
        vector<int> father(n);
        for(int i = 0; i < n; i++)
            father[i] = i;
        for(int i = 0; i < n; i++)
            valueFreqMap[i][vals[i]] = 1;
        vector<vector<int>> sortValEdges;
        for(auto edge : edges)
            sortValEdges.push_back({max(vals[edge[0]], vals[edge[1]]), edge[0], edge[1]});
        sort(sortValEdges.begin(), sortValEdges.end());
        for(auto &x : sortValEdges) {
            currVal = x[0];
            iFather = find(father, x[1]);
            jFather = find(father, x[2]);
            iCount = valueFreqMap[iFather][currVal];
            jCount = valueFreqMap[jFather][currVal];
            res += iCount*jCount;
            father[jFather] = iFather;
            valueFreqMap[iFather][currVal] = iCount + jCount;
        }
        return res;

    }
    int find(vector<int>& father, int x) {
        if(father[x] != x)
            father[x] = find(father, father[x]);
        return father[x];
    }
};