class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int ind = 0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == val){
                if(cnt == 0) ind = i;
                cnt++;
            }
        }
        for(int i=ind; i<nums.size(); i++){
            if(i+cnt >= nums.size()) break;
            nums[i] = nums[i+cnt]; 
        }
        return nums.size()-cnt;
    }
};