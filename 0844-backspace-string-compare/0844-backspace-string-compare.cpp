class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string first = "";
        string second = "";
        for (char c : s) {
            if (c == '#') {
                if (!first.empty())
                    first.pop_back();
            } 
            else {
                first.push_back(c);
            }
        }
        for (char c : t) {
            if (c == '#') {
                if (!second.empty())
                    second.pop_back();
            } 
            else {
                second.push_back(c);
            }
        }
        return first == second;
    }
};