class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> correct = heights;
        sort(correct.begin(), correct.end());

        int count = 0;
        for(int i=0; i<heights.size(); i++)
            if(correct[i] != heights[i])
                ++count;

        return count;
    }
};