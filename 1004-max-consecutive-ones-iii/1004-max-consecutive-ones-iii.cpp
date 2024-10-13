class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int temp = k;
        int i = 0, j = 0;
        int ans = 0;

        while(j < nums.size() && i <= j){
            if(nums[j] == 1){
                j++;
            }else if(nums[j] == 0){
                if(temp > 0){
                    temp--;
                    j++;
                }else{
                    if(nums[i] == 0){
                        if(k > 0){
                            temp++; 
                        }else{
                            j++;
                        }
                    }
                    i++;
                }
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};