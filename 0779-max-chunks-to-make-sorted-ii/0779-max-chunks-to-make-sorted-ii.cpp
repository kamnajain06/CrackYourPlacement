class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        long long sortedSum = 0, sum = 0, cnt = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            sortedSum += sorted[i];
            if(sum == sortedSum) cnt++;
        }
        return cnt;
    }
};