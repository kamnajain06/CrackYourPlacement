class Solution {
public:
    int preced(char ch) {
        if (ch == '+' || ch == '-')
            return 1;
        return 2;
    }
    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;

        string st = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ')
                st += s[i];
        }
        string temp = "";
        for (int i = 0; i < st.length(); i++) {
            if (st[i] >= '0' && st[i] <= '9') {
                temp += st[i];
            } else {
                if (temp != "") {
                    nums.push(stoi(temp));
                    temp = "";
                }
                if (ops.empty()) {
                    ops.push(st[i]);
                } else {
                    while(!ops.empty() && preced(st[i]) <= preced(ops.top())) {
                        int num1 = nums.top();
                        nums.pop();
                        int num2 = nums.top();
                        nums.pop();
                        if (ops.top() == '+') {
                            nums.push(num1 + num2);
                        } else if (ops.top() == '-') {
                            nums.push(num2 - num1);
                        } else if (ops.top() == '*') {
                            nums.push(num2 * num1);
                        } else if (ops.top() == '/') {
                            nums.push(num2 / num1);
                        }
                        ops.pop();
                    }
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
            } else if (ops.top() == '*') {
                nums.push(num2 * num1);
            } else if (ops.top() == '/') {
                nums.push(num2 / num1);
            }
            ops.pop();
        }
        return nums.top();
    }
};