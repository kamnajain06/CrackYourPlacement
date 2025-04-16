class Solution {
private:
    vector<int> segTree;
public:

    int query(int start, int end, int i, int l, int r){
        if(r < start || l > end) return 0;
        else if(l >= start && r <= end) return segTree[i];
        int mid = l + (r-l)/2;
        return segTree[i] = query(start, end, 2*i+1, l, mid) + query(start, end, 2*i+2, mid + 1, r);
    }
    void queryUpdate(int idx, int i, int l, int r){
        if(l == r){
            segTree[i] = 1;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid){
            queryUpdate(idx, 2*i+1, l, mid);
        }else{
            queryUpdate(idx, 2*i+2, mid+1, r);
        }
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        return;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        segTree.resize(4*n, 0);
        unordered_map<int,int> nums2Idx;

        for(int i=0; i<n; i++){
            nums2Idx[nums2[i]] = i;
        }
        long long ans = 0;
        queryUpdate(nums2Idx[nums1[0]], 0, 0, n-1);
        for(int i=1; i<n; i++){
            int idx = nums2Idx[nums1[i]];  //idx of nums1[i] in nums2
            long long leftCommonElements = query(0, idx, 0, 0, n-1);
            long long leftUncommonElements = i - leftCommonElements;
            long long rightElementsNums2 = n - idx - 1;
            long long rightCommonElements = rightElementsNums2 - leftUncommonElements;
            ans += (leftCommonElements * rightCommonElements);

            queryUpdate(idx, 0, 0, n-1);
        }

        return ans;
    }
};