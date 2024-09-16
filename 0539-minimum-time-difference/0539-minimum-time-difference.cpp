class Solution {
public:
    int convertToMinutes(string time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (string time : timePoints) {
            minutes.push_back(convertToMinutes(time));
        }

        sort(minutes.begin(), minutes.end());

        int n = minutes.size();
        int mini = INT_MAX;

        for (int i = 1; i < n; i++) {
            mini = min(mini, minutes[i] - minutes[i-1]);
        }

        mini = min(mini, (1440 - minutes[n-1] + minutes[0]));

        return mini;
    }
};
