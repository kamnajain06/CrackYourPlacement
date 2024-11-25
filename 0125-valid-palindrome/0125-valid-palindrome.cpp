class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i <= j){
            cout<<i<<j<<endl;
            if(!((s[i] >= 65 && s[i] <=90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >=48 && s[i] <=57))) i++;
            else if(!((s[j] >= 65 && s[j] <=90) || (s[j] >= 97 && s[j] <= 122) || (s[j] >=48 && s[j] <=57))) j--;
            else if(s[i] == s[j]){
                i++;
                j--;
            }else if(!(s[i] >=48 && s[i] <=57) && ((s[i] - 'A' == s[j] - 'a') || (s[i] - 'a' == s[j] - 'A')) ){
                // cout<<s[i]-'A'<<","<<s[j]-'a'<<endl;
                i++;
                j--;
            }else return false;
        }
        cout<<i<<j<<endl;
        return true;
    }
};