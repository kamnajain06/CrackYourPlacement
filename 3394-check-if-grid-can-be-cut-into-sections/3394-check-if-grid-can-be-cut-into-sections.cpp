class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // check for vertical cuts
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int cnt = 1;
        for(auto it:rectangles){
            pq.push({it[0], it[2]}); //x-coords;
        }
        int c_s = 0;
        int c_e = 0;
        if(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            c_s = it.first;
            c_e = it.second;
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int n_s = it.first;
            int n_e = it.second;
            if(c_e > n_s){
                c_e = max(c_e, n_e);
            }else{
                cnt++;
                c_s = n_s;
                c_e = n_e;
            }
        }
        if(cnt >= 3) return true;
        cnt = 1;
        // check for horizontal cuts
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq1;
        for(auto it:rectangles){
            pq1.push({it[1], it[3]}); //y-coords;
        }
        int c_s1 = 0;
        int c_e1 = 0;
        if(!pq1.empty()){
            auto it = pq1.top();
            pq1.pop();
            c_s1 = it.first;
            c_e1 = it.second;
        }
        while(!pq1.empty()){
            auto it = pq1.top();
            pq1.pop();
            int n_s1 = it.first;
            int n_e1 = it.second;
            if(c_e1 > n_s1){
                c_e1 = max(c_e1, n_e1);
            }else{
                cnt++;
                c_s1 = n_s1;
                c_e1 = n_e1;
            }
        }

        if(cnt >= 3) return true;
        return false;
    }
};