class Solution {
public:
   int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        unordered_map<string,int> obsMap;
        
        // obsMap["0+0"]=1;
        for(auto it: obstacles){
            string s = to_string(it[0]) + "+" + to_string(it[1]);
            obsMap[s]++;
        }
       for(auto it:obsMap){
           cout<<it.first<<" "<<it.second<<endl;
       }
        int moves [4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
        int dir = 1;
        int maxi = 0;
        for(int i=0; i<commands.size(); i++){
            if(commands[i] == -1){
                dir = (dir+1)%4;
            }else if(commands[i] == -2){
                if(dir == 0) dir = 3;
                else dir--;
            }else{
                int k = commands[i];
                while(k > 0){
                    int newX = x + moves[dir][0];
                    int newY = y + moves[dir][1];
                    if(obsMap.find(to_string(newX) + "+" + to_string(newY)) != obsMap.end()) break;
                    else{
                        x = newX;
                        y = newY;
                    }
                    k--;
                    maxi = max(maxi, x*x + y*y);
                }
            }  

        }
        return maxi;

    }
};