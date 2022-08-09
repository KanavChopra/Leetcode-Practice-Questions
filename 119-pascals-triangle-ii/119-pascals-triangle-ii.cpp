class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> currRow;
        currRow.push_back(1);
        if (rowIndex == 0) {
            return currRow;
        }
        vector<int> prevRow = getRow(rowIndex - 1);
        for (int i = 1; i < prevRow.size(); ++i) {
            int val = prevRow[i - 1] + prevRow[i];
            currRow.push_back(val);
        }
        currRow.push_back(1);
        return currRow;
    }
};