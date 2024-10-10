class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        st.push(asteroids[0]);
        for(int i=1; i<asteroids.size(); i++){
            if(!st.empty()){
                int val = st.top();
                if(val > 0){
                if(asteroids[i] > 0){
                    st.push(asteroids[i]);  
                }else{
                    while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
                        st.pop();
                    }
                    if(!st.empty() && st.top() == abs(asteroids[i])) st.pop();
                    else if(st.empty() || st.top()<0){
                        st.push(asteroids[i]);
                    }
                    
                }  
                }else{
                    st.push(asteroids[i]);    
                }
            }else{
                st.push(asteroids[i]);
            }
            
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};