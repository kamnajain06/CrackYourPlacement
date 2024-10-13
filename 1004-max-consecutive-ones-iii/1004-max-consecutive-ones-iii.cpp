class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int temp = k;
        int i = 0, j = 0;
        int ans = 0;

        while(j < nums.size() && i <= j){
            if(nums[j] == 1){
                j++;
            }else if(nums[j] == 0 && temp > 0){
                temp--;
                j++;
            }else if(nums[j] == 0 && temp <= 0){
                while(nums[i] == 1) i++;
                if(nums[i] == 0){
                    if(k > 0){
                        temp++;
                        i++;
                    }else{
                        i++;
                        j++;
                    }
                }
            } 
            ans = max(ans, j-i);
        }
        return ans;
    }
};