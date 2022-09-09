class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
         sort(properties.begin(), properties.end(), [](const vector<int> &a, const vector<int> &b) {
             return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
        });

        int res = 0;
        int mx = INT_MIN;
        for (auto p : properties) {
            if (mx > p[1]) 
                res++;
            else 
                mx = p[1];
        }
        return res;
    }
};