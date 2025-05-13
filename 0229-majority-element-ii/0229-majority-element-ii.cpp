class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i] == ele1){
                cnt1++;
            }else if(nums[i] == ele2){
                cnt2++;
            }else{
                if(cnt1 == 0){
                    ele1 = nums[i];
                    cnt1++;
                }else if(cnt2 == 0){
                    ele2 = nums[i];
                    cnt2++;
                }else{
                    cnt1--;
                    cnt2--;
                    if(cnt1 == 0){
                        ele1 = nums[i];
                        cnt1++;
                    }else if(cnt2 == 0){
                        ele2 = nums[i];
                        cnt2++;
                    }
                }
            }
        }
        cnt1 = cnt2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
        }
        if(cnt1 > n/3) ans.push_back(ele1);
        if(cnt2 > n/3) ans.push_back(ele2);
        return ans;
    }
};