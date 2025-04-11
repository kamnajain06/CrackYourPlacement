class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low ; i <= high; i++){
            string temp = to_string(i);
            int len = temp.length();
            if(len % 2 == 1) continue;
            else{
                int total = 0;
                for(int it = 0; it < len ; it++) total += (temp[it] - '0');
                int j = (len/2) - 1;
                int sum = 0;
                while(j >= 0){
                    sum += (temp[j] - '0');
                    j--;
                }
                if(2 * sum == total){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};