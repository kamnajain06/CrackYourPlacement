class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> v;
        
        for(int i=0; i<nums.size(); i++ ){
            
            if(i>0 && nums[i] == nums[i-1]) continue;
            vector<int> ans(3,-1);
            ans[0] = nums[i];
            
            int left = i+1;
            int right = nums.size()-1;
            
            while(left < right){
                if(nums[left] + nums[right] + nums[i] == 0){
                    cout<<nums[left]<<" "<<nums[right]<<endl;
                    ans[1] = nums[left++];
                    ans[2] = nums[right--];
                    v.push_back(ans);
                    
                    while(left<right && nums[left] == nums[left-1]) left++;
                    while(left<right && nums[right] == nums[right+1]) right--;
                }else if(nums[left] + nums[right] + nums[i] > 0 ){
                    right--;
                }else{
                    left++;
                }
                
            }
        }
        
        return v;
    }
};