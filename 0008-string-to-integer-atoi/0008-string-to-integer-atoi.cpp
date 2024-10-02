class Solution {
public: 
  
    int myAtoi(string s) {
        bool flag = 0;
        bool sign = 0;
        long long ans = 0;
        int digitIndex = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' ')continue;
            else if(s[i] == '+' && sign == 0){
                if(i< s.length()-1 && (s[i+1] < '0' || s[i+1] > '9')) break;
                sign = 1;
            }
            else if(s[i] == '-' && sign == 0){
                flag = 1;
                if(i< s.length()-1 && (s[i+1] < '0' || s[i+1] > '9')) break;
                sign = 1;
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                int value = s[i]-'0';
                if((ans)/10 > INT_MAX){
                    return flag == 1 ? INT_MIN : INT_MAX;
                }  
                ans = (ans*10) + value;
                if(i< s.length()-1 && (s[i+1] < '0' || s[i+1] > '9')) break;
            }else break;
        }
        if(flag == 1) ans = -ans;
        if(ans > INT_MAX) return INT_MAX;
        else if(ans < INT_MIN) return INT_MIN;
        return (int)ans;
    }
};