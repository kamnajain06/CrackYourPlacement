class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        stack<int> s;
        unordered_map<int,int> mpp;
        
        int n = nums2.size();
        
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                mpp[nums2[i]]=-1;
            }
            
            while(!s.empty() && s.top() < nums2[i]){
                s.pop();
            }
            if(!s.empty()) mpp[nums2[i]]=s.top();
            else mpp[nums2[i]]=-1;
            
            s.push(nums2[i]);
        }
        
        for(int i=0; i<nums1.size(); i++){
            v.push_back(mpp[nums1[i]]);
        }
        return v;
    }
};