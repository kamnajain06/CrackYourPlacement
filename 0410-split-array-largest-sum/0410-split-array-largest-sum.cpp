class Solution {
public:
    int sum(vector<int>& nums, int n , int mid){
        int sum = nums[0];
        int cnt = 1;
        for(int i=1; i<n ; i++){
            if(sum+ nums[i] <= mid){
                sum+=nums[i];
            }else{
                sum = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0 ; i<n; i++){
            totalSum+=nums[i];
        }
        int low = *max_element(nums.begin(), nums.end());
        int high = totalSum;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int count = sum(nums, n, mid);
            if(count <= k){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};