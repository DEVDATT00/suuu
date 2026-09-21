class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (int i = 0; i < s.length(); i++) {
            st.push(string(1, s[i]));

            if (st.top() == "]") {
                st.pop();

                string tem = "";

                while (st.top() != "[") {
                    tem = st.top() + tem;
                    st.pop();
                }

                st.pop();

                string num = "";

                while (!st.empty() && isdigit(st.top()[0])) {
                    num = st.top() + num;
                    st.pop();
                }

                int n = stoi(num);

                string final = "";

                for (int j = 0; j < n; j++) {
                    final += tem;
                }

                st.push(final);
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};