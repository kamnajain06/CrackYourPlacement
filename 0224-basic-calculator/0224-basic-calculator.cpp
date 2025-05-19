class Solution {
public:
    int calculate(string s) {
        stack<int> nums, ops;
        string temp = "";
        string st = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] != ' ') st += s[i];
        }
        for (int i = 0; i < st.length(); i++) {
            if (st[i] >= '0' && st[i] <= '9') {
                temp += st[i];
            } else if (st[i] == '(') {
                if (temp != "") {
                    nums.push(stoi(temp));
                    temp = "";
                }
                ops.push(st[i]);
            } else if (st[i] == ')') {
                if (temp != "") {
                    nums.push(stoi(temp));
                    temp = "";
                }
                while (ops.top() != '(') {
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    if (ops.top() == '+') {
                        nums.push(num1 + num2);
                    } else {
                        nums.push(num2 - num1);
                    }
                    ops.pop();
                }
                ops.pop();
            } else if (st[i] == '+' || st[i] == '-') {
                if (temp != "") {
                    nums.push(stoi(temp));
                    temp = "";
                }
                if (nums.empty() || ( i-1 >= 0 && (st[i-1] == '(' || st[i-1] == '+' || st[i-1] == '-')))
                    nums.push(0);
                if (ops.empty() || ops.top() == '(' || nums.size() < 2)
                    ops.push(st[i]);
                else {
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    if (ops.top() == '+') {
                        nums.push(num1 + num2);
                    } else if (ops.top() == '-') {
                        nums.push(num2 - num1);
                    }
                    ops.pop();
                    ops.push(st[i]);
                }
            }
        }
        if (temp != "") {
            nums.push(stoi(temp));
            temp = "";
        }
        while (!ops.empty() && nums.size() > 1) {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            if (ops.top() == '+') {
                nums.push(num1 + num2);
            } else if (ops.top() == '-') {
                nums.push(num2 - num1);
            }
            ops.pop();
        }

        return nums.top();
    }
};
