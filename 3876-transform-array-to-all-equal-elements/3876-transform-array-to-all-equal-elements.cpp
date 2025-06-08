class Solution {
public:
    bool f(vector<int> nums, int n, int k, int pos){
        for(int i=0; i<n-1; i++){
            if(nums[i] != pos && k == 0) return false;
            if(nums[i] != pos){
                nums[i] = -(nums[i]);
                nums[i+1] = -(nums[i+1]);
                k--;
            }
        }
        return nums[n-1] == pos;
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        bool allOnes = f(nums, n, k, 1);
        bool allNegOnes = f(nums, n, k, -1);
        return allOnes || allNegOnes;
    }
};