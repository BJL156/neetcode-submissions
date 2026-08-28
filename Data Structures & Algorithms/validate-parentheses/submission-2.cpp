class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }

            switch (s[i]) {
                case ')': {
                    if (!st.empty() && st.top() == '(') {
                        st.pop();
                    } else {
                        return false;
                    }

                    break;
                }
                case '}': {
                    if (!st.empty() && st.top() == '{') {
                        st.pop();
                    } else {
                        return false;
                    }

                    break;
                }
                case ']': {
                    if (!st.empty() && st.top() == '[') {
                        st.pop();
                    } else {
                        return false;
                    }

                    break;
                }
            }
        }

        return st.empty();
    }
};
