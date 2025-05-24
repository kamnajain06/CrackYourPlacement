class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0;
        int trues = 0, falses = 0;
        int i = 0;
        for(int j=0; j<answerKey.length(); j++){
            if(answerKey[j] == 'T') trues++;
            else falses++;
            while(min(trues, falses) > k){
                if(answerKey[i] == 'T') trues--;
                else falses--;
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};