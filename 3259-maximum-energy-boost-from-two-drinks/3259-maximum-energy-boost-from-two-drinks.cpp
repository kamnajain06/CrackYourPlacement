class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        vector<long long> curr(2,0), next(2,0);
        int n = energyDrinkA.size();
        for(int i = 0; i < n; i++){
            curr[0] = max(energyDrinkA[i]+next[0],next[1]);
            curr[1] = max(energyDrinkB[i]+next[1],next[0]);
            next = curr;
        }

        return max(next[0], next[1]);
    }
};