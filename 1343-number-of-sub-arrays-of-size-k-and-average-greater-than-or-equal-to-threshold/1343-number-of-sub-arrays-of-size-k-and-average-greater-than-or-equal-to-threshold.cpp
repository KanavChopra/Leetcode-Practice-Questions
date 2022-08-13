class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int cnt = 0;
        int sum = accumulate(arr.begin(), arr.begin() + k, 0);
        if (sum / k >= threshold) {
            cnt++;
        }
        for (int i = k; i < n; ++i) {
            sum -= arr[i - k];
            sum += arr[i];
            if (sum / k >= threshold) {
                cnt++;
            }
        }
        return cnt;
    }
};