class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        threshold *= k;
        int cnt = 0;
        int sum = accumulate(arr.begin(), arr.begin() + k, 0);
        cnt += (sum >= threshold);
        for (int i = k; i < arr.size(); ++i) {
            sum += arr[i] - arr[i - k];
            cnt += (sum >= threshold);
        }
        return cnt;
    }
};