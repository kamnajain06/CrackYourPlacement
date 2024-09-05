class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;

        int sumRolls = 0;
        for(auto it:rolls){
            sumRolls += it;
        }

        int nSum = (rolls.size() + n)*mean - sumRolls;

        if(nSum > 6*n || nSum < n) return ans;

        for(int i=0; i<n; i++){
            ans.push_back(nSum/n);
        }
        int extra = nSum%n; 
        for(int i=0; i<extra; i++){
            ans[i]++;
        }

        return ans;
    }
};