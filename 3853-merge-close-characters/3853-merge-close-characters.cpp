class Solution {
public:
    string mergeCharacters(string s, int k) {
        unordered_map<char, int> st;
        string n;
        for (int i = 0; i < s.length(); i++) {
            if (st.find(s[i]) == st.end()) {
                st[s[i]] = n.length();
                n.push_back(s[i]);
            } else {
                int last = st[s[i]];
                int current = n.length();

                if (current - last > k) {
                    st[s[i]] = current;
                    n.push_back(s[i]);
                }
            }
        }
        return n;
    }
};