class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i=0; i<chalk.size(); i++){
            sum+=chalk[i];
        }
        while(k>=sum) k-=sum;
        int i=0;
        while(i<chalk.size()){
                if(chalk[i]>k) return i;
                else{
                    k-=chalk[i];
                }
                i++;
            }
        return i;
    }
};