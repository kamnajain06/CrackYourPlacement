class Solution {
public:
    void merge(vector<int> &nums, int start, int end, int &cnt){
        int mid = (start + end)/2;
        int n1 = mid - start + 1, n2 = end - mid;
        vector<int> arr1(n1), arr2(n2);
        int idx = start;
        for(int i=0; i<n1; i++) arr1[i] = nums[idx++];
        for(int i=0; i<n2; i++) arr2[i] = nums[idx++];

        int i = 0, j = 0;
        idx = start;
        while(i < n1 && j < n2){
            if(arr1[i] > (long long)2* arr2[j]){
                cnt += n1-i;
                j++;
            }else{
               i++;
            }
        }
        i=0, j=0;
        while(i < n1 && j < n2){
            if(arr1[i] <= arr2[j]){
                nums[idx++] = arr1[i++];
            }else{
                nums[idx++] = arr2[j++];
            }
        }
        while(i < n1) nums[idx++] = arr1[i++];
        while(j < n2) nums[idx++] = arr2[j++];

    }
    void mergeSort(vector<int> &nums, int start, int end, int &cnt){
        if(start >= end) return;
        int mid = (start + end)/2;

        mergeSort(nums, start, mid, cnt);
        mergeSort(nums, mid+1, end, cnt);
        merge(nums, start, end, cnt);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        mergeSort(nums, 0, n-1, cnt);
        return cnt;
    }
};