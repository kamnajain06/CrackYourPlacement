class Solution {
public:
    long long fac(int n){
        if(n == 0 || n == 1) return 1LL;
        return n*fac(n-1);
    }
    long long cntPermutations(string str){
        unordered_map<char,int> mpp;
        int n = str.length();
        int non_zeroes = 0;
        for(auto it: str){
            mpp[it]++;
            if(it != '0') non_zeroes++;
        }
        long long ans = 0;
        if(non_zeroes){
            ans = (long long) non_zeroes*fac(n-1); //handle zeroes
        }
        for(auto it:mpp){
            ans /= fac(it.second);
        }
        return ans;
    }
    long long countGoodIntegers(int n, int k) {
        int half = (n+1)/2;
        int start = pow(10,half-1);
        int finish = pow(10,half) - 1;
        unordered_set<string> st; //duplicates avoid

        int flag = n % 2 == 0 ? 0 : 1;

        for(int i = start; i<= finish; i++){ //range
            string temp = to_string(i);
            
            if(flag){ //odd -> leave last digit
                string rev(temp.begin(), temp.end()-1);
                reverse(rev.begin(), rev.end());
                temp += rev;
            }else{ //even
                string rev(temp.begin(), temp.end());
                reverse(rev.begin(), rev.end());
                temp += rev;
            }
            long long num = stoll(temp);
            if(num % k == 0){
                sort(temp.begin(), temp.end()); //duplicates avoid
                st.insert(temp);
            }
        }
        long long ans = 0;
        for(auto str: st){
            long long cnt = cntPermutations(str);
            ans += cnt;
        }
        return ans;
    }
};