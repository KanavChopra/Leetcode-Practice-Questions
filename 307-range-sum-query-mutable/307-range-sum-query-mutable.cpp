class NumArray {
    vector<int> segTree;
    int n;
public:
    void buildTree(vector<int>& nums, int segTreeIdx, int start, int end) {
        if (start == end) {
            segTree[segTreeIdx] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(nums, 2 * segTreeIdx + 1, start, mid);
        buildTree(nums, 2 * segTreeIdx + 2, mid + 1, end);
        segTree[segTreeIdx] = segTree[2 * segTreeIdx + 1] + segTree[2 * segTreeIdx + 2];
    }
    
    void updateTree(int segTreeIdx, int start, int end, int idx, int val) {
        if (start == end) {
            segTree[segTreeIdx] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx > mid) {
            updateTree(2 * segTreeIdx + 2, mid + 1, end, idx, val);
        } else {
            updateTree(2 * segTreeIdx + 1, start, mid, idx, val);
        }
        segTree[segTreeIdx] = segTree[2 * segTreeIdx + 1] + segTree[2 * segTreeIdx + 2];
    }
    
    int queryTree(int start, int end, int segTreeIdx, int left, int right) {
        if (left > end || right < start) {
            return 0;
        }
        if (start >= left && end <= right) {
            return segTree[segTreeIdx];
        }
        int mid = start + (end - start) / 2;
        return queryTree(start, mid, 2 * segTreeIdx + 1, left, right) + queryTree(mid + 1, end, 2 * segTreeIdx + 2, left, right);
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4 * n, 0);
        buildTree(nums, 0, 0, n - 1);
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return queryTree(0, n - 1, 0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */