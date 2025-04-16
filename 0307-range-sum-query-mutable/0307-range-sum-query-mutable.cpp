class NumArray {
private:
    vector<int> segTree;
    int last = 0;
public:
    void buildTree(int i , int l, int r, vector<int> &nums){
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
       last = n-1;
       segTree.resize(4*n, 0);
       buildTree(0, 0, n-1, nums); 
       return;
    }
    void updateQuery(int ind , int val, int i, int l, int r){
        if(l == r){
            segTree[i] = val;
            return;
        }
        int mid = (l + r)/2;
        if(ind > mid){
            updateQuery(ind, val, 2*i+2, mid+1, r);
        }else{
            updateQuery(ind, val, 2*i +1, l, mid);
        }
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        return;
    }
    void update(int index, int val) {
        return updateQuery(index, val,0, 0, last);
    }
    int query(int start, int end, int i, int l, int r){
        if(l > end || start > r){
            return 0;
        }else if( l>= start && r <= end){
            return segTree[i];
        }
        int mid = (l + r)/2;
        return query(start, end, 2*i+1, l, mid) + query(start, end, 2*i+2, mid+1, r);
    }
    int sumRange(int left, int right) {
        return query(left, right, 0, 0, last);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */