class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (auto& ch : s) {
            // open bracket -> push in stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            // closed bracket but stack is not empty
            // we have 2 cases:
            // 1. char at st.top is opening bracket for ch -> st.pop();
            // 2. char at st.top don't match with ch -> return false;
            else if (!st.empty()) {
                if (st.top() == '(' && ch == ')') {
                    st.pop();
                } else if (st.top() == '{' && ch == '}') {
                    st.pop();
                } else if (st.top() == '[' && ch == ']') {
                    st.pop();
                } else {
                    return false;
                }
            }
            // closed bracket but st is empty;
            else {
                return false;
            }
        }
        return st.size() == 0;
    }
};