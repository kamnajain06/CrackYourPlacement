class Solution {
public:
    vector<int> nseVec(vector<int>& arr, int n){
        vector<int> nse(n,n);
        stack<int> st;
        for(int i= n-1; i>=0; i--){
            while(!st.empty()){
                if(arr[st.top()]<arr[i]){
                    nse[i] = st.top();
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> ngeVec(vector<int>& arr, int n){
        vector<int> nge(n,n);
        stack<int> st;
        for(int i= n-1; i>=0; i--){
            while(!st.empty()){
                if(arr[st.top()]>arr[i]){
                    nge[i] = st.top();
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return nge;
    }
    vector<int> pseVec(vector<int>& arr, int n){
        vector<int> pse(n,-1);
        stack<int> st;
        for(int i= 0; i<n; i++){
            while(!st.empty()){
                if(arr[st.top()]<=arr[i]){
                    pse[i] = st.top();
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return pse;
    }
    vector<int> pgeVec(vector<int>& arr, int n){
        vector<int> pge(n,-1);
        stack<int> st;
        for(int i= 0; i<n; i++){
            while(!st.empty()){
                if(arr[st.top()]>=arr[i]){
                    pge[i] = st.top();
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return pge;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        vector<int> nse = nseVec(nums, n);
        vector<int> pse = pseVec(nums, n);
        vector<int> nge = ngeVec(nums, n);
        vector<int> pge = pgeVec(nums, n);

        for(int i=0; i<n; i++){
            long long mini = (long long)nums[i]*(nse[i]-i)*(i-pse[i]);
            long long maxi = (long long)nums[i]*(nge[i]-i)*(i-pge[i]);
            sum += (maxi-mini);
        }
        
        return sum;
    }
};