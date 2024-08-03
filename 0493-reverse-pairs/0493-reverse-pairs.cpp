class Solution {
public:
void mergeSort(vector<int>& nums,long long start, long long end,long long &count){
        long long mid = (start+end)/2;
        long long  startIndex = start;
        long long n1= mid-start+1;
        long long n2= end - mid;
        vector<int> arr1(n1);
        vector<int> arr2(n2);
        for(long long i=0; i<n1; i++){
            arr1[i]=nums[startIndex++];
        }
        for(long long i=0; i<n2; i++){
            arr2[i]=nums[startIndex++];
        }
        long long i=0;
        long long j=0;
        while(i<n1 && j<n2){
            if((long long)arr1[i]>(long long)2*arr2[j]){
                j++;
            }else{
                count+=j;
                i++;
            }
        }
        while(i<n1){
            count+=j;
            i++;
        }
        i=0;
        j=0;
        while(i<n1 && j<n2){
            if(arr1[i]<=arr2[j]){
                nums[start++]=arr1[i++];
            }else{
                nums[start++]=arr2[j++];
            }
            
        }
        while(i<n1){
            nums[start++]=arr1[i++];
        }
        while(j<n2){
            nums[start++]=arr2[j++];
        }
    }
    void merge(vector<int>& nums,long long start,  long long end, long long &count){
        if(start>=end){
            return;
        }
        long long mid = (start+end)/2;
        merge(nums,start,mid,count);
        merge(nums,mid+1,end,count);
        mergeSort(nums,start,end,count);
    }
    int reversePairs(vector<int>& nums) {
        long long count = 0;
        merge(nums,0,nums.size()-1,count);
        return (int)count;
    }
};