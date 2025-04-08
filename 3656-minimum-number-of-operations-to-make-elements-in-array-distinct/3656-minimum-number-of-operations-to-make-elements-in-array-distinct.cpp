class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       //try iterating from last
       int n = nums.size();
       unordered_map<int,int> freq;
       for(int i=n-1; i>=0; i--){
            if(freq.find(nums[i]) == freq.end()) freq[nums[i]]++;
            else{
                return ((i+1) % 3) == 0 ? (i+1)/3 : ((i+1)/3) + 1;
            }
       } 
       return 0;
    }
};