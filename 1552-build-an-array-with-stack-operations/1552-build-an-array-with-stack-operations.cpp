class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int len = target.size();
        vector<string> ans;
        int i = 0;
        int stream = 1;
        while(i < len){
            if(target[i] == stream){
                ans.push_back("Push");
                i++;
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            stream++;
        }
        return ans;
    }
};