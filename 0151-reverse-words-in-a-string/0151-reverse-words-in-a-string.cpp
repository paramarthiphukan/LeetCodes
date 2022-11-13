class Solution {
public:
    string reverseWords(string s)
{

    int n = s.size();

    vector<string> arr;

    for (int i = 0; i < n; i++)
    {

        string temp;

        bool ok = 0;
        while (i < n && s[i] != ' ')
        {
            temp.push_back(s[i]);
            ok = 1;
            i++;
        }

        if (ok)
            arr.push_back(temp);
    }

    reverse(arr.begin(), arr.end());

    string ans;

    for (auto it : arr)
    {

        for (auto s : it)
        {

            ans.push_back(s);
        }

        ans.push_back(' ');
    }

    ans.pop_back();

    return ans;
}
   };