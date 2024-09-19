bool compare(int a, int b){
    string sta = to_string(a);
    string stb = to_string(b);

    if((sta+stb)>(stb+sta)) return true;
    return false;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string ans = "";
        if(nums[0] == 0) return "0";
        for(auto it:nums){
            ans += to_string(it);
        }
        return ans;

    }
};