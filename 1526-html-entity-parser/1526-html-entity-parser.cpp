class Solution {
public:
    string entityParser(string text) {
        unordered_map<string,string> mpp;
        mpp["&quot;"] = "\"";
        mpp["&apos;"] = "'";
        mpp["&amp;"] = "&";
        mpp["&gt;"] = ">";
        mpp["&lt;"] = "<";
        mpp["&frasl;"] = "/";

        string ans = "";
        for(int i=0; i<text.size(); i++){
            if(text[i] == '&'){
                string temp = "";
                for(; i<text.size(); i++){
                    if(text[i] == '&'){
                        ans += temp;
                        temp = '&';
                        continue;
                    }
                    temp += text[i];
                    if(temp.size() >= 7 && temp[6] != ';') break; 
                    if(text[i] == ';'){
                        break;
                    }
                }
                if(mpp.find(temp) != mpp.end()) ans += mpp[temp];
                else ans += temp;
            }else ans += text[i];
        }
        return ans;
    }
};