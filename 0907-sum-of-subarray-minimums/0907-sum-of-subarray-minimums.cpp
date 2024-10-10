class Solution {
public:
    
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        int n = arr.size();
        if(n == 1) return arr[0]%1000000007;
        stack<int> st;
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        for(int i=0; i<arr.size(); i++){
            while(!st.empty()){
                if(arr[st.top()]<=arr[i]){
                    pse[i] = st.top();
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        stack<int> st1;
        for(int i=n-1; i>=0; i--){
            while(!st1.empty()){
                if(arr[st1.top()]<arr[i]){
                    nse[i] = st1.top();
                    break;
                }
                st1.pop();
            }
            st1.push(i);
        }
        for(int i=0; i<n; i++){
            sum = (sum + ((long long)arr[i]*(i-pse[i])*(nse[i]-i))%1000000007)%1000000007;
        }

        return sum%1000000007;
    }
};