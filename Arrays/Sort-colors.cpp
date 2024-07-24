class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes = 0;
        int ones = 0;
        int twoes = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zeroes++;
            }else if(nums[i] == 1){
                ones++;
            }else{
                twoes++;
            }
        }
        int i=0;
        while(zeroes != 0){
            nums[i++]=0;
            zeroes--;
        }
        while(ones != 0){
            nums[i++]=1;
            ones--;
        }
        while(twoes != 0){
            nums[i++]=2;
            twoes--;
        }
    }
};