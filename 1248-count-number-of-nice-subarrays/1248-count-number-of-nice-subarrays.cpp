class Solution {
public:
    int func(vector<int> &nums, int k){
        if(k<0) return 0;
        int sum = 0;
        int cnt = 0;
        int i=0, j=0;

        while(j < nums.size() && i <= j){
            if(nums[j]%2 == 1){
                sum++;
            }
            while(sum > k){
                if(nums[i]%2 == 1) sum--;
                i++;
            }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k) - func(nums,k-1);
    }
};