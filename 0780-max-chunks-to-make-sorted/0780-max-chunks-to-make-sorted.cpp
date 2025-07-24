class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int sortedSum = 0, sum = 0, cnt = 0;
        for(int i=0; i<n; i++){
            sum += i;
            sortedSum += arr[i];
            if(sum == sortedSum) cnt++;
        }
        return cnt;
    }
};