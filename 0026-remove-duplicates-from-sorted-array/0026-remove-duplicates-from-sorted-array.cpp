class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1;
        int fast = 1;
        int cnt = 1;

        while(fast != nums.size()){
            if(nums[fast] > nums[fast-1]){
                if(nums[slow] <= nums[slow-1]){
                    nums[slow] = nums[fast];
                }
                cnt++;
                slow++;
                fast++;
            }else{
                fast++;
            }
        }
        return cnt;
    }
};