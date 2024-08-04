class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        
        for(int i=0; i<nums.size(); i++ ){
            if(i>0 && nums[i] == nums[i-1]) continue;
            vector<int> ans(4,-1);
            ans[0] = nums[i];
            
            for(int j=i+1; j<nums.size(); j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                ans[1] = nums[j];

                int left = j+1;
                int right = nums.size()-1;
                while(left < right){
                if((long)nums[left] + nums[right] + nums[i] + nums[j] == (long)target){
                    ans[2] = nums[left++];
                    ans[3] = nums[right--];
                    v.push_back(ans);
                    
                    while(left<right && nums[left] == nums[left-1]) left++;
                    while(left<right && nums[right] == nums[right+1]) right--;
                }else if((long)nums[left] + nums[right] + nums[i] + nums[j] > (long)target ){
                    right--;
                }else{
                    left++;
                }
                
            }
            }
        }
        
        return v;
    } 
};