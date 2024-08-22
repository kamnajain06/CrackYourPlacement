class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        int cnt = 0;
        while(temp > 0){
            temp/=2;
            cnt++;
        }

        int power = pow(2,cnt)-1;
        int ans = num^power;

        return ans;
    }
};