class NumArray {
public:
    int last = 0;
    vector<int> segTree;
    void buildTree(int i, int l, int r, vector<int> &nums){
        if(l == r){
            segTree[i] = nums[l];
            return;
        }
        int mid = (l + r)/2;
        buildTree(2*i+1, l , mid, nums);
        buildTree(2*i+2, mid+1 , r, nums);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        return;
    }
    NumArray(vector<int>& nums) {
        int n = nums.size();
        segTree.resize(4 * n + 1, 0);
        last = n-1;
        buildTree(0, 0, n-1, nums);
        return;
    }
    int Query(int start, int end, int i, int l, int r){
        if(end < l || start > r) return 0;
        else if(l >= start && r <= end) return segTree[i];
        int mid = (l + r)/2;
        return Query(start, end , 2*i+1, l, mid) + Query(start, end , 2*i+2, mid + 1, r); 
    }
    int sumRange(int left, int right) {
        return Query(left, right , 0, 0, last);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */