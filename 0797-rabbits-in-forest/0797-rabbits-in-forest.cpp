class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int> mpp;
        for(auto it:answers) mpp[it]++;

        int ans = 0;
        for(auto &[key, val]: mpp){
            if(key == 0) ans += (val);
            else if(val > key+1){
                int temp = val/(key+1);
                int rem = val - (key+1)*temp;
                ans += temp*(key+1);
                if(rem) ans += key+1;
            }else{
                ans += (key+1);  
            }
        }
        return ans;
    }
};