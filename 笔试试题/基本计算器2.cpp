#include <bits/stdc++.h>
using namespace std;

class Solution {
    string str;
    int n;
    map<int, int>
        bracket; // bracket[i] = j 表示str中i下标为(，并且匹配位置j，j为)

    // 匹配括号
    void match() {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (str[i] == '(')
                st.push(i);
            else if (str[i] == ')') {
                bracket[st.top()] = i;
                st.pop();
            }
        }
    }

    int readNumber(int &l, int &r) {
        int res = 0;
        while (l <= r && str[l] >= '0' && str[l] <= '9') {
            res *= 10;
            res += str[l] - '0';
            l++;
        }
        return res;
    }

    void pop_and_calc(stack<int> &vals, char op) {
        int rhs = vals.top();
        vals.pop();
        int lhs = vals.top();
        vals.pop();
        // op
        switch (op) {
        case '+':
            vals.push(lhs + rhs);
            break;
        case '-':
            vals.push(lhs - rhs);
            break;
        case '*':
            vals.push(lhs * rhs);
            break;
        case '/':
            vals.push(lhs / rhs);
            break;
        default:
            cout << " never be there" << endl;
        }
    }

    bool isop(char op) {
        return op == '+' || op == '-' || op == '*' || op == '/';
    }

    // op1的优先级比op2的优先级不低
    bool priorityThan(char op1, char op2) {
        if (op1 == '*' || op1 == '/')
            return true;
        return op2 == '+' || op2 == '-';
    }

    int calc(int l, int r) {
        stack<int> vals;
        stack<int> ops;
        int sign = 1;
        bool read_digit = false;

        while (l <= r) {
            if (isdigit(str[l])) {
                int val = readNumber(l, r);
                vals.push(val * sign);
                sign = 1;
                read_digit = true;
            } else if (str[l] == '(') {
                int match_pos = bracket[l];
                int val = calc(l + 1, match_pos - 1);
                l = match_pos + 1;
                vals.push(val * sign);
                sign = 1;
                read_digit = true;
            } else {
                // 处理负数
                if (str[l] == '-' && !read_digit) {
                    sign = -1;
                    l++;
                    continue;
                }
                if (isop(str[l])) {
                    char op = str[l];
                    while (!ops.empty() && priorityThan(ops.top(), op)) {
                        int cur_op = ops.top();
                        ops.pop();
                        pop_and_calc(vals, cur_op);
                    }
                    ops.push(op);
                }
                l++;
                read_digit = false;
            }
        }
        while (!ops.empty()){
            char op = ops.top();
            ops.pop();
            pop_and_calc(vals, op);
        }
        return vals.top();
    }

  public:
    int calculate(string s) {
        str = s;
        n = s.length();
        match();
        return calc(0, n - 1);
    }
};

int main() {
    cout << Solution().calculate("2+2-1--2");
    return 0;
}